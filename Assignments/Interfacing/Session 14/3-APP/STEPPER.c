/*
 * UART.c
 *
 *  Created on: Jul 26, 2024
 *      Author: user
 */
#define F_CPU 8000000
#include <util/delay.h>
#include "../2-HAL/01_LED/LED_interface.h"
#include "../2-HAL/07_STEPPER/STEPPER_interface.h"
#include "../4-LIB/BIT_MATH.H"
#include "../4-LIB/STD_TYPES.H"





int main()
{
	STEPPER_voidInit();
	while(1)
	{
		STEPPER_voidOn(STEPPER_FULL_STEP, STEPPER_CLOCK_WISE, 100, 270);
		_delay_ms(1000);
		STEPPER_voidOff();
	}
	return 0;
}

