/*
 * ADC_private.h
 *
 *  Created on: Aug 4, 2024
 *      Author: Mohammed Mansour
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_


/* ADC registers */
#define ADMUX_Register 		*((volatile u8 *) 0x27)
#define ADCSRA_Register 	*((volatile u8 *) 0x26)
#define ADCDATA_Register	*((volatile u16*) 0x24)
#define SFIOR_Register 		*((volatile u8 *) 0x50)




/* ADMUX register bits */
#define ADMUX_MUX_MASK	0b00011111
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define ADLAR   5
#define REFS0   6
#define REFS1   7

/* ADCSRA register bits */
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

/* SFIOR register bits */
#define ADTS0   5
#define ADTS1   6
#define ADTS2   7


#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
