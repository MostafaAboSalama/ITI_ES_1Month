/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	SERVO_program.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : SERVO
 *
*/

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/0_DIO/DIO_interface.h"
#include "../../1-MCAL/2_TIMER/TMR1_interface.h"

#include <util\delay.h>

#include "SERVO_interface.h"
#include "SERVO_config.h"
#include "SERVO_private.h"

void SERVO_voidInit(void)
{
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN4, DIO_PIN_OUTPUT);
	TMR1_voidInitFAST_PWM(SERVO_PERIOD_US);
}

void SERVO_voidSetAngle(u8 servo, s8 angle)
{
	u32 tmp = (angle + (s8) 90);
	tmp = (tmp * 1000)/180;

	switch(servo)
	{
	case SERVO1: TMR1_voidSetDutyCycle(SERVO1_CH, 1000 + ((u16) tmp)); break;
	case SERVO2: TMR1_voidSetDutyCycle(SERVO2_CH, 1000 + ((u16) tmp)); break;
	}

}
