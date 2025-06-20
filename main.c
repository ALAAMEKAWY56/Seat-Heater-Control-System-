#include "tm4c123gh6pm_registers.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* MCAL includes. */
#include "uart0.h"
#include "GPTM.h"
#include "gpio.h"
#include "adc.h"

/**/
#include "external.h"
#define DRIVER_BUTTON 1
#define PASSENGER_BUTTON 2
#define IFNTENSITY_TASK 3
#define LED_TASK 4
#define LOW_LEVEL_DESIRED_TEMP 25
#define MEDIUM_LEVEL_DESIRED_TEMP 30
#define HIGH_LEVEL_DESIRED_TEMP 35
#define LOW_INTENSITY_DIFF 2
#define MEDIUM_INTENSITY_DIFF 5
#define HIGH_INTENSITY_DIFF 10
#define HEATERS_THRESHOLD 3
#define ADC_MAX_READING 4096UL
#define ADC_MAX_VOLT 3.3

/* New type to hold task information */
typedef struct
{
    uint8_t ucTask;
    uint8_t *pcTaskMessge;
} TaskInformation;

typedef struct
{
    uint8_t ucErrorReading;
    uint8_t ucTimeStamp;
} ErrorLog;

TaskInformation Drivertask = {
DRIVER_BUTTON,
                               "Driver Task" };

TaskInformation Passengertask = {
PASSENGER_BUTTON,
                                  "Passenger Task" };

ErrorLog DriverErrorLog;

ErrorLog PassengerErrorLog;
#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 369

void Delay_MS(unsigned long long n)
{
    volatile unsigned long long count = 0;
    while (count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n))
        ;
}

/* The HW setup function */
static void prvSetupHardware(void);

/* User defined types */
typedef enum heaterLevels
{
    LEVEL_OFF, LEVEL_LOW, LEVEL_MEDIUM, LEVEL_HIGH
} heaterLevels;
typedef enum heaterIntensities
{
    INTENSITY_OFF, INTENSITY_LOW, INTENSITY_MEDIUM, INTENSITY_HIGH
} heaterIntensities;

/* Global variables */
heaterLevels driverHeaterLevel = LEVEL_OFF;
heaterLevels passengerHeaterLevel = LEVEL_OFF;
heaterIntensities driverHeaterIntensity = INTENSITY_OFF;
heaterIntensities passengerHeaterIntensity = INTENSITY_OFF;
uint8_t DriverSeatTemp = 22;
uint8_t PassengersSeatTemp = 22;
uint8_t DesiredDriverSeatTemp;
uint8_t DesiredPassengerSeatTemp;
uint8_t DriverTempDifference;
uint8_t PassengerTempDifference;
uint8_t LastDriverHeatingLevel;
uint8_t LastPassengerHeatingLevel;
/* FreeRTOS tasks */
void vButtonsCheck(void *pvParameters);
void vButtonsActionHandler(void *pvParameters);
void vIntensityHandler(void *pvParameters);
void vLEDsHandler(void *pvParameters);
void vHeatersResumer(void *pvParameters);
void vDisplayData(void *pvParameters);
void vErrorsDetection(void *pvParameters);
void vTempReader(void *pvParameters);
/* FreeRTOS Binary Semaphores */
xSemaphoreHandle xDriverBinarySemaphore;
xSemaphoreHandle xPassengerBinarySemaphore;

/* Used to hold the handle of tasks */
TaskHandle_t xPassengerHeaterTaskHandle;
TaskHandle_t xDriverHeaterTaskHandle;
TaskHandle_t xPassengerADCTaskHandle;
TaskHandle_t xDriverADCTaskHandle;
TaskHandle_t xPassengerButtonTaskHandle;
TaskHandle_t xDriverButtonsTaskHandle;
TaskHandle_t xPassengerLEDsTaskHandle;
TaskHandle_t xDriverLEDsTaskHandle;
TaskHandle_t xPassengerHeaterResumeTaskHandle;
TaskHandle_t xDriverHeaterResumeTaskHandle;

