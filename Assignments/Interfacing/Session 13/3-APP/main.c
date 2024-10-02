/*
 * fiveLeds.c
 *
 *  Created on: Jul 26, 2024
 *      Author: user
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "../2-HAL/01_LED/LED_interface.h"
#include "../4-LIB/BIT_MATH.H"
#include "../4-LIB/STD_TYPES.H"
#include "../1-MCAL/1_EXTI/EXTI_interface.h"
#include "../1-MCAL/3_GIE/GIE_interface.h"

#define DELAY_TIME	1000


void Airbag();

int main()
{

	EXTI_Init();
	EXTI_Enable(EXTI0);
	EXTI_SetCallback(EXTI0, Airbag);
	GIE_voidEnable();
	while(1)
	{

	}
	return 0;
}

void Airbag()
{
	LED_Type Led1 = {LED_PORTA, LED_PIN0, ACTIVE_HIGH};	LED_voidInit(Led1);
	LED_voidON(Led1);
}
