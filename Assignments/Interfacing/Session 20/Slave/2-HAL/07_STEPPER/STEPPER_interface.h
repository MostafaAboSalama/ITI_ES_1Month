/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	STEPPER_interface.h	  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : STEPPER
 *
*/

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_


#define STEPPER_FULL_STEP    1
#define STEPPER_HALF_STEP    0

#define STEPPER_CLOCK_WISE       1
#define STEPPER_ANTI_CLOCK_WISE  0

void STEPPER_voidInit( void );

void STEPPER_voidOff( void );

void STEPPER_voidOn( u8 StepType , u8 Direction , u8 Speed , u16 Degree );

#endif /* STEPPER_INTERFACE_H_ */