int main()
{
    /* Setup the hardware for use with the Tiva C board. */
    prvSetupHardware();

    /* Create a binary semaphore */
    xDriverBinarySemaphore = xSemaphoreCreateBinary();
    xPassengerBinarySemaphore = xSemaphoreCreateBinary();

    /* Create Tasks here */
    xTaskCreate(vButtonsCheck, "Driver Buttons", 128, (void*) &Drivertask, 2,
                &xDriverButtonsTaskHandle);
    xTaskCreate(vButtonsCheck, "Passenger Button", 128, (void*) &Passengertask,
                2, &xPassengerButtonTaskHandle);
    xTaskCreate(vButtonsActionHandler, "Driver", 128, (void*) &Drivertask, 1,
    NULL);
    xTaskCreate(vButtonsActionHandler, "Passenger", 128, (void*) &Passengertask,
                1,
                NULL);
    xTaskCreate(vIntensityHandler, "Driver_Heater", 128, (void*) &Drivertask, 3,
                &xDriverHeaterTaskHandle);
    xTaskCreate(vIntensityHandler, "Passenger_Heater", 128,
                (void*) &Passengertask, 3, &xPassengerHeaterTaskHandle);
    xTaskCreate(vLEDsHandler, "Driver_LEDs", 128, (void*) &Drivertask, 3,
                &xDriverLEDsTaskHandle);
    xTaskCreate(vLEDsHandler, "Passenger_LEDs", 128, (void*) &Passengertask, 3,
                &xPassengerLEDsTaskHandle);
    xTaskCreate(vHeatersResumer, "Driver Heater Resume", 128,
                (void*) &Drivertask, 3, &xDriverHeaterResumeTaskHandle);
    xTaskCreate(vHeatersResumer, "Passenger Heater Resume", 128,
                (void*) &Passengertask, 3, &xPassengerHeaterResumeTaskHandle);
    xTaskCreate(vDisplayData, "Display Data", 128, NULL, 3,
    NULL);
    xTaskCreate(vErrorsDetection, "Driver Error Detector", 128,
                (void*) &Drivertask, 4,
                NULL);
    xTaskCreate(vErrorsDetection, "Passenger Error Detector", 128,
                (void*) &Passengertask, 4,
                NULL);
    xTaskCreate(vTempReader, "Driver Temp Reading", 128, (void*) &Drivertask, 3,
                &xDriverADCTaskHandle);
    xTaskCreate(vTempReader, "Passenger Temp Reading", 128,
                (void*) &Passengertask, 3, &xPassengerADCTaskHandle);
    /* Now all the tasks have been started - start the scheduler.

     NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
     The processor MUST be in supervisor mode when vTaskStartScheduler is
     called.  The demo applications included in the FreeRTOS.org download switch
     to supervisor mode prior to main being called.  If you are not using one of
     these demo application projects then ensure Supervisor mode is used here. */
    vTaskStartScheduler();

    /* Should never reach here!  If you do then there was not enough heap
     available for the idle task to be created. */
    for (;;)
        ;

}

static void prvSetupHardware(void)
{
    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
    UART0_Init();
    GPIO_BuiltinButtonsLedsInit();
    vGPIO_Passenger_LEDs_Init();
    ADC0_Module_Init();
    ADC0_SampleSequencer_Init();
    ADC1_Module_Init();
    ADC1_SampleSequencer_Init();
    UART0_SendString("Starting.....");
}

void vButtonsCheck(void *pvParameters)
{
    TaskInformation *pTaskInformation = (TaskInformation*) pvParameters;
    /* Establish the task's period. */
    const TickType_t xDelay = pdMS_TO_TICKS(150);
    uint8_t ucSteeringButtonState;
    uint8_t ucLastDriverButtonState;    // the previous state of button
    uint8_t ucCurrentDriverButtonState; // the current state of button
    uint8_t ucLastPassengerButtonState;    // the previous state of button
    uint8_t ucCurrentPassengerButtonState; // the current state of button
    for (;;)
    {

        if (pTaskInformation->ucTask == 1)
        {
            ucLastDriverButtonState = ucCurrentDriverButtonState;
            ucCurrentDriverButtonState = GPIO_SW1GetState();

            if (ucCurrentDriverButtonState == PRESSED
                    && ucLastDriverButtonState == !PRESSED)
            {
                /* Button is pressed */
                /* Perform the action to give the semaphore to the handler */
                UART0_SendString("Driver Button is pressed");
                UART0_SendString("\r\n");
                xSemaphoreGive(xDriverBinarySemaphore);
            }
        }
        else if (pTaskInformation->ucTask == 2)
        {
            vTaskDelay(xDelay);
            /* Delay to avoid reading the button state too frequently */
            /* Read the button state */
            ucLastPassengerButtonState = ucCurrentPassengerButtonState;
            ucCurrentPassengerButtonState = GPIO_SW2GetState();

            if (ucCurrentPassengerButtonState == PRESSED
                    && ucLastPassengerButtonState == !PRESSED)
            {
                /* Button is pressed */
                /* Perform the action to give the semaphore to the handler */
                UART0_SendString("Passenger Button is pressed");
                UART0_SendString("\r\n");
                xSemaphoreGive(xPassengerBinarySemaphore);
            }
        }
    }
}

