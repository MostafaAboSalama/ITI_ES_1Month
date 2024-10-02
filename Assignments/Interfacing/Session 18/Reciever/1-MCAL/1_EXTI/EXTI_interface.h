#ifndef  EXTI_INTERFACE_H_
#define  EXTI_INTERFACE_H_


#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#define EXTI_LINE0		0	
#define EXTI_LINE1		1	
#define EXTI_LINE2		2	

#define LOW_LEVEL		0
#define LOGICAL_CHANGE	1
#define FALLING_EDGE	2
#define RISING_EDGE		3

#define EXTI2_FALLING_EDGE	0
#define EXTI2_RISING_EDGE	1

void EXTI_voidEnable(u8 line, u8 mode);

void EXTI_voidSetCallBack(u8 line, void(*pf)(void));

void EXTI_voidClearFlag(u8 line);

#endif /*EXTI_INTERFACE_H_*/
