/*
 * adc.c
 *
 *  Created on: Apr 14, 2024
 *      Author: PC
 */

#include "tm4c123gh6pm_registers.h"
#include "Common_Macros.h"
#include "std_types.h"
#include "adc.h"

#define ADC_PE0 0
#define ADC_PE1 1

void ADC0_Module_Init(void)
{
    SET_BIT(SYSCTL_RCGCADC_REG, 0);
    while (!(SYSCTL_PRADC_REG & 0x01))
        ;
    SYSCTL_RCGCGPIO_REG |= 0x10;
    while (!(SYSCTL_PRGPIO_REG & 0x10))
        ;

    SET_BIT(GPIO_PORTE_AFSEL_REG, ADC_PE0);
    CLEAR_BIT(GPIO_PORTE_DEN_REG, ADC_PE0);
    SET_BIT(GPIO_PORTE_AMSEL_REG, ADC_PE0);
    CLEAR_BIT(GPIO_PORTE_DIR_REG, ADC_PE0);
    CLEAR_BIT(GPIO_PORTE_PUR_REG, ADC_PE0);
    CLEAR_BIT(GPIO_PORTE_PDR_REG, ADC_PE0);

}
void ADC0_SampleSequencer_Init(void)
{
    CLEAR_BIT(ADC0_ACTSS_REG, 3);
    ADC0_EMUX_REG &= ~(0xF000);
    ADC0_TSSEL_REG = 0;
    ADC0_SSMUX3_REG = 0x03;
    ADC0_SSCTL3_REG = 0x06;
    SET_BIT(ADC0_ACTSS_REG, 3);
}

uint16 ADC0_read(void)
{
    uint16 adcValue = 0;
    SET_BIT(ADC0_PSSI_REG, 3);
    while (ADC0_ACTSS_REG & 0x1000)
        ;

    while (GET_BIT(ADC0_RIS_REG,3) == 0)
        ;
    adcValue = ADC0_SSFIFO3_REG;
    ADC0_ISC_REG |= 1 << 4;
    return adcValue;
}

void ADC1_Module_Init(void)
{
    SET_BIT(SYSCTL_RCGCADC_REG, 1);
    while (!(SYSCTL_PRADC_REG & 0x02))
        ;
    SYSCTL_RCGCGPIO_REG |= 0x10;
    while (!(SYSCTL_PRGPIO_REG & 0x10))
        ;

    SET_BIT(GPIO_PORTE_AFSEL_REG, ADC_PE1);
    CLEAR_BIT(GPIO_PORTE_DEN_REG, ADC_PE1);
    SET_BIT(GPIO_PORTE_AMSEL_REG, ADC_PE1);
    CLEAR_BIT(GPIO_PORTE_DIR_REG, ADC_PE1);
    CLEAR_BIT(GPIO_PORTE_PUR_REG, ADC_PE1);
    CLEAR_BIT(GPIO_PORTE_PDR_REG, ADC_PE1);
}
void ADC1_SampleSequencer_Init(void)
{
    CLEAR_BIT(ADC1_ACTSS_REG, 3);
    ADC1_EMUX_REG &= ~(0xF000);
    ADC1_TSSEL_REG = 0;
    ADC1_SSMUX3_REG = 0x03;
    ADC1_SSCTL3_REG = 0x06;
    SET_BIT(ADC1_ACTSS_REG, 3);
}
uint16 ADC1_read(void)
{
    uint16 adcValue = 0;
    SET_BIT(ADC1_PSSI_REG, 3);
    while (ADC1_ACTSS_REG & 0x1000)
        ;

    while (GET_BIT(ADC1_RIS_REG,3) == 0)
        ;
    adcValue = ADC1_SSFIFO3_REG;
    ADC1_ISC_REG |= 1 << 4;
    return adcValue;
}
