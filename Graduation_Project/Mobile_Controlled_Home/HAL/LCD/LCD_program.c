/*
 * LCD_program.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Elmag
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include <util/delay.h>

void HLCD_voidinit()
{
	DIO_u8SetPortDirection(LCD_DATA_PORT ,OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT ,LCD_RS_PIN ,OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT ,LCD_RW_PIN ,OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT ,LCD_E_PIN ,OUTPUT);

	_delay_ms(30);
	HLCD_voidCommand(LCD_Function_set1);
	//_delay_ms(1);
	HLCD_voidCommand(LCD_Display_Mode2);
	_delay_ms(1);
	HLCD_voidCommand(LCD_Clear_Screen);
	_delay_ms(2);
	HLCD_voidCommand(LCD_Entry_Mode1);

    HLCD_voidCommand(LCD_DISP_ON_CURSOR);
    HLCD_voidCommand(LCD_DISP_ON);
}

void HLCD_voidCommand(u8 command)
{
	DIO_u8SetPinValue(LCD_CONTROL_PORT , LCD_RS_PIN ,LOW );
	DIO_u8SetPinValue(LCD_CONTROL_PORT , LCD_RW_PIN ,LOW );
	DIO_u8SetPortValue(LCD_DATA_PORT ,command );

	HLCD_voidSendPulse();
}
void HLCD_voidSetDDRAM_Address(u8 address)
{
	SET_BIT(address,7);
	HLCD_voidCommand(address);
}

void static HLCD_voidSendPulse(void)
{
	DIO_u8SetPinValue(LCD_CONTROL_PORT ,LCD_E_PIN ,HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_CONTROL_PORT ,LCD_E_PIN ,LOW);
	_delay_ms(1);
}

void HLCD_SendData(u8 data)
{
	DIO_u8SetPinValue(LCD_CONTROL_PORT , LCD_RS_PIN ,HIGH);
	DIO_u8SetPinValue(LCD_CONTROL_PORT , LCD_RW_PIN ,LOW);

	DIO_u8SetPortValue(LCD_DATA_PORT ,data);

	HLCD_voidSendPulse();
}

void HLCD_PrintString(u8 *string)
{
	int count = 0;
	while (*string > 0) {
		count++;
		HLCD_SendData(*string++);
		if (count == 16) {
			HLCD_voidSetDDRAM_Address(0x40);
		} else if (count == 32) {
			HLCD_voidCommand(LCD_Clear_Screen);
			HLCD_voidSetDDRAM_Address(0);
			count = 0;
		}
	}
}

void LCD_display_number(int number)
{
	char str[5];

	itoa(number , str ,10);
	HLCD_PrintString(str);
}

void HLCD_GOTO_XY(u8 line, u8 position) {
	if (line == 1) {
		if (position < 16 && position >= 0) {
			HLCD_voidSetDDRAM_Address(LCD_FIRST_ROW + position-1);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			HLCD_voidSetDDRAM_Address(LCD_SECOND_ROW + position -1);
		}
	}
}
