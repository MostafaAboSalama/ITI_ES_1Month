/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	LCD_program.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : LCD
 *
*/

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"
#include "../../1-MCAL/0_DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "util/delay.h"



void LCD_voidInit        ( void ){



	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	#if   LCD_MODE == 8

	// 1- must wait more than 30 ms before any action (VDD rises to 4.5 v)
	_delay_ms(50);

	// All Pins as OutPut pins
	DIO_enumSetPortDirection ( LCD_DATA_PORT    , DIO_PORT_OUTPUT           );
	DIO_enumSetPinDirection  ( LCD_CTRL_PORT , LCD_RS , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( LCD_CTRL_PORT , LCD_RW , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( LCD_CTRL_PORT , LCD_EN , DIO_PIN_OUTPUT  );

	/* Return cursor to the first position on the first line  */
	LCD_voidSendCommand(LCD_HOME);
	_delay_ms(1);

	/*FUNCTION SET Command : 2 lines , 5*8 font size */
	LCD_voidSendCommand( EIGHT_BITS ); // 8 Bit Mode ==> 0x38
	_delay_ms(1); // wait more than 39 Ms

	/* DISPLAY & Cursor (ON / OFF) Control */
	LCD_voidSendCommand( LCD_DISPLAY_ON_CURSOR_OFF );
	_delay_ms(1);

	/* DISPLAY CLEAR */
	LCD_voidClearScreen();

	/* ENTRY MODE  SET*/
	LCD_voidSendCommand( LCD_ENTRY_MODE );
	_delay_ms(1);



	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	#elif   LCD_MODE == 4

	// 1- must wait more than 30 ms before any action (VDD rises to 4.5 v)
	_delay_ms(50);
	DIO_enumSetPinDirection      (LCD_DATA_PORT,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (LCD_DATA_PORT,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (LCD_DATA_PORT,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (LCD_DATA_PORT,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection  ( LCD_CTRL_PORT , LCD_RS , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( LCD_CTRL_PORT , LCD_RW , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( LCD_CTRL_PORT , LCD_EN , DIO_PIN_OUTPUT  );



	/*return home*/
	LCD_voidSendCommand( LCD_HOME );
	_delay_ms(30);

	/*FUNCTION SET Command*/
	LCD_voidSendCommand( FOUR_BITS ); // 4 Bit Mode
	_delay_ms(1);

	/* DISPLAY & Cursor (ON / OFF) Control */
	LCD_voidSendCommand( LCD_DISPLAY_ON_CURSOR_OFF );
	_delay_ms(1);

	/* DISPLAY CLEAR */
	LCD_voidClearScreen();

	/* ENTRY MODE  Set*/
	LCD_voidSendCommand( LCD_ENTRY_MODE );
	_delay_ms(1);


	#endif




}


void LCD_voidSendData    ( u8 Copy_u8Data ){

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if   LCD_MODE == 8

	DIO_enumSetPortValue ( LCD_DATA_PORT    , Copy_u8Data        );
	DIO_enumSetPinValue  ( LCD_CTRL_PORT , LCD_RS , DIO_PIN_HIGH );
	DIO_enumSetPinValue  ( LCD_CTRL_PORT , LCD_RW , DIO_PIN_LOW  );
	LCD_voidSendFallingEdge();

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif   LCD_MODE == 4

	DIO_enumSetPinValue  ( LCD_CTRL_PORT , LCD_RS , DIO_PIN_HIGH );
	DIO_enumSetPinValue  ( LCD_CTRL_PORT , LCD_RW , DIO_PIN_LOW  );
	DIO_voidWriteHighNibbles (LCD_DATA_PORT ,(Copy_u8Data>>4));            // send the most 4 bits of data to high nibbles
	LCD_voidSendFallingEdge();
	DIO_voidWriteHighNibbles (LCD_DATA_PORT ,Copy_u8Data);               // send the least 4 bits of data to high nibbles
	LCD_voidSendFallingEdge();

	#endif

	_delay_ms(1);

}


void LCD_voidSendCommand ( u8 Copy_u8Command ){

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if   LCD_MODE == 8

	DIO_enumSetPortValue ( LCD_DATA_PORT    , Copy_u8Command     );
	DIO_enumSetPinValue  ( LCD_CTRL_PORT , LCD_RS , DIO_PIN_LOW  );
	// RW always connect to GND to Write
	DIO_enumSetPinValue          (LCD_CTRL_PORT,LCD_RW , DIO_PIN_LOW    );
	LCD_voidSendFallingEdge();

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif   LCD_MODE == 4

	DIO_enumSetPinValue  ( LCD_CTRL_PORT , LCD_RS , DIO_PIN_LOW  );
	DIO_enumSetPinValue  ( LCD_CTRL_PORT , LCD_RW , DIO_PIN_LOW  );
	DIO_voidWriteHighNibbles (LCD_DATA_PORT ,Copy_u8Command>>4);             // send the most 4 bits of data to high nibbles
	LCD_voidSendFallingEdge();
	DIO_voidWriteHighNibbles (LCD_DATA_PORT ,Copy_u8Command);                // send the least 4 bits of data to high nibbles
	LCD_voidSendFallingEdge();

	#endif

	_delay_ms(1);

}


void LCD_voidSendString  ( const u8 * Copy_u8ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[LOC_u8Iterator] != '\0' ){

		LCD_voidSendData( Copy_u8ptrString[LOC_u8Iterator] );
		LOC_u8Iterator++ ;

	}

}

void LCD_voidSendNumber   ( u64 Copy_u64Number    ){

	u64 LOC_u64Reversed = 1 ;

	if( Copy_u64Number == 0 ){ LCD_voidSendData('0'); }

	else{

		while( Copy_u64Number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u64Number % 10 );
			Copy_u64Number /= 10 ;

		}
		while( LOC_u64Reversed != 1 ){

			LCD_voidSendData( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}

}


void LCD_voidSetPosition ( u8 Copy_u8Row , u8 Copy_u8Col ){

	u8 LOC_u8data ;

	/* In These cases will set at (0,0) ==> if the user enter invalid location */
	if(Copy_u8Row>2||Copy_u8Row<1||Copy_u8Col>16||Copy_u8Col<1)  //check
	{
		LOC_u8data = LCD_CURSOR ;   // first location
	}

	else if( Copy_u8Row == LCD_ROW_1 ){

		LOC_u8data = ( ( LCD_CURSOR ) + ( Copy_u8Col - 1 ) );              //Row1 -> 0x80+col-1

	}

	else if( Copy_u8Row == LCD_ROW_2 ){

		LOC_u8data = ( ( LCD_CURSOR ) + (64) + ( Copy_u8Col - 1 ) );       //Row2 -> 0xc0+col-1

	}
	LCD_voidSendCommand ( LOC_u8data );
	_delay_ms(1);

}




void LCD_voidClearScreen(void)
{
	LCD_voidSendCommand(LCD_CLEAR);
	_delay_ms(10); //wait more than 1.53 ms
}



static void LCD_voidSendFallingEdge(void)
{
	DIO_enumSetPinValue  ( LCD_CTRL_PORT , LCD_EN , DIO_PIN_HIGH );
	_delay_ms(1);
	DIO_enumSetPinValue  ( LCD_CTRL_PORT , LCD_EN , DIO_PIN_LOW  );
	_delay_ms(1);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
