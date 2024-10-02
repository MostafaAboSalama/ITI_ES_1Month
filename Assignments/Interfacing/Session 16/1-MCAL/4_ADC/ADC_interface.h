/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mostafa AboSalama
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */ 

 

#ifndef   ADC_INTERFACE_H_
#define   ADC_INTERFACE_H_

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

/***Channel Choice***/
#define ADC_CH0		0
#define ADC_CH1		1
#define ADC_CH2		2
#define ADC_CH3		3
#define ADC_CH4		4
#define ADC_CH5		5
#define ADC_CH6		6
#define ADC_CH7		7
/*******************/
void ADC_voidInit(void);
void ADC_voidSelectChannel(u8 channel);
f32 ADC_voidStartConversion(void);
void ADC_voidInit(void);

#endif
