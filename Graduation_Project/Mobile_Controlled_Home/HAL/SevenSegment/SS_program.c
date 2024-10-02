/*
 * SS_program.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Hossam Bahaa
 */

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "SS_private.h"
#include "SS_config.h"
#include "SS_interface.h"


void SevenSegment_voidInit()
{
	DIO_u8SetPortDirection(SEVEN_SEGMENT1_PORT, 0xFF);
	DIO_u8SetPortValue(SEVEN_SEGMENT1_PORT, 0x00);
}

void SevenSegment_voidSetValue(u8 L_u8UnitNo, u8 L_u8Value)
{
	switch(L_u8UnitNo)
	{
	case SEVEN_SEGMENT_UNIT1: DIO_u8SetPortValue(SEVEN_SEGMENT1_PORT, digits[L_u8Value]);break;
	}
}

void SevenSegment_voidClear(u8 L_u8UnitNo)
{
	switch(L_u8UnitNo)
	{
	case SEVEN_SEGMENT_UNIT1: DIO_u8SetPortValue(SEVEN_SEGMENT1_PORT, 0x00);break;
	}
}
