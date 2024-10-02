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

void TMR1_voidInitFAST_PWM(u16 period_us);

void TMR1_voidSetDutyCycle(u8 channel, u16 DC_us); 


void TMR1_voidSetCallBackPWM(void (*pf)(void));

#endif /* TMR1_INTERFACE_H_ */
