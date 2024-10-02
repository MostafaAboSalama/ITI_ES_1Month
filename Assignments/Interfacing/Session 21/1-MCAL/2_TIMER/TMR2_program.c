/*
 * TMR2_program.c
 *
 *  Created on: Aug 3, 2024
 *      Author: user
 */


#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"
#include "TMR2_private.h"
#include "TMR2_interface.h"
#include "TMR2_config.h"

static void (*TMR2_CALL_BACK_PF)(void) = NULL;

void TMR2_voidInitCTC(void)
{
	/* CTC MODE */
	SET_BIT(TCCR2, WGM21);
	CLR_BIT(TCCR2, WGM20);
	
	/* SET REQUIRED CTC VAL */
	OCR2 = CTC_VAL;

	/*  Normal port operation, OC2 disconnected */
	CLR_BIT(TCCR2, COM20);
	CLR_BIT(TCCR2, COM21);
	
	/* ENABLE INT*/
	SET_BIT(TIMSK , OCIE2) ;

	/* CLOCK SELECT F/64 */
	SET_BIT(TCCR2, CS22);
	CLR_BIT(TCCR2, CS21);
	CLR_BIT(TCCR2, CS20);
}

void TMR2_voidSetCTC(u8 time)
{
	OCR2 = time;
}

void TMR2_voidSetCallBackCTC(void (*pf)(void))
{
	 TMR2_CALL_BACK_PF = pf;
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	TMR2_CALL_BACK_PF();
}
