/*
 * TMR2_private.h
 *
 *  Created on: Aug 3, 2024
 *      Author: user
 */

#ifndef TMR1_PRIVATE_H_
#define TMR1_PRIVATE_H_

#define TMR1_PWM_TOG_ON_COMPARE_MATCH	0b01
#define TMR1_PWM_CLR_ON_COMPARE_MATCH	0b10
#define TMR1_PWM_SET_ON_COMPARE_MATCH	0b11

#define SREG		*(volatile u8* )(0x5F)
#define TCCR1A		*(volatile u8* )(0x4F)
#define TCCR1B		*(volatile u8* )(0x4E)
#define TCNT1H		*(volatile u8* )(0x4D)
#define TCNT1L		*(volatile u8* )(0x4C)
#define TCNT1_ALL	*(volatile u16*)(0x4C)
#define OCR1AH		*(volatile u8* )(0x4B)
#define OCR1AL		*(volatile u8* )(0x4A)
#define OCR1A_ALL	*(volatile u16*)(0x4A)
#define OCR1BH		*(volatile u8* )(0x49)
#define OCR1BL		*(volatile u8* )(0x48)
#define OCR1B_ALL	*(volatile u16*)(0x48)
#define ICR1AH		*(volatile u8* )(0x47)
#define ICR1AL		*(volatile u8* )(0x46)
#define ICR1A_ALL	*(volatile u16*)(0x46)
#define TCCR2		*(volatile u8* )(0x45)
#define TCNT2		*(volatile u8* )(0x44)
#define OCR2		*(volatile u8* )(0x43)
#define ASSR		*(volatile u8* )(0x42)

#define TIMSK	*(volatile u8*)(0x59)
#define TIFR	*(volatile u8*)(0x58)

/* SREG BITS */
#define I_Bit	7

/* TCCR1A BITS */       
#define COM1A1	7
#define COM1A0	6
#define COM1B1	5
#define COM1B0	4
#define FOC1A	3
#define FOC1B	2
#define WGM11	1
#define WGM10	0

/* TCCR1B BITS */               
#define ICNC1	7
#define ICES1	6
#define BLANK	5 	//RESERVED
#define WGM13	4
#define WGM12	3
#define CS12	2
#define CS11	1
#define CS10	0

/* TIMSK */
#define OCIE2	7

#endif /* TMR1_PRIVATE_H_ */
