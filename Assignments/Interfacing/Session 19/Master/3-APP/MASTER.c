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





int main()
{
	UART_voidInit();
	while(1)
	{
		UART_voidSendByte('W');
		_delay_ms(1000);
		UART_voidSendByte('G');
		_delay_ms(1000);
	}
	return 0;
}

