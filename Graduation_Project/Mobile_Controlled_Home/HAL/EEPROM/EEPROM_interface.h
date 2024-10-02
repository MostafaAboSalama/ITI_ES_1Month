/*
 * EEPROM_interface.h
 *
 *  Created on: Aug 12, 2024
 *      Author: Elmag
 */

#ifndef EEPROM_EEPROM_INTERFACE_H_
#define EEPROM_EEPROM_INTERFACE_H_

#define EEPROM_A2_HIGH   1
#define EEPROM_A2_LOW    0

void EEPROM_Init();
u8 EEPROM_SendByte(u8 byte ,u16 Address);
u8 EEPROM_ReadByte(u8 *buff ,u16 Address);
u8 EEPROM_SendFram(u8 byte ,u16 Address);
u8 EEPROM_SendNumber(u32 number ,u16 Address);

#endif /* EEPROM_EEPROM_INTERFACE_H_ */
