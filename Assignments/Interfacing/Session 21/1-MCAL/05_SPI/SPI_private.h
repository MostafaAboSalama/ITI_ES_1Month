#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPDR	*(volatile u8*)(0x2F)        
#define SPSR	*(volatile u8*)(0x2E)        
#define SPCR	*(volatile u8*)(0x2D)        
#define DDRB_Register   *((volatile u8*)0x37)

 /* SPCR BITS */
#define SPIE	7
#define SPE		6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0

/* SPSR BITS */   
#define SPIF	7
#define WCOL	6
/////////////////
/////////////////
/////////////////
/////////////////
/////////////////
#define SPI2X	0

/* SPDR BITS */    
#define MSB		7
#define LSB		6


#endif /* SPI_PRIVATE_H_ */
