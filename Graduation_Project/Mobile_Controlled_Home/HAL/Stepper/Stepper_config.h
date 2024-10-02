/*
 * Stepper_config.h
 *
 *  Created on: Jul 31, 2024
 *      Author: Mohammed Mansour
 */

#ifndef STEPPER_STEPPER_CONFIG_H_
#define STEPPER_STEPPER_CONFIG_H_

struct coil
{
	u8 port;
	u8 pin;
};


struct coil coils[] =
{
		{PORTC, PIN0},
		{PORTC, PIN1},
		{PORTC, PIN2},
		{PORTC, PIN3},
};


#define NUM_OF_COILS	(sizeof(coils)/sizeof(coils[0]))

#endif /* STEPPER_STEPPER_CONFIG_H_ */
