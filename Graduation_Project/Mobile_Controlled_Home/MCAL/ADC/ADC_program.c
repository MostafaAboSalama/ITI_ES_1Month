/*
 * ADC_program.c
 *
 *  Created on: Aug 4, 2024
 *      Author: Hossam Bahaa
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"



void ADC_Init(void)
{
	u8 ADMUX_Temp =0;
	u8 ADCSRA_Temp = 0;

	/* Set Adjust Value */
	ADMUX_Temp |= (ADC_ADJUST << ADLAR);

	/* Set Reference Value */
	ADMUX_Temp |= (ADC_REF << REFS0);

	/* Write to Register */
	ADMUX_Register = ADMUX_Temp;

	/* Set Pre-scaler value */
	ADCSRA_Temp |= (ADC_PSC << ADPS0);

	/* Enable Register */
	SET_BIT(ADCSRA_Temp, ADEN);

	/* Write to Register */
	ADCSRA_Register = ADCSRA_Temp;
}


u16 ADC_StartConversion(u8 L_u8Channel)
{
	/* Clear MUX bits */
	ADMUX_Register &= ~ADMUX_MUX_MASK;

	/* Select Channel */
	ADMUX_Register |= (L_u8Channel << MUX0);

	/* Start Conversion */
	SET_BIT(ADCSRA_Register, ADSC);


	/* Wait for ADC to finish conversion */
	while(GET_BIT(ADCSRA_Register, ADIF) == 0)
	{
		/* Wait for ADC to finish */
	}

	/* Clear ADIF Flag */
	SET_BIT(ADCSRA_Register, ADIF);


	return ADCDATA_Register;
}
