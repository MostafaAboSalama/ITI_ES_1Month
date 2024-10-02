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
#include "../../1-MCAL/0_DIO/DIO_interface.h"
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

void LCD_voidSetPosition ( u8 Copy_u8Row , u8 Copy_u8Col ){

	u8 LOC_u8data ;

	/* In These cases will set at (0,0) ==> if the user enter invalid location */
	if(Copy_u8Row>2||Copy_u8Row<1||Copy_u8Col>16||Copy_u8Col<1)  //check
	{
		LOC_u8data = LCD_CURSOR ;   // first location
	}

	else if( Copy_u8Row == 1 ){

		LOC_u8data = ( ( LCD_CURSOR ) + ( Copy_u8Col - 1 ) );              //Row1 -> 0x80+col-1

	}

	else if( Copy_u8Row == 2 ){

		LOC_u8data = ( ( LCD_CURSOR ) + (64) + ( Copy_u8Col - 1 ) );       //Row2 -> 0xc0+col-1

	}
	LCD_voidSendCommand ( LOC_u8data );
	_delay_ms(1);

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

void LCD_voidSendNumber(u64 number )
{

	u64 LOC_u64Reversed = 1 ;

	if( number == 0 ){ LCD_voidSendData('0'); }

	else{

		while( number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( number % 10 );
			number /= 10 ;

		}
		while( LOC_u64Reversed != 1 ){

			LCD_voidSendData( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}

}

static void LCD_voidSendPulse()
{
	DIO_enumSetPinValue(LCD_CTRL_PORT, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(LCD_CTRL_PORT, LCD_EN, DIO_PIN_LOW);

}
