/*
 * Stepper_program.c
 *
 *  Created on: Jul 31, 2024
 *      Author: Hossam Bahaa
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "Stepper_private.h"
#include "Stepper_config.h"
#include "Stepper_interface.h"

static u8 current_pattern = 0;

void Stepper_Init(void)
{
	for(int i=0; i<NUM_OF_COILS; i++)
	{
		DIO_u8SetPinDirection(coils[i].port, coils[i].pin, OUTPUT);
	}

}

void Stepper_StepCW(void)
{
	current_pattern++;
	for(u8 i = 0; i<NUM_OF_COILS; i++)
	{
		DIO_u8SetPinValue(coils[i].port, coils[i].pin, GET_BIT(sequence_arr[current_pattern], i));
	}
	if(current_pattern > 7) current_pattern = 0;
}

void Stepper_StepCCW(void)
{
	current_pattern--;
	for(u8 i = 0; i<NUM_OF_COILS; i++)
	{
		DIO_u8SetPinValue(coils[i].port, coils[i].pin, GET_BIT(sequence_arr[current_pattern], i));
	}
	if(current_pattern > 7) current_pattern = 7;
}
