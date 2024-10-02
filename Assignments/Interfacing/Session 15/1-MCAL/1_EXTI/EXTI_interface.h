#ifndef  EXTI_INTERFACE_H_
#define  EXTI_INTERFACE_H_


#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#define EXTI0 0
#define EXTI1 1
#define EXTI2 2


void EXTI_Init(void);
void EXTI_Enable(u8 L_u8EXTI_Num);
void EXTI_Disable(u8 L_u8EXTI_Num);
void EXTI_SetCallback(u8 L_u8EXTI_Num, void (* ptr)());

#endif /*EXTI_INTERFACE_H_*/
