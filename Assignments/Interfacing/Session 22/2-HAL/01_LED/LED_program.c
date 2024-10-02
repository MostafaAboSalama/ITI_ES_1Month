/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	LED_program.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : LED
 *
*/


#include "LED_interface.h"

#include <util/delay.h>


void LED_voidInit(LED_Type LED_Configuration)
{
	DIO_enumSetPinDirection(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_OUTPUT);
}

void LED_voidON(LED_Type LED_Configuration)
{
	if(LED_Configuration.Active_State == ACTIVE_HIGH)
	{
		DIO_enumSetPinValue(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_HIGH);
	}
	
	else
	{
		DIO_enumSetPinValue(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_LOW);
	}
}

void LED_voidOff ( LED_Type LED_Configuration )
{

	if( LED_Configuration.Active_State == ACTIVE_HIGH ){

		DIO_enumSetPinValue( LED_Configuration.port , LED_Configuration.pin , DIO_PIN_LOW  );

	}else if( LED_Configuration.Active_State == ACTIVE_LOW ){

		DIO_enumSetPinValue( LED_Configuration.port , LED_Configuration.pin , DIO_PIN_HIGH  );

	}

}


void LED_voidToggle(LED_Type LED_Configuration)
{
	DIO_enumTogglePinValue(LED_Configuration.port, LED_Configuration.pin);
}

void LED_voidBinaryCounter(u8 Copy_u8PORT)
{
	DIO_enumSetPortDirection( Copy_u8PORT , DIO_PORT_OUTPUT );
	u8 i = 0;
	for(i = 0; i < 10; i++)
	{
		DIO_enumSetPortValue(Copy_u8PORT, i);
		_delay_ms(1000);
	}

}
