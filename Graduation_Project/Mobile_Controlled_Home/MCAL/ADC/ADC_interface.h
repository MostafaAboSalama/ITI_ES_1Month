/*
 * ADC_interface.h
 *
 *  Created on: Aug 4, 2024
 *      Author: Mohammed Mansour
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#define ADC_CH0		0b00000
#define ADC_CH1		0b00001
#define ADC_CH2		0b00010
#define ADC_CH3		0b00011
#define ADC_CH4		0b00100
#define ADC_CH5		0b00101
#define ADC_CH6		0b00110
#define ADC_CH7		0b00111


void ADC_Init(void);
u16 ADC_StartConversion(u8 L_u8Channel);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
