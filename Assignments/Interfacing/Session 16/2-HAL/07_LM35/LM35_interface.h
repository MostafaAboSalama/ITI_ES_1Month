/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LM35_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mostafa AboSalama
 *  Layer  : MCAL
 *  SWC    : LM35
 *
 */ 

 

#ifndef   LM35_INTERFACE_H_
#define   LM35_INTERFACE_H_
		  
#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

/***Channel Choice***/

/*******************/
void LM35_voidInit(void);

f32 LM35_voidGetTemp(void);


#endif
