/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TMR_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mostafa AboSalama
 *  Layer  : MCAL
 *  SWC    : TMR
 *
 */ 

 

#ifndef   TMR_INTERFACE_H_
#define   TMR_INTERFACE_H_

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"


#define TIMER0_OVF_VECTOR_ID		11
#define TIMER0_CTC_VECTOR_ID		10

#define TIMER1_OVF_VECTOR_ID		9
#define TIMER1_CTCB_VECTOR_ID		8
#define TIMER1_CTCA_VECTOR_ID		7
#define TIMER1_ICU_VECTOR_ID		6

#define TIMER2_OVF_VECTOR_ID		5
#define TIMER2_CTC_VECTOR_ID		4

void TMR2_voidInit();

void TMR2_voidSetPreloadValue(u8 preload);

void TMR2_voidSetCTC(u8 CTC);

void TIMER_u8SetCallBack(void (*Copy_pvCallBackFunc)(void) , u8 Copy_u8VectorID) ;

#endif