void vButtonsActionHandler(void *pvParameters)
{
    TaskInformation *pTaskInformation = (TaskInformation*) pvParameters;
    for (;;)
    {
        if (pTaskInformation->ucTask == 1)
        {

            if (xSemaphoreTake(xDriverBinarySemaphore, portMAX_DELAY) == pdTRUE)
            {
                driverHeaterLevel = (driverHeaterLevel + 1) % 4;
                UART0_SendString("Driver Button press is handled");
                UART0_SendString("\r\n");
                UART0_SendString("Driver heater level: ");
                UART0_SendInteger(driverHeaterLevel);
                UART0_SendString("\r\n");
                LastDriverHeatingLevel = driverHeaterLevel;
            }
        }
        else if (pTaskInformation->ucTask == 2)
        {
            if (xSemaphoreTake(xPassengerBinarySemaphore,
                    portMAX_DELAY) == pdTRUE)
            {
                passengerHeaterLevel = (passengerHeaterLevel + 1) % 4;
                UART0_SendString("Passenger Button press is handled");
                UART0_SendString("\r\n");
                UART0_SendString("passenger heater level: ");
                UART0_SendInteger(passengerHeaterLevel);
                UART0_SendString("\r\n");
                LastPassengerHeatingLevel = passengerHeaterLevel;
            }
        }
    }
}

