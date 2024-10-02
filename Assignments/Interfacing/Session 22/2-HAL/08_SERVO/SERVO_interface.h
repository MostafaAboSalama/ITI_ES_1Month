/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	SERVO_interface.h	  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : SERVO
 *
*/

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#define SERVO1	0
#define SERVO2	1

#define SERVO1_CH	PWM_OCR1A
#define SERVO2_CH	PWM_OCR1B

void SERVO_voidInit(void);
void SERVO_voidSetAngle(u8 servo, s8 angle);


#endif /* SERVO_INTERFACE_H_ */
