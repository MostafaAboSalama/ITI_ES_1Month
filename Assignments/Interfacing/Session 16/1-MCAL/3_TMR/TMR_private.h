/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TMR_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mostafa AboSalama
 *  Layer  : MCAL
 *  SWC    : TMR
 *
 */ 

#ifndef _TMR_PRIVATE_H_
#define _TMR_PRIVATE_H_

#define NULL 0

#define FALLING_EDGE	0
#define RISING_EDGE		1

#define NORMAL_MODE		0
#define CTC_MODE		2
#define PWM_MODE		1
#define FAST_PWM_MODE	3


#define NO_CLK_SRC	0 
#define PSC_0		1 
#define PSC_8		2 
#define PSC_32		3 
#define PSC_64		4 
#define PSC_128		5 
#define PSC_256		6 
#define PSC_1024	7 
 

#define TCCR2 *(volatile u8*)(0x45)
#define TCNT2 *(volatile u8*)(0x44)
#define OCR2  *(volatile u8*)(0x43)
#define ASSR  *(volatile u8*)(0x42)
#define TIMSK *(volatile u8*)(0x59)
#define TIFR  *(volatile u8*)(0x58)
#define SFIOR *(volatile u8*)(0x50)

/* TCCR2 PINS*/
#define WGM21	3
#define WGM20	6
#define COM21	5
#define COM20	4
#define CS22	2
#define CS21	1
#define CS20	0

/* ASSR PINS*/
#define AS2		3

/* TIMSK PINS*/
#define OCIE2 	7
#define TOIE2 	6

/* TIFR PINS*/
#define OCF2  	7
#define TOV2 	6

/* SFIOR PINS*/
#define PSR2	1

#endif
