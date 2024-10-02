/*
 * SPI_program.c
 *
 *  Created on: Jul 30, 2024
 *      Author: Mostafa AboSalama
 */

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"

void SPI_MasterInit(void)
{   DDRB_Register |=0xB0;             // B5 ,B4 and B7 are configured as output (MOSI , SS',SCK)
	SPCR=0x50;               //SPI is Enable , MSB is transmitted first , Master SPI , SCK is low when idle,Sample in Leading Edge, FOSC/128.
	SPSR=0x00;               //Flag is reset , and FOSC/128 is used .
}

void SPI_SlaveInit(void)
{   DDRB_Register &= (~(1<<6)) ;    // B6 are configured as input (MISO)
	SPCR=0x40;            //SPI is Enable , MSB is transmitted first,  Slave SPI ,SCK is low when idle,Sample in Leading Edge, FOSC/128.
	SPSR=0x00;            //Flag is reset , and FOSC/128 is used .
}


void SPI_SendChar(u8 idata)
{
	SPDR=idata;                     //Send input data to the Data register
	while( (SPSR&&(1<<7))==0 ) ;      // While Transmission not completed wait .  (To aviod overlapping of data transmission )
	
}

u8 SPI_GetChar(void)
{
	while( (SPSR&&(1<<7))==0 ) ;   // While Transmission not completed wait untill it's complete
	return SPDR;                 //Return the received data found in Datareister .
}


