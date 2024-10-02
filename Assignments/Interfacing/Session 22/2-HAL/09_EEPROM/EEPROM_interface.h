/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	EEPROM_interface.h	  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : EEPROM
 *
*/

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidInit();

void EEPROM_voidWrite(u8 data, u8 cell);

u8 EEPROM_u8Read(u8 cell);


#endif /* EEPROM_INTERFACE_H_ */
