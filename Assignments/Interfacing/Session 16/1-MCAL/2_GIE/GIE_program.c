/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    GIE_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mostafa AboSalama
 *  Layer  : MCAL
 *  SWC    : GIE
 *
 */



#include "GIE_interface.h"
#include "GIE_private.h"


void GIE_voidEnable()
{
	SET_BIT(SREG, I_BIT);
}
void GIE_voidDisable()
{
	CLR_BIT(SREG, I_BIT);
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>






