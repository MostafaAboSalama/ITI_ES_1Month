#ifndef  ADC_CONFIG_H_
#define  ADC_CONFIG_H_

/***********ADJUST**********/
#define ADC_LEFT_ADJUST		1
#define ADC_RIGHT_ADJUST	0
/***************************/

/********PSA*********/
#define ADC_PSC_2 	0
#define ADC_PSC_4 	2
#define ADC_PSC_8 	3
#define ADC_PSC_16 	4
#define ADC_PSC_32 	5
#define ADC_PSC_64 	6
#define ADC_PSC_128 7
/*******************/

/**********VREF*********/
#define ADC_REF_AREF	0
#define ADC_REF_AVCC	1
#define ADC_REF_INT		3
/************************/

/**********YOUR CHOICE*************/
#define ADC_PSC		ADC_PSC_32
#define ADC_REF		ADC_REF_AVCC
#define ADC_ADJUST	ADC_RIGHT_ADJUST
/***********************************/
#endif
