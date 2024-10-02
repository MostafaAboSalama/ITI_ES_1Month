/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mostafa AboSalama
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */



#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_voidInit(void)
{
	ADCSRA = 0; ADMUX = 0;
	/*Enable ADC Unit*/
	SET_BIT(ADCSRA, ADEN);
	
	/*Select PSC*/
	ADCSRA |= ADC_PSC << ADPS0;
	
	/*SET VREF*/
	ADMUX |= ADC_REF << REFS0;
	
	/*ADJUST*/
	ADMUX |= ADC_ADJUST << ADLAR;
}

void ADC_voidSelectChannel(u8 channel)
{
	ADMUX &= 0XE0;
	ADMUX |= channel << MUX0;

}

f32 ADC_voidStartConversion(void)
{
	SET_BIT(ADCSRA, ADSC);
	
	/*WAIT CONVERSION*/
	while(GET_BIT(ADCSRA, ADSC))
	{
		/*WAITING*/
	}
	
	return ADC_FULL;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>






