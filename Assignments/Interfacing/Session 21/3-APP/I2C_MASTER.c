/*
 * SERVO.c
 *
 *  Created on: Jul 26, 2024
 *      Author: user
 */
#define F_CPU 8000000
#include <util/delay.h>
#include "../2-HAL/01_LED/LED_interface.h"
#include "../2-HAL/05_LCD/LCD_interface.h"
#include "../4-LIB/BIT_MATH.h"
#include "../4-LIB/STD_TYPES.h"
#include "../1-MCAL/06_I2C/I2C_interface.h"

u8 data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
LED_Type err = {LED_PORTA, LED_PIN0, ACTIVE_HIGH};
LED_Type Ok = {LED_PORTA, LED_PIN3, ACTIVE_HIGH};

int main()
{
	I2C_voidInitMaster(10000);
	I2C_u8SendStart();
	I2C_u8SendAddress(0x15 , I2C_WRITE_OPERATION);
	I2C_u8SendData(10);
	I2C_u8SendStop();
     return 0;
}
