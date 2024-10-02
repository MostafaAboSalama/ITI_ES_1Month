/*
 * EXTI_program.c
 *
 *  Created on: Jul 30, 2024
 *      Author: Hossam Bahaa
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

void (* callback_ptr1)(void);
void (* callback_ptr2)(void);
void (* callback_ptr3)(void);

/*
void EXTI_Init(void)
{
#if EXTI0_MODE == EXTI_LOWLEVEL
	CLEAR_BIT(MCUCR_Register, ISC00);
	CLEAR_BIT(MCUCR_Register, ISC01);
#elif EXTI0_MODE == EXTI_ONCHANGE
	SET_BIT(MCUCR_Register, ISC00);
	CLEAR_BIT(MCUCR_Register, ISC01);
#elif EXTI0_MODE == EXTI_FALLING
	CLEAR_BIT(MCUCR_Register, ISC00);
	SET_BIT(MCUCR_Register, ISC01);
#elif EXTI0_MODE == EXTI_RISING
	SET_BIT(MCUCR_Register, ISC00);
	SET_BIT(MCUCR_Register, ISC01);
#endif


#if EXTI1_MODE == EXTI_LOWLEVEL
	CLEAR_BIT(MCUCR_Register, ISC10);
	CLEAR_BIT(MCUCR_Register, ISC11);
#elif EXTI1_MODE == EXTI_ONCHANGE
	SET_BIT(MCUCR_Register, ISC10);
	CLEAR_BIT(MCUCR_Register, ISC11);
#elif EXTI1_MODE == EXTI_FALLING
	CLEAR_BIT(MCUCR_Register, ISC10);
	SET_BIT(MCUCR_Register, ISC11);
#elif EXTI1_MODE == EXTI_RISING
	SET_BIT(MCUCR_Register, ISC10);
	SET_BIT(MCUCR_Register, ISC11);
#endif

#if EXTI2_MODE == EXTI_FALLING
	CLEAR_BIT(MCUCSR_Register, ISC12);
#elif EXTI2_MODE == EXTI_RISING
	SET_BIT(MCUCSR_Register,ISC2);
#endif

}
*/

void EXTI_SetMode(u8 L_u8EXTINum, u8 L_u8Mode)
{
	switch(L_u8EXTINum)
	{
	case EXTI0:
		MCUCR_Register &= ~(0b11 << ISC00);
		MCUCR_Register |= L_u8Mode << ISC00;
		break;
	case EXTI1:
		MCUCR_Register &= ~(0b11 << ISC10);
		MCUCR_Register |= L_u8Mode << ISC10;
		break;
	case EXTI2:
		CLEAR_BIT(MCUCSR_Register, ISC2);
		MCUCSR_Register |= (1 & L_u8Mode) << ISC2;
		break;
	}
}


void EXTI_Enable(u8 L_u8EXTINum)
{
	switch(L_u8EXTINum)
	{
	case EXTI0:	SET_BIT(GICR_Register, INT0); break;
	case EXTI1:	SET_BIT(GICR_Register, INT1); break;
	case EXTI2:	SET_BIT(GICR_Register, INT2); break;
	}
}


void EXTI_Disable(u8 L_u8EXTINum)
{
	switch(L_u8EXTINum)
	{
	case EXTI0:	CLEAR_BIT(GICR_Register, INT0); break;
	case EXTI1:	CLEAR_BIT(GICR_Register, INT1); break;
	case EXTI2:	CLEAR_BIT(GICR_Register, INT2); break;
	}
}


void EXTI_SetCallback(u8 L_u8EXTINum, void (* ptr)())
{
	switch(L_u8EXTINum)
	{
	case EXTI0: callback_ptr1 = ptr; break;
	case EXTI1: callback_ptr2 = ptr; break;
	case EXTI2: callback_ptr3 = ptr; break;
	}
}

void __vector_1(void)
{
	callback_ptr1();
}

void __vector_2(void)
{
	callback_ptr2();
}

void __vector_3(void)
{
	callback_ptr3();
}
