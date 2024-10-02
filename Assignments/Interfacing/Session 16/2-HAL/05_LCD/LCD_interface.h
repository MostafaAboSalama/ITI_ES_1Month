/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	LCD_interface.h	  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : LCD
 *
*/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#define LCD_CLEAR 					0x01
#define LCD_HOME	 				0x02
#define LCD_ENTRY_MODE 				0x06
#define LCD_CLEAR 					0x01
#define LCD_DISPLAY_ON_CURSOR_ON 	0x0E
#define LCD_DISPLAY_ON_CURSOR_OFF 	0x0C
#define LCD_DISPLAY_OFF_CURSOR_OFF 	0x08
#define LCD_FUNCTION_SET 			0x30
#define LCD_CURSOR					0X80
#define LCD_CGRAM					0X40




void LCD_voidInit();
void LCD_voidSendCommand(u8 command);
void LCD_voidSendData(u8 data);
void LCD_voidSendString(u8* string);
void LCD_voidSetCursorPosition(u8 row, u8 col);
void LCD_voidSendNumber   ( u64 Copy_u64Number    );

#endif /* LCD_INTERFACE_H_ */
