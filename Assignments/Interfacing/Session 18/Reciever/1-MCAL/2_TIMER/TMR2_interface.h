/*
 * TMR2_interface.h
 *
 *  Created on: Aug 3, 2024
 *      Author: user
 */

#ifndef TMR2_INTERFACE_H_
#define TMR2_INTERFACE_H_

void TMR2_voidInitCTC(void);

void TMR2_voidSetCTC(u8 time);

void TMR2_voidSetCallBackCTC(void (*pf)(void));

#endif /* TMR2_INTERFACE_H_ */
