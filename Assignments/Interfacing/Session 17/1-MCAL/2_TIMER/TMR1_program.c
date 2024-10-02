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

void TMR1_voidSetCallBackPWM(void (*pf)(void))
{
	TMR1_CALL_BACK_PF = pf;
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	TMR1_CALL_BACK_PF();
}
