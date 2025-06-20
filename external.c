/*
 * external.c
 *
 *  Created on: May 10, 2024
 *      Author: PC
 */

#include"external.h"
#include "tm4c123gh6pm_registers.h"

void vGPIO_Passenger_Green_LED_ON()
{
    GPIO_PORTA_DATA_REG &= 0xF9; /* Clear bit 1 ,2 in Data register to turn off the blue and red led */
    GPIO_PORTA_DATA_REG |= 0x01; /* Set bit 0 in Data register to turn on the green led */
}
void vGPIO_Passenger_Cyan_LED_ON()
{
    GPIO_PORTA_DATA_REG &= 0xFB; /* Clear bit 3 in Data register to turn off the green led */
    GPIO_PORTA_DATA_REG |= 0x03; /* set bit 0, 1 in Data register to turn on the leds */
}
void vGPIO_Passenger_BLUE_LED_ON()
{
    GPIO_PORTA_DATA_REG &= 0xFA; /* Clear bit 0 in Data register to turn off the green led */
    GPIO_PORTA_DATA_REG |= 0x02; /* Set bit 1 in Data register to turn on the blue led */
}
void vGPIO_Passenger_LEDs_OFF()
{
    GPIO_PORTA_DATA_REG &= 0xF8; /* Clear bit 0, 1,2 in Data register to turn off the leds */
}
void vGPIO_Passenger_RED_LED_ON()
{
    GPIO_PORTA_DATA_REG |= 0x04; /* Clear bit 0, 1,2 in Data register to turn off the leds */
}
void vGPIO_Passenger_LEDs_Init(void)
{
    /* Enable clock for PORTA and wait for clock to start */
    SYSCTL_RCGCGPIO_REG |= 0x01;
    while (!(SYSCTL_PRGPIO_REG & 0x01))
        ;
    GPIO_PORTA_AMSEL_REG &= 0xF8; /* Disable Analog on PA0, PA1 */
    GPIO_PORTA_PCTL_REG &= 0xFFFFF000; /* Clear PMCx bits for PA0, PA1 to use it as GPIO pin */
    GPIO_PORTA_DIR_REG |= 0x07; /* Configure PA0, PA1 as output pin */
    GPIO_PORTA_AFSEL_REG &= 0xF8; /* Disable alternative function on PA0, PA1 */
    GPIO_PORTA_DEN_REG |= 0x07; /* Enable Digital I/O on PA0, PA1 */
    GPIO_PORTA_DATA_REG &= 0xF8; /* Clear bit 0, 1 in Data register to turn off the leds */

}
