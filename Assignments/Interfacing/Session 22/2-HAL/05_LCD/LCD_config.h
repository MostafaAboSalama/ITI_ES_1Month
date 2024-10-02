/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	LCD_config.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : LCD
 *
*/



#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/***************************************************************************************/
/* LCD Mode */

	/* Choose 8 for 8_bit connection, 4 for 4_bit connection */

/* $ Options :-

	1- 4
	2- 8

 */
#define LCD_MODE  4


/***************************************************************************************/


/* D0 ------> D7 */

/*

  Options:-
 	 1-DIO_PORTA
 	 2-DIO_PORTB
 	 3-DIO_PORTC
 	 4-DIO_PORTD

 */
/***************************************************************************************/


#define LCD_DATA_PORT      DIO_PORTA
/* RS,RW,EN */
#define LCD_CTRL_PORT      DIO_PORTD

/***************************************************************************************/


/*

 Options:-
 	 1-DIO_PIN0
 	 2-DIO_PIN1
 	 3-DIO_PIN2
 	 4-DIO_PIN3
 	 5-DIO_PIN4
 	 6-DIO_PIN5
 	 7-DIO_PIN6
 	 8-DIO_PIN7

 */
#define LCD_RS             DIO_PIN2
#define LCD_RW             DIO_PIN1
#define LCD_EN             DIO_PIN0

/***************************************************************************************/


#endif /* CLCD_CONFIG_H_ */
