/*
 * TMR2_private.h
 *
 *  Created on: Aug 3, 2024
 *      Author: user
 */

#ifndef TMR2_PRIVATE_H_
#define TMR2_PRIVATE_H_

#define SREG	*(volatile u8*)(0x5F)
#define TCCR2	*(volatile u8*)(0x45)
#define TCNT2	*(volatile u8*)(0x44)
#define OCR2	*(volatile u8*)(0x43)
#define TIMSK	*(volatile u8*)(0x59)
#define TIFR	*(volatile u8*)(0x58)
#define ASSR	*(volatile u8*)(0x42)

/* SREG BITS */
#define I_Bit	7


/* TCCR2 BITS */
#define FOC2	7
#define WGM20	6
#define COM21	5
#define COM20	4
#define WGM21	3
#define CS21	2
#define CS22	1
#define CS20	0

/* TIMSK */
#define OCIE2	7

/* ASSR */
#define AS2		3

#endif /* TMR2_PRIVATE_H_ */
