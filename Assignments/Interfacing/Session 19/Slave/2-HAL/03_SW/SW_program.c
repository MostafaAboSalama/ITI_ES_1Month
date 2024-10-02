/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	SW_program.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : BUZ
 *
*/

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/0_DIO/DIO_interface.h"


#include "SW_interface.h"
#include "SW_config.h"
#include "SW_private.h"

void SW_voidInit(SW_Type SW_Config)
{
	DIO_enumSetPinDirection(SW_Config.PORT, SW_Config.PIN, DIO_PIN_INPUT);
	if(SW_Config.PULL_STATE == SW_INT_PULL_UP)
		DIO_enumSetPinValue(SW_Config.PORT, SW_Config.PIN, DIO_PIN_OUTPUT);
}

u8 SW_u8GetPressed (SW_Type SW_Config){
	
	u8 LOC_u8Result = SW_NOT_PRESSED ;
	u8 LOC_u8PinVal = SW_NOT_PRESSED ;
	
	if ( (SW_Config.PULL_STATE == SW_INT_PULL_UP) || (SW_Config.PULL_STATE == SW_EXT_PULL_UP) )
	{
		DIO_enumGetPinValue( SW_Config.PORT , SW_Config.PIN , &LOC_u8PinVal );
		
		if (LOC_u8PinVal==0)
		{
			LOC_u8Result = SW_PRESSED ;
		}
		else if (LOC_u8PinVal==1)
		{
			LOC_u8Result = SW_NOT_PRESSED ;
		}

	}
	else if (SW_Config.PULL_STATE == SW_EXT_PULL_DOWN)
	{
		DIO_enumGetPinValue( SW_Config.PORT , SW_Config.PIN , &LOC_u8PinVal );
		
		if (LOC_u8PinVal==0)
		{
			LOC_u8Result = SW_NOT_PRESSED ;
		}
		else if (LOC_u8PinVal==1)
		{
			LOC_u8Result = SW_PRESSED ;
		}
	}
		
	return LOC_u8Result ;
	
}
