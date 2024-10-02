/*
 * I2C_program.c
 *
 *  Created on: Aug 11, 2024
 *      Author: Elmag
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"

#include <avr/delay.h>

void I2C_InitMaster(u16 SCL_Clock)
{
	SET_BIT(TWCR ,TWEN);
	CLEAR_BIT(TWSR , TWPS0);
	CLEAR_BIT(TWSR , TWPS1);
	TWBR = (u8)((8000000/8*SCL_Clock)-2);
}

void I2C_InitSlave(void)
{
	SET_BIT(TWCR ,TWEN);

	TWAR = I2C_SLAVE_ADRESS <<1;
}

u8 I2C_SendStart(void)
{
	//if(GET_BIT(TWCR , TWINT)== 0) return 0xFF ;
     TWCR|=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	while(GET_BIT(TWCR , TWINT)== 0);
	return TWSR & 0xF8;

}

u8 I2C_SendRepStart(void)
{

	CLEAR_BIT(TWCR , TWEN);
	//if(GET_BIT(TWCR , TWINT)== 0) return 0xFF ;
     TWCR|=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	while(GET_BIT(TWCR , TWINT)== 0);
	return TWSR&0xf8;

}
u8 I2C_SendAddress(u8 address , u8 opp)
{
	TWDR =  (address <<TWA0 )| (opp);

	TWCR |= (1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR , TWINT) == 0);
	return TWSR &0xf8;

}
u8 I2C_SendData(u8 data)
{
  TWDR = data ;

  TWCR |=(1<<TWINT)|(1<<TWEN) ;

  while(GET_BIT(TWCR , TWINT)== 0);

  return TWSR & 0xf8 ;

}
u8 I2C_SendStop(void)
{
	//if(GET_BIT(TWCR , TWINT)== 0) return 0xFF ;
     TWCR |=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);

    CLEAR_BIT(TWCR,TWSTA);
	return TWSR & 0xF8;
}
u8 I2C_ReceiveWihtAck(void)
{
  TWCR |=(1<< TWINT)|(1<<TWEA)|(1<<TWEN) ;

  while(GET_BIT(TWCR , TWINT)== 0);

  return TWDR ;
}
u8 I2C_ReceiveWithoutAck(void)
{
	  TWCR |=(1<< TWINT)|(1<<TWEN)  ;

	  while(GET_BIT(TWCR , TWINT)== 0);

	  return TWDR ;
}

u8 I2C_SendFram(u8 address , u8*buf , u8 len)
{
	u8 state ;
	//send start condition
	state = I2C_SendStart();

	if(state != I2C_STAT_STA) return state ;

	state = I2C_SendAddress(address , I2C_WRITE_OPP);

	if(state != I2C_STAT_ADDRESS_ACK) return state ;

	for(int i= 0 ; i<len; i++)
	{
		state = I2C_SendData(buf[i]);
		if(state != I2C_STAT_DATA_ACK) break ;

	}
	 I2C_SendStop();
	 CLEAR_BIT(TWCR , TWSTA);
	return state ;
}