void vIntensityHandler(void *pvParameters)
{
    TaskInformation *pTaskInformation = (TaskInformation*) pvParameters;
    for (;;)
    {
        if (pTaskInformation->ucTask == 1)
        {

            switch (driverHeaterLevel)
            {
            case 0:
                driverHeaterIntensity = INTENSITY_OFF;
                break;
            case 1:
                DesiredDriverSeatTemp = LOW_LEVEL_DESIRED_TEMP;
                DriverTempDifference = DesiredDriverSeatTemp - DriverSeatTemp;
                if (DriverTempDifference >= HIGH_INTENSITY_DIFF
                        && DriverSeatTemp < DesiredDriverSeatTemp)
                {
                    driverHeaterIntensity = INTENSITY_HIGH; // High intensity
                }
                else if (DriverTempDifference >= MEDIUM_INTENSITY_DIFF
                        && DriverSeatTemp < DesiredDriverSeatTemp)
                {
                    driverHeaterIntensity = INTENSITY_MEDIUM; // Medium intensity
                }
                else if (DriverTempDifference >= LOW_INTENSITY_DIFF
                        && DriverSeatTemp < DesiredDriverSeatTemp)
                {
                    driverHeaterIntensity = INTENSITY_LOW; // Low intensity
                }
                else
                {
                    driverHeaterIntensity = INTENSITY_OFF; // Disable heater
                    vTaskSuspend(NULL);
                }
                break;

            case 2:
                DesiredDriverSeatTemp = MEDIUM_LEVEL_DESIRED_TEMP;
                DriverTempDifference = DesiredDriverSeatTemp - DriverSeatTemp;
                if (DriverTempDifference >= HIGH_INTENSITY_DIFF
                        && DriverSeatTemp < DesiredDriverSeatTemp)
                {
                    driverHeaterIntensity = INTENSITY_HIGH; // High intensity
                }
                else if (DriverTempDifference >= MEDIUM_INTENSITY_DIFF
                        && DriverSeatTemp < DesiredDriverSeatTemp)
                {
                    driverHeaterIntensity = INTENSITY_MEDIUM; // Medium intensity
                }
                else if (DriverTempDifference >= LOW_INTENSITY_DIFF
                        && DriverSeatTemp < DesiredDriverSeatTemp)
                {
                    driverHeaterIntensity = INTENSITY_LOW; // Low intensity
                }
                else
                {
                    driverHeaterIntensity = INTENSITY_OFF; // Disable heater
                    vTaskSuspend(NULL);
                }
                break;
            case 3:
                DesiredDriverSeatTemp = HIGH_LEVEL_DESIRED_TEMP;
                DriverTempDifference = DesiredDriverSeatTemp - DriverSeatTemp;
                if (DriverTempDifference >= HIGH_INTENSITY_DIFF
                        && DriverSeatTemp < DesiredDriverSeatTemp)
                {
                    driverHeaterIntensity = INTENSITY_HIGH; // High intensity
                }
                else if (DriverTempDifference >= MEDIUM_INTENSITY_DIFF
                        && DriverSeatTemp < DesiredDriverSeatTemp)
                {
                    driverHeaterIntensity = INTENSITY_MEDIUM; // Medium intensity
                }
                else if (DriverTempDifference >= LOW_INTENSITY_DIFF
                        && DriverSeatTemp < DesiredDriverSeatTemp)
                {
                    driverHeaterIntensity = INTENSITY_LOW; // Low intensity
                }
                else
                {
                    driverHeaterIntensity = INTENSITY_OFF; // Disable heater
                    vTaskSuspend(NULL);
                }
                break;
            }
            UART0_SendString("Driver Heater Intensity: ");
            UART0_SendInteger(driverHeaterIntensity);
            UART0_SendString("\r\n");
            UART0_SendString("Driver Seat Temp:  ");
            UART0_SendInteger(DriverSeatTemp);
            UART0_SendString("\r\n");
        }

        else if (pTaskInformation->ucTask == 2)
        {

            switch (passengerHeaterLevel)
            {
            case 0:
                passengerHeaterIntensity = INTENSITY_OFF;
                break;
            case 1:
                DesiredPassengerSeatTemp = LOW_LEVEL_DESIRED_TEMP;
                PassengerTempDifference = DesiredPassengerSeatTemp
                        - PassengersSeatTemp;
                if (PassengerTempDifference >= HIGH_INTENSITY_DIFF
                        && PassengersSeatTemp < DesiredPassengerSeatTemp)
                {
                    passengerHeaterIntensity = INTENSITY_HIGH; // High intensity
                }
                else if (PassengerTempDifference >= MEDIUM_INTENSITY_DIFF
                        && PassengersSeatTemp < DesiredPassengerSeatTemp)
                {
                    passengerHeaterIntensity = INTENSITY_MEDIUM; // Medium intensity

                }
                else if (PassengerTempDifference >= LOW_INTENSITY_DIFF
                        && PassengersSeatTemp < DesiredPassengerSeatTemp)
                {
                    passengerHeaterIntensity = INTENSITY_LOW; // Low intensity
                }
                else
                {
                    passengerHeaterIntensity = INTENSITY_OFF; // Disable heater
                    vTaskSuspend(NULL);
                }
                break;

            case 2:
                DesiredPassengerSeatTemp = MEDIUM_LEVEL_DESIRED_TEMP;
                PassengerTempDifference = DesiredPassengerSeatTemp
                        - PassengersSeatTemp;
                if (PassengerTempDifference >= HIGH_INTENSITY_DIFF
                        && PassengersSeatTemp < DesiredPassengerSeatTemp)
                {
                    passengerHeaterIntensity = INTENSITY_HIGH; // High intensity
                }
                else if (PassengerTempDifference >= MEDIUM_INTENSITY_DIFF
                        && PassengersSeatTemp < DesiredPassengerSeatTemp)
                {
                    passengerHeaterIntensity = INTENSITY_MEDIUM; // Medium intensity

                }
                else if (PassengerTempDifference >= LOW_INTENSITY_DIFF
                        && PassengersSeatTemp < DesiredPassengerSeatTemp)
                {
                    passengerHeaterIntensity = INTENSITY_LOW; // Low intensity
                }
                else
                {
                    passengerHeaterIntensity = INTENSITY_OFF; // Disable heater
                    vTaskSuspend(NULL);
                }
                break;
            case 3:
                DesiredPassengerSeatTemp = HIGH_LEVEL_DESIRED_TEMP;
                PassengerTempDifference = DesiredPassengerSeatTemp
                        - PassengersSeatTemp;
                if (PassengerTempDifference >= HIGH_INTENSITY_DIFF
                        && PassengersSeatTemp < DesiredPassengerSeatTemp)
                {
                    passengerHeaterIntensity = INTENSITY_HIGH; // High intensity
                }
                else if (PassengerTempDifference >= MEDIUM_INTENSITY_DIFF
                        && PassengersSeatTemp < DesiredPassengerSeatTemp)
                {
                    passengerHeaterIntensity = INTENSITY_MEDIUM; // Medium intensity

                }
                else if (PassengerTempDifference >= LOW_INTENSITY_DIFF
                        && PassengersSeatTemp < DesiredPassengerSeatTemp)
                {
                    passengerHeaterIntensity = INTENSITY_LOW; // Low intensity
                }
                else
                {
                    passengerHeaterIntensity = INTENSITY_OFF; // Disable heater
                    vTaskSuspend(NULL);
                }
                break;
            }
            UART0_SendString("Passenger Heater Intensity: ");
            UART0_SendInteger(passengerHeaterIntensity);
            UART0_SendString("\r\n");
            UART0_SendString("Passenger Seat Temp:  ");
            UART0_SendInteger(PassengersSeatTemp);
            UART0_SendString("\r\n");
        }
    }
}

