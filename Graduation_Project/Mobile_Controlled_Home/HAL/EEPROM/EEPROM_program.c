/*
 * EEPROM_program.c
 *
 *  Created on: Aug 12, 2024
 *      Author: Elmag
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/I2C/I2C_interface.h"

#include "EEPROM_private.h"
#include "EEPROM_config.h"
#include "EEPROM_interface.h"


void EEPROM_Init()
{
	DIO_u8SetPinDirection(PORTC , PIN0 , INPUT);
	DIO_u8SetPinDirection(PORTC , PIN1 , INPUT);

	DIO_u8SetPinValue(PORTC , PIN0 , LOW);
	DIO_u8SetPinValue(PORTC , PIN1 , LOW);

	I2C_InitMaster(10000);

}
u8 EEPROM_SendByte(u8 byte ,u16 Address)
{
	u8 state = 1 ;
	//1 0 1 0 A2 DA1 DA2  RW
	u8 DevAddress  =((0b1010<<4) |(EEPROM_A2_VAL <<3 )|(((Address >> 8)&3)<<1)&(~1));
	u8 DaAdress = ((u8)Address );

	//send start
	state = I2C_SendStart();

	if(state != I2C_STAT_STA) return state ;
	//send device address

	DevAddress >>= 1 ;
	state = I2C_SendAddress(DevAddress , I2C_WRITE_OPP);

	if(state != I2C_STAT_ADDRESS_ACK)
	{
		I2C_SendStop();
		return state ;
	}

	state = I2C_SendData(DaAdress);

	if(state != I2C_STAT_DATA_ACK)
	{
		I2C_SendStop();
		return state ;
	}

	state = I2C_SendData(byte);
	if(state != I2C_STAT_DATA_ACK)
	{
		I2C_SendStop();
		return state ;
	}

	I2C_SendStop();

	return state ;

}

u8 EEPROM_SendFram(u8 byte ,u16 Address)
{
	u8 state =1;
	u8 DevAddress  =((0b1010<<4) |(EEPROM_A2_VAL <<3 )|(((Address >> 8)&3)<<1)&(~1));

	u8 arr[2] = {0} ;

	arr[0] = (u8)Address ;
	arr[1]= byte ;

	state = I2C_SendFram((DevAddress>>1) , arr ,2);

	return state ;
}
u8 EEPROM_ReadByte(u8 *buff ,u16 Address)
{
	u8 state = 1 ;
	//1 0 1 0 A2 DA1 DA2  RW
	u8 DevAddress  =((0b1010<<4) |(EEPROM_A2_VAL <<3 )|(((Address >> 8)&3)<<1)&(~1));
	u8 DaAdress = ((u8)Address );

	//send start
	I2C_SendStart();

	//send device address

	DevAddress >>= 1 ;
	state = I2C_SendAddress(DevAddress , I2C_WRITE_OPP);

	if(state != I2C_STAT_ADDRESS_ACK)
	{
		I2C_SendStop();
		return state ;
	}

	state = I2C_SendData(DaAdress);

	if(state != I2C_STAT_DATA_ACK)
	{
		I2C_SendStop();
		return state ;
	}

	//DevAddress >>= 1 ;

	state = I2C_SendRepStart();

	if(state != I2C_STAT_STA) return state ;


	state = I2C_SendAddress(DevAddress , I2C_READ_OPP);


	*buff = I2C_ReceiveWithoutAck();

	I2C_SendStop();

	return 0 ;

}

