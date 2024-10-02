/*
 * ICU_private.h
 *
 *  Created on: Aug 6, 2024
 *      Author: Mohammed Mansour
 */

#ifndef ICU_ICU_PRIVATE_H_
#define ICU_ICU_PRIVATE_H_

#define ICU_STATE_WAIT_FOR_RISINGEDGE1	0
#define ICU_STATE_WAIT_FOR_FALLINGEDGE	1
#define ICU_STATE_WAIT_FOR_RISINGEDGE2	2

void EXTI_Callback(void);
static volatile u16 t_on = 0;
static volatile u16 period = 0;

#endif /* ICU_ICU_PRIVATE_H_ */
