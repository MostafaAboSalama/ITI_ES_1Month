/*
 * EXTI_interface.h
 *
 *  Created on: Jul 30, 2024
 *      Author: Mohammed Mansour
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#define EXTI0	1
#define EXTI1	2
#define EXTI2	3

#define  EXTI_MODE_RISING	0b11
#define  EXTI_MODE_FALLING	0b10
#define  EXTI_MODE_ONCHANGE	0b01
#define  EXTI_MODE_LOWLEVEL	0b00

//void EXTI_Init(void);
void EXTI_Enable(u8 L_u8EXTINum);
void EXTI_SetMode(u8 L_u8EXTINum, u8 L_u8Mode);
void EXTI_Disable(u8 L_u8EXTINum);
void EXTI_SetCallback(u8 L_u8EXTINum, void (* ptr)());


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
