/*
  * File:  SPI_Private.h 
 *	SWC:    SPI
 *	Version: 1.0 
 *  Created on: 08-08-2024 
 *  Author: Abdalla Ragab 
 */
#ifndef SPI_PRIVATE
#define SPI_PRIVATE

/* SPCR Bits */
#define SPCR_SPIE                   7
#define SPCR_SPE                    6
#define SPCR_DORD                   5
#define SPCR_MSTR                   4
#define SPCR_CPOL                   3
#define SPCR_CPHA                   2
#define SPCR_SPR1                   1
#define SPCR_SPR0                   0


/* SPSR BITS */
#define SPSR_SPIF                   7
#define SPSR_WCOL                   6
#define SPSR_SPI2X                  0



#define SPCR   *((volatile u8*)0x2D)
#define SPSR   *((volatile u8*)0x2E)
#define SPDR   *((volatile u8*)0x2F)

void __vector_12(void);

#endif // SPI_PRIVATE
