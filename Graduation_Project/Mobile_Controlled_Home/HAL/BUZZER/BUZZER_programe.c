/*
 * BUZZER_programe.c
 *
 *  Created on: Aug 17, 2024
 *      Author: Elmag
 */
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "BUZZER_interface.h"
#include "BUZZER_private.h"

void BUZZER_voidInit(u8 L_u8Buzzer)
{
	switch(L_u8Buzzer)
	{
	case BUZZER1 :DIO_u8SetPinDirection(BUZZER1_PORT, BUZZER1_PIN, OUTPUT); break ;
	case BUZZER2 :DIO_u8SetPinDirection(BUZZER2_PORT, BUZZER2_PIN, OUTPUT); break ;

	}
}
void BUZZER_voidSetBuzzerHigh(u8 L_u8Buzzer)
{
	switch(L_u8Buzzer){
	case BUZZER1: DIO_u8SetPinValue(BUZZER1_PORT, BUZZER1_PIN, HIGH); break;
	case BUZZER2: DIO_u8SetPinValue(BUZZER2_PORT, BUZZER2_PIN, HIGH); break;

	}
}
void BUZZER_voidSetBuzzerLow(u8 L_u8Buzzer)
{
	switch(L_u8Buzzer){
	case BUZZER1: DIO_u8SetPinValue(BUZZER1_PORT, BUZZER1_PIN, LOW); break;
	case BUZZER2: DIO_u8SetPinValue(BUZZER2_PORT, BUZZER2_PIN, LOW); break;

	}
}
