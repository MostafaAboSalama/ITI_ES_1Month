/*
 * PasswordLock.c
 *
 *  Created on: Jul 26, 2024
 *      Author: user
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "../2-HAL/01_LED/LED_interface.h"
#include "../2-HAL/05_LCD/LCD_interface.h"
#include "../2-HAL/06_KPD/KPD_interface.h"
#include "../1-MCAL/2_GIE/GIE_interface.h"
#include "../1-MCAL/3_TMR/TMR_interface.h"
#include "../2-HAL/07_LM35/LM35_interface.h"

#include "../4-LIB/BIT_MATH.h"
#include "../4-LIB/STD_TYPES.h"

void fun()
{
	LED_Type led1= {LED_PORTD, LED_PIN7, ACTIVE_HIGH};
	LED_voidON(led1);

}

int main(void)
{

	DIO_enumSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);
	LM35_voidInit();
    LCD_voidInit();

    //GIE_voidEnable();
    /*TMR2_voidInit();
    TMR2_voidSetCTC(250);
    TIMER_u8SetCallBack(fun, TIMER2_CTC_VECTOR_ID);*/
	while(1)
    {
		u32 res = LM35_voidGetTemp();
		LCD_voidSendString("Temperature: ");
		LCD_voidSendNumber(res);
		LCD_voidSendData('C');
		 _delay_ms(1000);
		 LCD_voidSendCommand(LCD_CLEAR);
    }
    return 0;
}
