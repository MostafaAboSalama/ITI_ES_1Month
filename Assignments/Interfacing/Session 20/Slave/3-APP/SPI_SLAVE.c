/*
 * SERVO.c
 *
 *  Created on: Jul 26, 2024
 *      Author: user
 */
#define F_CPU 8000000
#include <util/delay.h>
#include "../2-HAL/01_LED/LED_interface.h"
#include "../2-HAL/08_SERVO/SERVO_interface.h"
#include "../4-LIB/BIT_MATH.h"
#include "../4-LIB/STD_TYPES.h"
#include "../1-MCAL/05_SPI/SPI_interface.h"
#include "../2-HAL/05_LCD/LCD_interface.h"

int main()
{
    u8 i = 0;
    DIO_enumSetPortDirection( DIO_PORTD , DIO_PORT_OUTPUT );
    SPI_SlaveInit();
    u8 data[10];
    while(1)
    {
    	for(i=0;i<10;i++)
    	{
    		data[i] = SPI_GetChar();
    		DIO_enumSetPortValue(DIO_PORTD, data[i]);
    		_delay_ms(1000);
    	 }

    }
    return 0;
}

