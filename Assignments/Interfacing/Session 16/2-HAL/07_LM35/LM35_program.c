/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LM35_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mostafa AboSalama
 *  Layer  : MCAL
 *  SWC    : LM35
 *
 */



#include "LM35_interface.h"
#include "LM35_private.h"
#include "LM35_config.h"

#include "../../1-MCAL/4_ADC/ADC_interface.h"

void LM35_voidInit(void)
{
	ADC_voidInit();
	ADC_voidSelectChannel(LM35_PIN);
}

f32 LM35_voidGetTemp(void)
{
	f32 temp;
	f32 ADC_val;
	ADC_val = ADC_voidStartConversion();
	temp = (ADC_val *500.0)/1023.0;
	return temp;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>






