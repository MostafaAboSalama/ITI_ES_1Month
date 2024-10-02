/*
 * LED_program.c
 *
 *  Created on: Jul 25, 2024
 *      Author: Elmag
 */


#include "LED_interface.h"
#include "LED_private.h"

void LED_voidInit(u8 L_u8led)
{
	switch(L_u8led)
	{
	case LED1 :DIO_u8SetPinDirection(LED1_PORT, LED1_PIN, OUTPUT); break ;
	case LED2 :DIO_u8SetPinDirection(LED2_PORT, LED2_PIN, OUTPUT); break ;
	case LED3 :DIO_u8SetPinDirection(LED3_PORT, LED3_PIN, OUTPUT); break ;
	case LED4 :DIO_u8SetPinDirection(LED4_PORT, LED4_PIN, OUTPUT); break ;
	case LED5 :DIO_u8SetPinDirection(LED5_PORT, LED5_PIN, OUTPUT); break ;
	}
}
void LED_voidSetLEDHigh(u8 L_u8led)
{
	switch(L_u8led){
	case LED1: DIO_u8SetPinValue(LED1_PORT, LED1_PIN, HIGH); break;
	case LED2: DIO_u8SetPinValue(LED2_PORT, LED2_PIN, HIGH); break;
	case LED3: DIO_u8SetPinValue(LED3_PORT, LED3_PIN, HIGH); break;
	case LED4: DIO_u8SetPinValue(LED4_PORT, LED4_PIN, HIGH); break;
	case LED5: DIO_u8SetPinValue(LED5_PORT, LED5_PIN, HIGH); break;
	}
}
void LED_voidSetLEDLow(u8 L_u8led)
{
	switch(L_u8led){
	case LED1: DIO_u8SetPinValue(LED1_PORT, LED1_PIN, LOW); break;
	case LED2: DIO_u8SetPinValue(LED2_PORT, LED2_PIN, LOW); break;
	case LED3: DIO_u8SetPinValue(LED3_PORT, LED3_PIN, LOW); break;
	case LED4: DIO_u8SetPinValue(LED4_PORT, LED4_PIN, LOW); break;
	case LED5: DIO_u8SetPinValue(LED5_PORT, LED5_PIN, LOW); break;
	}
}
