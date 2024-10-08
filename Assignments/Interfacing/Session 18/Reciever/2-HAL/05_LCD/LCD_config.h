/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	LCD_config.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : LCD
 *
*/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_DATA_PORT 	DIO_PORTA
#define LCD_CTRL_PORT 	DIO_PORTB

#define LCD_D0		DIO_PIN0
#define LCD_D1		DIO_PIN1
#define LCD_D2		DIO_PIN2
#define LCD_D3		DIO_PIN3
#define LCD_D4		DIO_PIN4
#define LCD_D5		DIO_PIN5
#define LCD_D6		DIO_PIN6
#define LCD_D7		DIO_PIN7

#define LCD_RS		DIO_PIN0
#define LCD_RW		DIO_PIN1
#define LCD_EN		DIO_PIN2

#endif /* LCD_CONFIG_H_ */
