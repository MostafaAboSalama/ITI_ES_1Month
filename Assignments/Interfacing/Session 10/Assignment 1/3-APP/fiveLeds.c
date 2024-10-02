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
#include "../4-LIB/BIT_MATH.H"
#include "../4-LIB/STD_TYPES.H"



#define DELAY_TIME	1000

int main()
{
	LED_Type Led1 = {LED_PORTA, LED_PIN0, ACTIVE_HIGH};	LED_voidInit(Led1);
	LED_Type Led2 = {LED_PORTA, LED_PIN1, ACTIVE_HIGH};	LED_voidInit(Led2);
	LED_Type Led3 = {LED_PORTA, LED_PIN2, ACTIVE_HIGH};	LED_voidInit(Led3);
	LED_Type Led4 = {LED_PORTA, LED_PIN5, ACTIVE_HIGH};	LED_voidInit(Led4);
	LED_Type Led5 = {LED_PORTA, LED_PIN6, ACTIVE_HIGH};	LED_voidInit(Led5);

	while(1)
	{
		LED_voidToggle(Led1);
		_delay_ms(DELAY_TIME);
		LED_voidToggle(Led2);
		_delay_ms(DELAY_TIME);
		LED_voidToggle(Led3);
		_delay_ms(DELAY_TIME);
		LED_voidToggle(Led4);
		_delay_ms(DELAY_TIME);
		LED_voidToggle(Led5);
		_delay_ms(DELAY_TIME);
	}
	return 0;
}

