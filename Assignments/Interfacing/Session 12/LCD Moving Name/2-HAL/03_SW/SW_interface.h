/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	SW_interface.h	  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : SW
 *
*/

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

#define SW_PRESSED     1
#define SW_NOT_PRESSED 0

#define SW_INT_PULL_UP	0
#define SW_EXT_PULL_UP	1
#define SW_EXT_PULL_DOWN	2
#define SW_FLOATING		3

typedef struct
{
	u8 PORT;
	u8 PIN;
	u8 PULL_STATE;
	
}SW_Type;

void SW_voidInit(SW_Type SW_Config);

u8 SW_u8GetPressed(SW_Type SW_Config);

#endif /* SW_INTERFACE_H_ */
