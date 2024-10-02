/*
 * EXTI_prgram.c
 *
 *  Created on: Jul 30, 2024
 *      Author: a-m-m
 */

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

void (*EXTI0_CallBackPF)(void) = NULL;
void (*EXTI1_CallBackPF)(void) = NULL;
void (*EXTI2_CallBackPF)(void) = NULL;

void EXTI_voidEnable(u8 line, u8 mode)
{
	switch(line)
	{
	case EXTI_LINE1 :
		switch(mode)
		{
			case LOW_LEVEL      : CLR_BIT(MCUCR, ISC11); CLR_BIT(MCUCR, ISC10); break;
			case LOGICAL_CHANGE : CLR_BIT(MCUCR, ISC11); SET_BIT(MCUCR, ISC10); break;
			case FALLING_EDGE   : SET_BIT(MCUCR, ISC11); CLR_BIT(MCUCR, ISC10); break;
			case RISING_EDGE    : SET_BIT(MCUCR, ISC11); SET_BIT(MCUCR, ISC10); break;
		}
		SET_BIT(GICR, INTF1);
		break;

	case EXTI_LINE0 :
		switch(mode)
		{
			case LOW_LEVEL      : CLR_BIT(MCUCR, ISC01); CLR_BIT(MCUCR, ISC00); break;	
			case LOGICAL_CHANGE : CLR_BIT(MCUCR, ISC01); SET_BIT(MCUCR, ISC00); break;	
			case FALLING_EDGE   : SET_BIT(MCUCR, ISC01); CLR_BIT(MCUCR, ISC00); break;	
			case RISING_EDGE    : SET_BIT(MCUCR, ISC01); SET_BIT(MCUCR, ISC00); break;	
		}
		SET_BIT(GICR, INTF0);
		break;

	case EXTI_LINE2 : 
		switch(mode)
		{
			case EXTI2_FALLING_EDGE : CLR_BIT(MCUCSR, ISC2); break;
			case EXTI2_RISING_EDGE  : SET_BIT(MCUCSR, ISC2); break;
		}	
		SET_BIT(GICR, INTF2);
		break;
	}
}

void EXTI_voidSetCallBack(u8 line, void(*pf)(void))
{
	switch(line)
	{
	case EXTI_LINE0 : EXTI0_CallBackPF = pf; break;
	case EXTI_LINE1 : EXTI1_CallBackPF = pf; break;
	case EXTI_LINE2 : EXTI2_CallBackPF = pf; break;
	}
}

void EXTI_voidClearFlag(u8 line)
{
    switch(line)
    {
        case EXTI_LINE0: SET_BIT(GIFR, INTF0); break;
        case EXTI_LINE1: SET_BIT(GIFR, INTF1); break;
        case EXTI_LINE2: SET_BIT(GIFR, INTF2); break;
    }
}



void  __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	EXTI0_CallBackPF();
}

void  __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	EXTI1_CallBackPF();
}

void  __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	EXTI2_CallBackPF();
}
