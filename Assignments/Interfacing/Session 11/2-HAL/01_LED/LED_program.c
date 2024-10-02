/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	LED_program.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : LED
 *
*/


#include "LED_interface.h"



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

void LED_voidToggle(LED_Type LED_Configuration)
{
	DIO_enumTogglePinValue(LED_Configuration.port, LED_Configuration.pin);
}
