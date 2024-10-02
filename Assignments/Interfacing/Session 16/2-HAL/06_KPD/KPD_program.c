/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	KPD_program.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : KPD
 *
*/

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/0_DIO/DIO_interface.h"

#include <util/delay.h>

#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"

void KPD_voidInit(void)
{
	/* ROWS -> INT_PULLUP */
	DIO_enumSetPinDirection(KPD_PORT, KPD_R0, DIO_PIN_INPUT);
	DIO_enumSetPinValue(KPD_PORT, KPD_R0, DIO_PIN_HIGH);
	
	DIO_enumSetPinDirection(KPD_PORT, KPD_R1, DIO_PIN_INPUT);
	DIO_enumSetPinValue(KPD_PORT, KPD_R1, DIO_PIN_HIGH);
	
	DIO_enumSetPinDirection(KPD_PORT, KPD_R2, DIO_PIN_INPUT);
	DIO_enumSetPinValue(KPD_PORT, KPD_R2, DIO_PIN_HIGH);
	
	DIO_enumSetPinDirection(KPD_PORT, KPD_R3, DIO_PIN_INPUT);
	DIO_enumSetPinValue(KPD_PORT, KPD_R3, DIO_PIN_HIGH);
	
	/* COLS -> OUTPUT, HIGH */
	DIO_enumSetPinDirection(KPD_PORT, KPD_C0, DIO_PIN_OUTPUT);
	DIO_enumSetPinValue(KPD_PORT, KPD_C0, DIO_PIN_HIGH);
	
	DIO_enumSetPinDirection(KPD_PORT, KPD_C1, DIO_PIN_OUTPUT);
	DIO_enumSetPinValue(KPD_PORT, KPD_C1, DIO_PIN_HIGH);
	
	DIO_enumSetPinDirection(KPD_PORT, KPD_C2, DIO_PIN_OUTPUT);
	DIO_enumSetPinValue(KPD_PORT, KPD_C2, DIO_PIN_HIGH);
	
	DIO_enumSetPinDirection(KPD_PORT, KPD_C3, DIO_PIN_OUTPUT);
	DIO_enumSetPinValue(KPD_PORT, KPD_C3, DIO_PIN_HIGH);
	
	
	
}

u8 KPD_u8GetPressed(void)
{
	u8 LOC_u8RetVal = NOT_PRESSED;
	
	u8 LOC_u8GetPressed;
	
	u8 LOC_u8ROW_Iterator;
	u8 LOC_u8COL_Iterator;
	
	for(LOC_u8COL_Iterator = KPD_COL_INIT; LOC_u8COL_Iterator < KPD_COL_END; LOC_u8COL_Iterator++)
	{
		DIO_enumSetPinValue(KPD_PORT, LOC_u8COL_Iterator, DIO_PIN_LOW);
		for(LOC_u8ROW_Iterator = KPD_ROW_INIT; LOC_u8ROW_Iterator < KPD_ROW_END; LOC_u8ROW_Iterator++)
		{
			DIO_enumGetPinValue(KPD_PORT, LOC_u8ROW_Iterator, &LOC_u8GetPressed);
			
			if(LOC_u8GetPressed == 0)
			{
				_delay_ms(50); // bouncing
				DIO_enumGetPinValue(KPD_PORT, LOC_u8ROW_Iterator, &LOC_u8GetPressed);
				
				if(LOC_u8GetPressed == 0)
				{
					LOC_u8RetVal = KPD_u8Buttons[LOC_u8ROW_Iterator - KPD_ROW_INIT][LOC_u8COL_Iterator - KPD_COL_INIT];
				}
				
				_delay_ms(200); // if continuous pressing
				break;
			}
		}
		
		DIO_enumSetPinValue(KPD_PORT, LOC_u8COL_Iterator, DIO_PIN_HIGH);
	}
	
	return LOC_u8RetVal;
}
