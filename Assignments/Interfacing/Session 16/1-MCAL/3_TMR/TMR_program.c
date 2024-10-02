/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TMR_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mostafa AboSalama
 *  Layer  : MCAL
 *  SWC    : TMR
 *
 */



#include "TMR_interface.h"
#include "TMR_private.h"
#include "TMR_config.h"

static void (*TIMERS_pvCallBackFunc[16])(void) = {NULL} ;  /* we have 8 interrupt sources in timer  */


void TMR2_voidInit(void)
{
    // Set Timer 2 to CTC mode
    TCCR2 |= (1 << WGM21);
    TCCR2 &= ~(1 << WGM20);

    // Set prescaler to 64
    TCCR2 |= (1 << CS22);
    TCCR2 &= ~(1 << CS21);
    TCCR2 &= ~(1 << CS20);

    // Enable Output Compare Match Interrupt
    TIMSK |= (1 << OCIE2);

    // Set initial compare value
   // TMR2_voidSetCTC(250); // For 1 Hz blink rate
}



void TMR2_voidSetPreloadValue(u8 preload)
{
	TCNT2 = preload;
}

void TMR2_voidSetCTC(u8 CTC)
{
	OCR2 = CTC;
}

void TIMER_u8SetCallBack(void (*Copy_pvCallBackFunc)(void) , u8 Copy_u8VectorID)
{
	if (Copy_pvCallBackFunc != NULL)
	{
		TIMERS_pvCallBackFunc[Copy_u8VectorID] = Copy_pvCallBackFunc ;
	}	
}

void __vector_4 (void)		__attribute__((signal)) ;
void __vector_4 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER2_CTC_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER2_CTC_VECTOR_ID]() ;
	}
}






//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>






