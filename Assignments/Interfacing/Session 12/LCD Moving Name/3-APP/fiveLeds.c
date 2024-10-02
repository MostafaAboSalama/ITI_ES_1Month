/*
 * fiveLeds.c
 *
 *  Created on: Jul 26, 2024
 *      Author: user
 */
#define F_CPU 8000000
#include <avr\io.h>
#include <util\delay.h>
#include "../2-HAL/01_LED/LED_interface.h"
#include "../2-HAL/05_LCD/LCD_interface.h"

#include "../4-LIB/BIT_MATH.H"
#include "../4-LIB/STD_TYPES.H"



#define DELAY_TIME	1000

int main()
{
	LCD_voidInit();

	while(1)
	{
		for(u8 i =1; i<=16; i++)
		{
			LCD_voidSetCursorPosition(1, i);
			LCD_voidSendString("ABOSALAMA");
			_delay_ms(1000);
			LCD_voidSetCursorPosition(1, i);
			LCD_voidSendString("                ");
		}

	}
	return 0;
}