void vLEDsHandler(void *pvParameters)
{
    TaskInformation *pTaskInformation = (TaskInformation*) pvParameters;
    for (;;)
    {
        if (pTaskInformation->ucTask == 1)
        {

            switch (driverHeaterIntensity)
            {
            case 0:
                GPIO_BlueLedOff();
                GPIO_GreenLedOff();
                break;
            case 1:
                GPIO_GreenLedOn();
                GPIO_BlueLedOff();
                break;

            case 2:
                GPIO_BlueLedOn();
                GPIO_GreenLedOff();
                break;
            case 3:
                GPIO_BlueLedOn();
                GPIO_GreenLedOn();
                break;
            }
        }

        else if (pTaskInformation->ucTask == 2)
        {
            switch (passengerHeaterIntensity)
            {
            case 0:
                vGPIO_Passenger_LEDs_OFF();
                break;
            case 1:
                vGPIO_Passenger_Green_LED_ON();
                break;

            case 2:
                vGPIO_Passenger_BLUE_LED_ON();
                break;
            case 3:
                vGPIO_Passenger_Cyan_LED_ON();
                break;
            }

        }
    }

}

void vHeatersResumer(void *pvParameters)
{
    TaskInformation *pTaskInformation = (TaskInformation*) pvParameters;
    for (;;)
    {
        if (pTaskInformation->ucTask == 1)
        {

            switch (driverHeaterLevel)
            {
            case 1:
                DesiredDriverSeatTemp = LOW_LEVEL_DESIRED_TEMP;
                DriverTempDifference = DesiredDriverSeatTemp - DriverSeatTemp;
                break;

            case 2:
                DesiredDriverSeatTemp = MEDIUM_LEVEL_DESIRED_TEMP;
                DriverTempDifference = DesiredDriverSeatTemp - DriverSeatTemp;
                break;
            case 3:
                DesiredDriverSeatTemp = HIGH_LEVEL_DESIRED_TEMP;
                DriverTempDifference = DesiredDriverSeatTemp - DriverSeatTemp;
                break;
            }
            if (DriverTempDifference >= HEATERS_THRESHOLD
                    && DriverSeatTemp < DesiredDriverSeatTemp)
            {
                vTaskResume(xDriverHeaterTaskHandle);
            }
        }

        else if (pTaskInformation->ucTask == 2)
        {

            switch (passengerHeaterLevel)
            {
            case 1:
                DesiredPassengerSeatTemp = LOW_LEVEL_DESIRED_TEMP;
                PassengerTempDifference = DesiredPassengerSeatTemp
                        - PassengersSeatTemp;
                break;

            case 2:
                DesiredPassengerSeatTemp = MEDIUM_LEVEL_DESIRED_TEMP;
                PassengerTempDifference = DesiredPassengerSeatTemp
                        - PassengersSeatTemp;
                break;
            case 3:
                DesiredPassengerSeatTemp = HIGH_LEVEL_DESIRED_TEMP;
                PassengerTempDifference = DesiredPassengerSeatTemp
                        - PassengersSeatTemp;
                break;
            }
            if (PassengerTempDifference >= HEATERS_THRESHOLD
                    && PassengersSeatTemp < DesiredPassengerSeatTemp)
            {
                vTaskResume(xPassengerHeaterTaskHandle);
            }
        }
    }
}
void vDisplayData(void *pvParameters)
{

    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS( 5000 ));
        UART0_SendString("Passenger Seat Temp:  ");
        UART0_SendInteger(PassengersSeatTemp);
        UART0_SendString("\r\n");
        UART0_SendString("passenger heater level: ");
        UART0_SendInteger(passengerHeaterLevel);
        UART0_SendString("\r\n");
        UART0_SendString("Passenger Heater Intensity: ");
        UART0_SendInteger(passengerHeaterIntensity);
        UART0_SendString("\r\n");
        UART0_SendString("Driver Seat Temp:  ");
        UART0_SendInteger(DriverSeatTemp);
        UART0_SendString("\r\n");
        UART0_SendString("Driver heater level: ");
        UART0_SendInteger(driverHeaterLevel);
        UART0_SendString("\r\n");
        UART0_SendString("Driver Heater Intensity: ");
        UART0_SendInteger(driverHeaterIntensity);
        UART0_SendString("\r\n");

    }
}

