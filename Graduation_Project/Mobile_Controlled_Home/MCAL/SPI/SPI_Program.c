/*
  * File:  SPI_Program.c 
 *	SWC:    SPI
 *	Version: 1.0 
 *  Created on: 08-08-2024 
 *  Author: Abdalla Ragab 
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include    "SPI_Interface.h"
#include    "SPI_Config.h"
#include    "SPI_Private.h"


void (*vFunptr)(void)=NULL ;



void SPI_voidINIT(){
	//choose slave or master mode
#if SPI_MODE==SPI_MODE_MASTER

	SET_BIT(SPCR,SPCR_MSTR);
#elif SPI_MODE==SPI_MODE_SLAVE
	CLEAR_BIT(SPCR,SPCR_MSTR);
#endif

	//choose clock(prescaler)
	SPCR=SPCR&(~(0b11));
	SPCR=SPCR|((SPI_CLOCK_PRESCALER)&0b11);

	SPSR=SPSR&(~(1));
	SPSR=SPSR|(  (SPI_CLOCK_PRESCALER>>2)&(1)  )   ;


	//choose clock phase and polarity
	if(SPI_CKPOL==SPI_MODE_CPOL_H){
		SET_BIT(SPCR,SPCR_CPOL);
	}
	else{
		CLEAR_BIT(SPCR,SPCR_CPOL);

	}

	if(SPI_CKPH==SPI_MODE_CPPH_SAMPLE){
		SET_BIT(SPCR,SPCR_CPHA);
	}
	else{
		CLEAR_BIT(SPCR,SPCR_CPHA);

	}

	//choose data direction
	if(SPI_DATA_DIR==SPI_DATA_DIR_LSB){
			SET_BIT(SPCR,SPCR_DORD);
		}
	else{
		CLEAR_BIT(SPCR,SPCR_DORD);

	}

	//choose if you want to enable interrupt
	//its own function


	//enable spi
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidSend_Receive(u8 value,u8* retVal){
	if(retVal!= 0){
		//send value over spi
		SPDR=value;

		//wait for value to be delevired
		while(!GET_BIT(SPSR,SPSR_SPIF));

		//retrieve data from buffer
		*retVal=SPDR;
	}
	else{

	}


}

u8  SPI_u8receive(){
	while(!GET_BIT(SPSR,SPSR_SPIF));
	return SPDR;
}

void SPI_Enable_Interrupt(){
	SET_BIT(SPCR,SPCR_SPIE);
}

void SPI_Disable_Interrupt(){
	CLEAR_BIT(SPCR,SPCR_SPIE);
}

void SPI_SetCallback(void(*fptr)(void)){
	vFunptr=fptr;
}

void __vector_12(){
	if(vFunptr!=NULL){
		vFunptr();
	}
}
