/*
 * GIE_program.c
 *
 *  Created on: Aug 3, 2024
 *      Author: user
 */


#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"
#include "GIE_private.h"
#include "GIE_interface.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG, I_Bit);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG, I_Bit);
}
