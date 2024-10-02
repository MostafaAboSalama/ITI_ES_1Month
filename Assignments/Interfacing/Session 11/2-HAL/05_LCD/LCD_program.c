/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	LCD_program.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : LCD
 *
*/

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"
#include "../../1-MCAL/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "util/delay.h"

void LCD_voidInit()
{
	DIO_enumSetPortDirection(LCD_CTRL_PORT, DIO_PORT_OUTPUT);
	DIO_enumSetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
	//DIO_enumSetPortValue(LCD_CTRL_PORT, DIO_PORT_HIGH);
	_delay_ms(30);

	LCD_voidSendCommand(LCD_HOME);
	_delay_ms(1);

	LCD_voidSendCommand(0X38);
	_delay_ms(1);

	LCD_voidSendCommand(LCD_DISPLAY_ON_CURSOR_OFF);
	_delay_ms(1);

	LCD_voidSendCommand(LCD_CLEAR);
	_delay_ms(2);

	LCD_voidSendCommand(LCD_ENTRY_MODE);
	_delay_ms(1);
}

void LCD_voidSendCommand(u8 command)
{
	DIO_enumSetPortValue(LCD_DATA_PORT, command);
	DIO_enumSetPinValue(LCD_CTRL_PORT, LCD_RS, DIO_PIN_LOW);
	DIO_enumSetPinValue(LCD_CTRL_PORT, LCD_RW, DIO_PIN_LOW);

	//Send Pulse
	LCD_voidSendPulse();
}

void LCD_voidSendData(u8 data)
{
	DIO_enumSetPinValue(LCD_CTRL_PORT, LCD_RS, DIO_PIN_HIGH);
	DIO_enumSetPinValue(LCD_CTRL_PORT, LCD_RW, DIO_PIN_LOW);
	DIO_enumSetPortValue(LCD_DATA_PORT, data);

	//Send Pulse
	LCD_voidSendPulse();
}

void LCD_voidSetCursorPosition(u8 row, u8 col)
{
	u8 pos;
	if(row == 1)
		pos = LCD_CURSOR + (col - 1);
	else
		pos = LCD_CURSOR + (col - 1) + 64;

	LCD_voidSendCommand(pos);
}

void LCD_voidSendString(u8* str)
{
	u8 ptr = 0;
	while(str[ptr] != '\0')
	{
		LCD_voidSendData(str[ptr]);
		ptr++;
	}
}
static void LCD_voidSendPulse()
{
	DIO_enumSetPinValue(LCD_CTRL_PORT, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(LCD_CTRL_PORT, LCD_EN, DIO_PIN_LOW);

}
