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

#include "LCD_config.h" // to khow the mode


#if   LCD_MODE == 4
#define FOUR_BITS                     0x28          //4 bits mode initialization
#elif LCD_MODE == 8
#define EIGHT_BITS                    0x38          //8 bits mode initialization (8-bit data, 2-line display, 5 x 7 font )
#endif

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


#define LCD_ROW_1   1
#define LCD_ROW_2   2

#define LCD_COL_1   1
#define LCD_COL_2   2
#define LCD_COL_3   3
#define LCD_COL_4   4
#define LCD_COL_5   5
#define LCD_COL_6   6
#define LCD_COL_7   7
#define LCD_COL_8   8
#define LCD_COL_9   9
#define LCD_COL_10  10
#define LCD_COL_11  11
#define LCD_COL_12  12
#define LCD_COL_13  13
#define LCD_COL_14  14
#define LCD_COL_15  15
#define LCD_COL_16  16

/***************************************************************************************/

void LCD_voidInit                      ( void                                  );
void LCD_voidSendData                  ( u8 Copy_u8Data                        );
void LCD_voidSendCommand               ( u8 Copy_u8Commend                     );
void LCD_voidSendString                ( const u8 * Copy_u8ptrString           );
void LCD_voidSendNumber                ( u64 Copy_u64Number                    );
void LCD_voidSetPosition               ( u8 Copy_u8Row         , u8 Copy_u8Col );
void LCD_voidSendExtraChar             ( u8 Copy_u8Row         , u8 Copy_u8Col );
void LCD_voidClearScreen               (void                                   );

/***************************************************************************************/


#endif /* LCD_INTERFACE_H_ */
