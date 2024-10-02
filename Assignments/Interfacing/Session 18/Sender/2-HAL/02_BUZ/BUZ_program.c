/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	BUZ_program.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : BUZ
 *
*/

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/0_DIO/DIO_interface.h"


#include "BUZ_interface.h"

void BUZ_voidInit(BUZ_Type BUZ_Configuration)
{
	DIO_enumSetPinDirection(BUZ_Configuration.Port, BUZ_Configuration.Pin, DIO_PIN_OUTPUT);
}

void BUZ_voidON(BUZ_Type BUZ_Configuration)
{
	if(BUZ_Configuration.Active_State == ACTIVE_HIGH)
	{
		DIO_enumSetPinValue(BUZ_Configuration.Port, BUZ_Configuration.Pin, DIO_PIN_HIGH);
	}
	
	else
	{
		DIO_enumSetPinValue(BUZ_Configuration.Port, BUZ_Configuration.Pin, DIO_PIN_LOW);
	}
}

void BUZ_voidOff ( BUZ_Type BUZ_Configuration )
{

	if( BUZ_Configuration.Active_State == ACTIVE_HIGH ){

		DIO_enumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_LOW  );

	}else if( BUZ_Configuration.Active_State == ACTIVE_LOW ){

		DIO_enumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_HIGH  );

	}

}


void BUZ_voidToggle(BUZ_Type BUZ_Configuration)
{
	DIO_enumTogglePinValue(BUZ_Configuration.Port, BUZ_Configuration.Pin);
}
