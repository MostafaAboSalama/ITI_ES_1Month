/*
 * LCD_interface.h
 *
 *  Created on: Jul 29, 2024
 *      Author: Elmag
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

#define LCD_Clear_Screen   0x01
#define LCD_Return_Home    0x03
#define LCD_Entry_Mode1    0x06  //normal mode
#define LCD_Entry_Mode2    0x07  // display shift right mode
#define LCD_Display_Mode1  0x0F  // display on ,cursor on , cursor blink on
#define LCD_Display_Mode2  0x0D  // display on ,cursor off
#define LCD_Function_set1  0x38
#define LCD_Function_set2  0x3F
#define LCD_FIRST_ROW	  (0x80)
#define LCD_SECOND_ROW	  (0xC0)
#define LCD_DISP_ON   	  (0x0C)
#define LCD_DISP_ON_CURSOR (0x0E)




void HLCD_voidinit();

void HLCD_voidCommand(u8 command);

void HLCD_voidSetDDRAM_Address(u8 address);

void HLCD_SendData(u8 data);

void HLCD_PrintString(u8 *data);

void LCD_display_number(int number);

void HLCD_GOTO_XY(u8 line, u8 position);

#endif /* LCD_LCD_INTERFACE_H_ */
