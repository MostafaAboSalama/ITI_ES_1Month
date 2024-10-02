/*
 * KeyPade_program.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Elmag
 */
#include"../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "KeyPade_config.h"
#include "KeyPade_interface.h"
#include "KeyPade_private.h"


void Keypad_init()
{
	DIO_u8SetPinDirection(KeyPade_PORT , R1 ,INPUT);
	DIO_u8SetPinValue(KeyPade_PORT , R1 ,HIGH);

	DIO_u8SetPinDirection(KeyPade_PORT , R2 ,INPUT);
	DIO_u8SetPinValue(KeyPade_PORT , R2 ,HIGH);

	DIO_u8SetPinDirection(KeyPade_PORT , R3 ,INPUT);
	DIO_u8SetPinValue(KeyPade_PORT , R3 ,HIGH);

	DIO_u8SetPinDirection(KeyPade_PORT , R4 ,INPUT);
	DIO_u8SetPinValue(KeyPade_PORT , R4 ,HIGH);

	DIO_u8SetPinDirection(KeyPade_PORT , C1 ,OUTPUT);

	DIO_u8SetPinDirection(KeyPade_PORT , C2 ,OUTPUT);

	DIO_u8SetPinDirection(KeyPade_PORT , C3 ,OUTPUT);

	DIO_u8SetPinDirection(KeyPade_PORT , C4 ,OUTPUT);


}

u8 Keypad_getkey(void)
{
	for(u8 COL = 0 ; COL<4 ;COL++)
	{
		DIO_u8SetPinValue(KeyPade_PORT , Key_padCol[COL] ,LOW);

		for(u8 ROW = 0 ; ROW<4 ;ROW++)
		{
			if(DIO_u8GetPinValue(KeyPade_PORT ,Key_padRow[ROW])==0)
			{
				while(DIO_u8GetPinValue(KeyPade_PORT ,Key_padRow[ROW])==0);
				return digit[ROW][COL] ;
			}
		}
		DIO_u8SetPinValue(KeyPade_PORT , Key_padCol[COL] ,HIGH);
	}
	return -1;
}
