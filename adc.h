/*
 * adc.h
 *
 *  Created on: Apr 14, 2024
 *      Author: PC
 */
#include "std_types.h"

#ifndef ADC_H_
#define ADC_H_


void ADC0_Module_Init(void);
void ADC1_Module_Init(void);
void ADC0_SampleSequencer_Init(void);
void ADC1_SampleSequencer_Init(void);
uint16 ADC0_read(void);
uint16 ADC1_read(void);



#endif /* ADC_H_ */
