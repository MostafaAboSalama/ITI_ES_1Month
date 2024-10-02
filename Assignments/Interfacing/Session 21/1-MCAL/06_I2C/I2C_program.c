/*
 * SPI_program.c
 *
 *  Created on: Jul 30, 2024
 *      Author: Mostafa AboSalama
 */

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"

void I2C_voidInitMaster(u32 Copy_u32BitRate)
{
	SET_BIT(TWCR , TWEN);
	CLR_BIT(TWSR ,TWPS0);
	CLR_BIT(TWSR ,TWPS1);

	TWBR = (((u32)8000000)/(8* Copy_u32BitRate))-2;

}
void I2C_InitSlave(void)
{
	SET_BIT(TWCR , TWEN);
	TWAR = (I2C_SLAVE_ADDRESS << 1);
}
u8 I2C_u8SendStart(void)
{

	SET_BIT(TWCR , TWSTA);
	SET_BIT(TWCR , TWINT);
	while(GET_BIT(TWCR , TWINT) == 0);
	return (TWSR & 0xF8);

}
u8 I2C_u8SendAddress(u8 Copy_u8address ,u8 Copy_u8Operation)
{
	TWDR = (Copy_u8address << TWA0) | (Copy_u8Operation);
	SET_BIT(TWCR , TWINT);
	while(GET_BIT(TWCR , TWINT) == 0);
	return (TWSR & 0xF8);
}
u8 I2C_u8SendData(u8 Copy_u8data)
{
	TWDR = Copy_u8data;
	SET_BIT(TWCR , TWINT);
	while(GET_BIT(TWCR , TWINT) == 0);
	return (TWSR & 0xF8);
}
u8 I2C_u8SendStop(void)
{

	SET_BIT(TWCR , TWSTO);
	SET_BIT(TWCR , TWINT);

	return (TWSR & 0xF8);
}

u8 I2C_u8Recive_With_ACK(void)
{
	TWCR |= (1<< TWEA )|(1<< TWINT);
	while(GET_BIT(TWCR , TWINT) == 0);
	return TWDR ;
}

u8 I2C_u8Recive_Without_ACK(void)
{
	TWCR |= (1<< TWINT);
	while(GET_BIT(TWCR , TWINT) == 0);
	return TWDR ;
}

u8 I2C_u8SendFrame(u8 Copy_u8Address , u8 *Copy_pu8Buffer , u8 Copy_u8Length)
{
	u8 Local_u8State = 0;
	Local_u8State= I2C_u8SendStart();

	if(Local_u8State != I2C_STATE_STA)
	{
		I2C_u8SendStop();
		return Local_u8State;
	}

	Local_u8State = I2C_u8SendAddress(Copy_u8Address ,I2C_WRITE_OPERATION);

	if (Local_u8State != I2C_START_ADDRESS_ACK)
	{
		I2C_u8SendStop();
		return Local_u8State;
	}

	for(int i =0 ; i< Copy_u8Length ; i++)
	{
		Local_u8State = I2C_u8SendData(Copy_pu8Buffer[i]);


		if (Local_u8State != I2C_START_DATA_ACK)
		{
			I2C_u8SendStop();
			break;
		}
	}
	CLR_BIT(TWCR , TWSTA);
	Local_u8State = I2C_u8SendStop();

	return Local_u8State;
}
