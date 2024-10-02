/*
 * UART.c
 *
 *  Created on: Jul 26, 2024
 *      Author: user
 */
#define F_CPU 8000000
#include <util/delay.h>
#include "../2-HAL/01_LED/LED_interface.h"
#include "../4-LIB/BIT_MATH.H"
#include "../4-LIB/STD_TYPES.H"
#include "../1-MCAL/04_UART/UART_interface.h"
#include "../2-HAL/05_LCD/LCD_interface.h"


int main()
{
	UART_voidInit();
	LCD_voidInit();
	LED_Type G = {LED_PORTD, LED_PIN7, ACTIVE_HIGH};
	LED_Type W = {LED_PORTD, LED_PIN5, ACTIVE_HIGH};
	LED_voidInit(G);
	LED_voidInit(W);
	while(1)
	{
		u8 data = UART_u8RecieveByte();
		if(data == 'G')
		{
			LCD_voidSendCommand(LCD_CLEAR);
			LED_voidON(G); LED_voidOff(W);
			LCD_voidSendString(" GREEN LED ON ");
		}
		else if(data == 'W')
		{
			LCD_voidSendCommand(LCD_CLEAR);
			LED_voidON(W); LED_voidOff(G);
			LCD_voidSendString(" WHITE LED ON ");
		}
	}
	return 0;
}

