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
#include "../2-HAL/04_SSD/SSD_interface.h"
#include "../2-HAL/03_SW/SW_interface.h"

#include "../4-LIB/BIT_MATH.H"
#include "../4-LIB/STD_TYPES.H"



#define DELAY_TIME	1000

int main()
{
	SSD_Type SSD1 = {SSD_COMM_AND, SSD_PORTC, SSD_PORTC, SSD_PIN7};
	SSD_voidInit(SSD1);
	SSD_voidEnable(SSD1);
	SW_Type SW1 = {SW_PORTA, SW_PIN7, SW_EXT_PULL_DOWN};
	SW_voidInit(SW1);
	u8 cnt = 0;
	SSD_voidSendNumber(SSD1, cnt);
	while(1)
	{

		if(SW_u8GetPressed(SW1) == 1)
		{
			_delay_ms(10);
			cnt++;
			if(cnt == 10)
				cnt = 0;
			SSD_voidSendNumber(SSD1, cnt);
			while(SW_u8GetPressed(SW1) == 1);
		}

	}
	return 0;
}

