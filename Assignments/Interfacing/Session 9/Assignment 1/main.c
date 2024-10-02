/*
 * main.c
 *
 *  Created on: Jul 26, 2024
 *      Author: user
 */

#define F_CPU 8000000
#include <avr\io.h>
#include <util\delay.h>
#include "macros.h"

#define DELAY_TIME	1000

int main()
{
	DDRA = 0xFF;
	PORTA = 0x00;
	while(1)
	{
		SET_BIT(PORTA, 0); CLR_BIT(PORTA, 1);
		_delay_ms(DELAY_TIME);
		SET_BIT(PORTA, 1); CLR_BIT(PORTA, 0);
		_delay_ms(DELAY_TIME);
	}
	return 0;
}
