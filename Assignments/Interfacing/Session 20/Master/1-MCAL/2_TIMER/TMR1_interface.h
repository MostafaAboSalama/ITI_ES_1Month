/*
 * TMR2_interface.h
 *
 *  Created on: Aug 3, 2024
 *      Author: user
 */

#ifndef TMR1_INTERFACE_H_
#define TMR1_INTERFACE_H_

#define PWM_OCR1A		0
#define PWM_OCR1B		1

#define ICU_FALLING_EDGE	0
#define ICU_RISING_EDGE		1


void TMR1_voidInitFAST_PWM(u16 period_us);

void TMR1_voidSetDutyCycle(u8 channel, u16 DC_us);

void TMR1_voidSetCallBack(void (*pf)(void));

void TMR1_voidICU_Init(void);

u16 TMR1_u16ICU_Read(void);

void TMR1_voidICU_SetEdge(u8 edge);

#endif /* TMR1_INTERFACE_H_ */
