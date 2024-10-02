/*
 * TMR2_program.c
 *
 *  Created on: Aug 3, 2024
 *      Author: user
 */


#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"
#include "TMR1_private.h"
#include "TMR1_interface.h"
#include "TMR1_config.h"

static void (*TMR1_CALL_BACK_PF)(void) = NULL;

void TMR1_voidInitFAST_PWM(u16 period_us)
{
	/*  Normal port operation, OC1A/OC1B disconnected */
	CLR_BIT(TCCR1A, COM1A1); CLR_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1B1); CLR_BIT(TCCR1A, COM1B1);
	
	/*MODE 14 FAST PWM*/
	SET_BIT(TCCR1B, WGM13); SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1A, WGM11); CLR_BIT(TCCR1A, WGM10);
	
	/* SELECT OC1A MODE */
	TCCR1A &= ~(0b11 << COM1A0);
	TCCR1A |= TMR1_PWM_OC1A_MODE << COM1A0;

	/* SELECT OC1B MODE */
	TCCR1A &= ~(0b11 << COM1B0);
	TCCR1A |= TMR1_PWM_OC1B_MODE << COM1B0;

	ICR1A_ALL = period_us;
	
	/* CLOCK SELECT F/8 */ 
	CLR_BIT(TCCR1B, CS12); SET_BIT(TCCR1B, CS11); CLR_BIT(TCCR1B, CS10);
}

void TMR1_voidSetDutyCycle(u8 channel, u16 DC_us)
{
	switch(channel)
	{
	case PWM_OCR1A:	OCR1A_ALL = DC_us; break;
	case PWM_OCR1B:	OCR1B_ALL = DC_us; break;
	}
}


/* ICU */
void TMR1_voidICU_Init(void)
{
	/* OVF MODE ENABLE */
	CLR_BIT(TCCR1A, WGM10); CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12); CLR_BIT(TCCR1A, WGM13);
	
	/* ICU INT ENABLE */
	SET_BIT(TIMSK, 5);
	
	/* CLOCK SELECT F/8 */ 
	CLR_BIT(TCCR1B, CS12); SET_BIT(TCCR1B, CS11); CLR_BIT(TCCR1B, CS10);
}

u16 TMR1_u16ICU_Read(void)
{
	return ICR1A_ALL;
}

void TMR1_voidICU_SetEdge(u8 edge)
{
	switch(edge)
	{
	case ICU_FALLING_EDGE : CLR_BIT(TCCR1B, ICES1); break;
	case ICU_RISING_EDGE  : SET_BIT(TCCR1B, ICES1); break;
	}
}

void TMR1_voidSetCallBack(void (*pf)(void))
{
	TMR1_CALL_BACK_PF = pf;
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	TMR1_CALL_BACK_PF();
}
