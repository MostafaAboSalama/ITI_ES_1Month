#ifndef  SPI_INTERFACE_H_
#define  SPI_INTERFACE_H_


#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#define SPI_MASTER		0
#define SPI_SLAVE 		1

#define SPI_RISING_LEADING_FALLING_TRAILING 	0
#define SPI_FALLING_LEADING_RISING_TRAILING		1

#define SPI_SAMPLE_LEADING_SETUP_TRAILING 		0
#define SPI_SETUP_LEADING_SAMPLE_TRAILING		1

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_SendChar(u8 idata);
u8 SPI_GetChar(void);
#endif /*SPI_INTERFACE_H_*/
