/*
 * ICU_interface.h
 *
 *  Created on: Aug 6, 2024
 *      Author: Mohammed Mansour
 */

#ifndef ICU_ICU_INTERFACE_H_
#define ICU_ICU_INTERFACE_H_

void ICU_Init(void);
u16 ICU_GetOnTimeUs(void);
u16 ICU_GetPeriodUs(void);
u8 ICU_GetDutyCycle(void);

#endif /* ICU_ICU_INTERFACE_H_ */
