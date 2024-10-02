/*
 * fiveLeds.c
 *
 *  Created on: Jul 26, 2024
 *      Author: user
 */
#define F_CPU 8000000
#include <util/delay.h>
#include "../2-HAL/01_LED/LED_interface.h"
#include "../4-LIB/BIT_MATH.H"
#include "../4-LIB/STD_TYPES.H"
#include "../1-MCAL/3_GIE/GIE_interface.h"
#include "../1-MCAL/2_TIMER/TMR1_interface.h"


LED_Type led1 = {LED_PORTD, LED_PIN5, ACTIVE_HIGH};


void PWM_LED()
{
	LED_voidToggle(led1);
}


int main()
{
	LED_voidInit(led1);
	TMR1_voidInitFAST_PWM(30000);
	TMR1_voidSetDutyCycle(PWM_OCR1A, 20000);
	TMR1_voidSetCallBack(PWM_LED);
	GIE_voidEnable();
	while(1)
	{
	}
	return 0;
}