void vErrorsDetection(void *pvParameters)
{
    TaskInformation *pTaskInformation = (TaskInformation*) pvParameters;
    for (;;)
    {
        if (pTaskInformation->ucTask == 1)
        {

            if (DriverSeatTemp > 40)
            {
                TickType_t xTime = xTaskGetTickCount();
                vTaskSuspend(xDriverButtonsTaskHandle);
                vTaskSuspend(xDriverADCTaskHandle);
                vTaskSuspend(xDriverHeaterResumeTaskHandle);
                vTaskSuspend(xDriverHeaterTaskHandle);
                vTaskSuspend(xDriverLEDsTaskHandle);
                DriverErrorLog.ucErrorReading = DriverSeatTemp;
                DriverErrorLog.ucTimeStamp = xTime;
                GPIO_BlueLedOff();
                GPIO_GreenLedOff();
                GPIO_RedLedOn();
            }
        }

        else if (pTaskInformation->ucTask == 2)
        {
            if (PassengersSeatTemp > 40)
            {
                TickType_t xTime = xTaskGetTickCount();
                vTaskSuspend(xPassengerButtonTaskHandle);
                vTaskSuspend(xPassengerADCTaskHandle);
                vTaskSuspend(xPassengerHeaterResumeTaskHandle);
                vTaskSuspend(xPassengerHeaterTaskHandle);
                vTaskSuspend(xPassengerLEDsTaskHandle);
                PassengerErrorLog.ucErrorReading = PassengersSeatTemp;
                PassengerErrorLog.ucTimeStamp = xTime;
                vGPIO_Passenger_RED_LED_ON();
            }

        }
    }
}
void vTempReader(void *pvParameters)
{`
    TaskInformation *pTaskInformation = (TaskInformation*) pvParameters;
    for (;;)
    {
        if (pTaskInformation->ucTask == 1)
        {
            uint16 ADCValue = ADC0_read();
            DriverSeatTemp = (uint8) (((uint16) ((ADCValue * ADC_MAX_VOLT)
                    / ADC_MAX_READING)) * 45 / ADC_MAX_VOLT);
        }

        else if (pTaskInformation->ucTask == 2)
        {
            uint16 ADCValue = ADC1_read();
            PassengersSeatTemp = (uint8) (((uint16) ((ADCValue * ADC_MAX_VOLT)
                    / ADC_MAX_READING)) * 45 / ADC_MAX_VOLT);

        }
    }
}
