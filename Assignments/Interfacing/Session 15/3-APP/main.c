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
#include "../1-MCAL/2_TIMER/TMR2_interface.h"

LED_Type led1 = {LED_PORTA, LED_PIN0, ACTIVE_HIGH};
u32 SW_Cnt = 0;
u8 time = 125;
void TogLed()
{
	SW_Cnt++;
	if(SW_Cnt == 1000)
	{
		TMR2_voidSetCTC(time);
		LED_voidToggle(led1);
		SW_Cnt = 0;
	}
}
int main()
{
	LED_voidInit(led1);
	TMR2_voidInitCTC();
	TMR2_voidSetCallBackCTC(TogLed);
	GIE_voidEnable();
	while(1)
	{

	}
	return 0;
}

