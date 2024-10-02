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

void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

void (* ptr1)();
void (* ptr2)();
void (* ptr3)();



void EXTI_Init(void)
{
#if EXTI0_MODE == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR_Register, ISC00);
	CLR_BIT(MCUCR_Register, ISC01);
#elif EXTI0_MODE == EXTI_ON_CHANGE
	SET_BIT(MCUCR_Register, ISC00);
	CLR_BIT(MCUCR_Register, ISC01);
#elif EXTI0_MODE == EXTI_FALLING
	CLR_BIT(MCUCR_Register, ISC00);
	SET_BIT(MCUCR_Register, ISC01);
#elif EXTI0_MODE == EXTI_RISING
	SET_BIT(MCUCR_Register, ISC00);
	SET_BIT(MCUCR_Register, ISC01);
#endif


#if EXTI1_MODE == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR_Register, ISC10);
	CLR_BIT(MCUCR_Register, ISC11);
#elif EXTI1_MODE == EXTI_ON_CHANGE
	SET_BIT(MCUCR_Register, ISC10);
	CLR_BIT(MCUCR_Register, ISC11);
#elif EXTI1_MODE == EXTI_FALLING
	CLR_BIT(MCUCR_Register, ISC10);
	SET_BIT(MCUCR_Register, ISC11);
#elif EXTI1_MODE == EXTI_RISING
	SET_BIT(MCUCR_Register, ISC10);
	SET_BIT(MCUCR_Register, ISC11);
#endif

#if EXTI2_MODE == EXTI_FALLING
	CLR_BIT(MCUCSR_Register, ISC2);
#elif EXTI2_MODE == EXTI_RISING
	SET_BIT(MCUCSR_Register, ISC2);
#endif
}

void EXTI_Enable(u8 L_u8EXTI_Num)
{
	switch(L_u8EXTI_Num)
	{
	case EXTI0: SET_BIT(GICR_Register, INT0); break;
	case EXTI1: SET_BIT(GICR_Register, INT1); break;
	case EXTI2: SET_BIT(GICR_Register, INT2); break;
	}
}

void EXTI_Disable(u8 L_u8EXTI_Num)
{
	switch(L_u8EXTI_Num)
	{
	case EXTI0: CLR_BIT(GICR_Register, INT0); break;
	case EXTI1: CLR_BIT(GICR_Register, INT1); break;
	case EXTI2: CLR_BIT(GICR_Register, INT2); break;
	}
}

void EXTI_SetCallback(u8 L_u8EXTI_Num, void (* ptr)())
{
	if(ptr != 0x00)
	{
		switch(L_u8EXTI_Num)
		{
		case EXTI0: ptr1 = ptr;break;
		case EXTI1: ptr2 = ptr;break;
		case EXTI2: ptr3 = ptr;break;
		}
	}
}


void __vector_1(void)
{
	ptr1();
}

void __vector_2(void)
{
	ptr2();
}

void __vector_3(void)
{
	ptr3();
}
