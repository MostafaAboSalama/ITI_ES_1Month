/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	STEPPER_program.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : KPD
 *
*/

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/0_DIO/DIO_interface.h"

#include <util\delay.h>

#include "STEPPER_interface.h"
#include "STEPPER_config.h"
#include "STEPPER_private.h"

void STEPPER_voidInit( void )
{
	DIO_enumSetPinDirection( STEPPER_PORT , STEPPER_PIN0 , DIO_PORT_OUTPUT );
	DIO_enumSetPinDirection( STEPPER_PORT , STEPPER_PIN1 , DIO_PORT_OUTPUT );
	DIO_enumSetPinDirection( STEPPER_PORT , STEPPER_PIN2 , DIO_PORT_OUTPUT );
	DIO_enumSetPinDirection( STEPPER_PORT , STEPPER_PIN3 , DIO_PORT_OUTPUT );

	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW );
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW );
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW );
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW );
}

void STEPPER_voidOff( void )
{
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW );
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW );
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW );
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW );
}

void STEPPER_voidOn( u8 StepType , u8 Direction , u8 Speed , u16 Degree )
{
	u32 LOC_u16Iterator = 0 ;

	if( StepType == STEPPER_FULL_STEP ){

		if( Direction == STEPPER_CLOCK_WISE ){

			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Degree * 256 ) / 45 ) / 4 ; LOC_u16Iterator++  ){

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_HIGH );
				_delay_ms( Speed );


			}

		}else if( Direction == STEPPER_ANTI_CLOCK_WISE ){

			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Degree * 256 ) / 45 ) / 4 ; LOC_u16Iterator++  ){

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_HIGH );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );


			}

		}

	}else if( StepType == STEPPER_HALF_STEP ){

		if( Direction == STEPPER_CLOCK_WISE ){

			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Degree * 512 ) / 45 ) / 8 ; LOC_u16Iterator++  ){

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0, DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1, DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2, DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3, DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_HIGH );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_HIGH );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_HIGH );
				_delay_ms( Speed );



			}

		}else if( Direction == STEPPER_ANTI_CLOCK_WISE ){


			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Degree * 512 ) / 45 ) / 8 ; LOC_u16Iterator++  ){
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_HIGH );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_HIGH );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_HIGH );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_LOW  );
				_delay_ms( Speed );

			}

		}

	}

}
