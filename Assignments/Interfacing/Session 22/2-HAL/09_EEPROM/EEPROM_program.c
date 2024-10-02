/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	EEPROM_program.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : EEPROM
 *
*/

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"
#include "../../1-MCAL/0_DIO/DIO_interface.h"
#include "../../1-MCAL/06_I2C/I2C_interface.h"

#include <util\delay.h>

#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"

void EEPROM_voidInit()
{
	I2C_voidInitMaster(10000);
}

void EEPROM_voidWrite(u8 data, u8 cell)
{
	I2C_u8SendStart();
	I2C_u8SendAddress(EEPROM_ADD ,I2C_WRITE_OPERATION); // EEPROM SLAVE ADD + W
	I2C_u8SendData(cell); // EEPROM CELL
	I2C_u8SendData(data); // EEPROM DATA
	I2C_u8SendStop();
}

u8 EEPROM_u8Read(u8 cell)
{
	u8 data;
	I2C_u8SendStart();
	I2C_u8SendAddress(EEPROM_ADD ,I2C_WRITE_OPERATION); // EEPROM SLAVE ADD + W
	I2C_u8SendData(cell); // EEPROM CELL
	I2C_u8RepeatStart(); //REPEATED START
	I2C_u8SendAddress(EEPROM_ADD ,I2C_READ_OPERATION); // EEPROM SLAVE ADD + R
	data = I2C_u8Recive_Without_ACK();
	I2C_u8SendStop();
	return data;
}
