/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	LED_interface.h	  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : LED
 *
*/

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/DIO_interface.h"

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


#define LED_PORTA	0
#define LED_PORTB	1
#define LED_PORTC 	2
#define LED_PORTD 	3


#define LED_PIN0	0
#define LED_PIN1	1
#define LED_PIN2	2
#define LED_PIN3	3
#define LED_PIN4	4
#define LED_PIN5	5
#define LED_PIN6	6
#define LED_PIN7	7


#define ACTIVE_HIGH	1
#define ACTIVE_LOW	0


typedef struct
{
	u8 port;
	u8 pin;
	u8 Active_State;
	
}LED_Type;




void LED_voidInit	(LED_Type LED_Configuration);
void LED_voidON		(LED_Type LED_Configuration);
void LED_voidToggle	(LED_Type LED_Configuration);

#endif /* LED_INTERFACE_H_ */
