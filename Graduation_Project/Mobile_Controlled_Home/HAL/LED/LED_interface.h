/*
 * LED_interface.h
 *
 *  Created on: Jul 25, 2024
 *      Author: Elmag
 */

#ifndef LED_LED_INTERFACE_H_
#define LED_LED_INTERFACE_H_

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"

#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3
#define LED5 4



void LED_voidInit(u8 L_u8led);
void LED_voidSetLEDHigh(u8 L_u8led);
void LED_voidSetLEDLow(u8 L_u8led);

#endif /* LED_LED_INTERFACE_H_ */
