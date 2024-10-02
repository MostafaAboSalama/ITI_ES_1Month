/*
  * File:  SPI_Interface.h 
 *	SWC:    SPI
 *	Version: 1.0 
 *  Created on: 08-08-2024 
 *  Author: Abdalla Ragab 
 */
#ifndef SPI_INTERFACE
#define SPI_INTERFACE



#define SPI_MODE_MASTER		1
#define SPI_MODE_SLAVE		0

#define SPI_MODE_CPOL_H		1
#define SPI_MODE_CPOL_L		0

#define SPI_MODE_CPPH_SAMPLE		1
#define SPI_MODE_CPOL_SETUP			0

#define	SPI_DATA_DIR_LSB		1
#define	SPI_DATA_DIR_MSB		0

#define SPI_CLOCK_PRESCALER4		0b000
#define SPI_CLOCK_PRESCALER16		0b001
#define SPI_CLOCK_PRESCALER64		0b010
#define SPI_CLOCK_PRESCALER128		0b011
#define SPI_CLOCK_PRESCALER2        0b100
#define SPI_CLOCK_PRESCALER8        0b110
#define SPI_CLOCK_PRESCALER32       0b110









void SPI_voidINIT();

void SPI_voidSend(u8 value);

u8   SPI_u8receive();

void SPI_voidSend_Receive(u8 value,u8* retVal);
#endif // SPI_INTERFACE
