/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	SSD_program.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : SSD
 *
*/
#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/0_DIO/DIO_interface.h"


#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

static u8 Local_u8SSDNums[10] = SSD_ArrNums;

void SSD_voidInit(SSD_Type SSD_Configuration)
{
	DIO_enumSetPortDirection (SSD_Configuration.DataPort, DIO_PORT_OUTPUT);
}

void SSD_voidSendNumber(SSD_Type SSD_Configuration, u8 Copy_u8Number)
{
	if(SSD_Configuration.Type == SSD_COMM_CAT)
	{
		DIO_enumSetPortValue(SSD_Configuration.DataPort, Local_u8SSDNums[Copy_u8Number] );
	}
	else if(SSD_Configuration.Type == SSD_COMM_AND)
	{
		DIO_enumSetPortValue(SSD_Configuration.DataPort, ~Local_u8SSDNums[Copy_u8Number]);
	}
}

void SSD_voidEnable(SSD_Type SSD_Configuration)
{
	DIO_enumSetPinDirection(SSD_Configuration.DataPort, SSD_Configuration.EnPin, DIO_PIN_OUTPUT);
	if(SSD_Configuration.Type == SSD_COMM_CAT)
	{
		DIO_enumSetPinValue(SSD_Configuration.DataPort, SSD_Configuration.EnPin, DIO_PIN_LOW);
	}
	else if(SSD_Configuration.Type == SSD_COMM_AND)
	{
		DIO_enumSetPinValue(SSD_Configuration.DataPort, SSD_Configuration.EnPin, DIO_PIN_HIGH);
	}
}

void SSD_voidDisable(SSD_Type SSD_Configuration)
{
	DIO_enumSetPinDirection(SSD_Configuration.DataPort, SSD_Configuration.EnPin, DIO_PIN_OUTPUT);
	if(SSD_Configuration.Type == SSD_COMM_CAT)
	{
		DIO_enumSetPinValue(SSD_Configuration.DataPort, SSD_Configuration.EnPin, DIO_PIN_HIGH);
	}
	else if(SSD_Configuration.Type == SSD_COMM_AND)
	{
		DIO_enumSetPinValue(SSD_Configuration.DataPort, SSD_Configuration.EnPin, DIO_PIN_LOW);
	}
}
