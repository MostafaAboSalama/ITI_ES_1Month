/*
 * SS_interface.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Mohammed Mansour
 */

#ifndef SEVENSEGMENT_SS_INTERFACE_H_
#define SEVENSEGMENT_SS_INTERFACE_H_

#define SEVEN_SEGMENT_UNIT1		0

void SevenSegment_voidInit();
void SevenSegment_voidSetValue(u8 L_u8UnitNo, u8 L_u8Value);
void SevenSegment_voidClear(u8 L_u8UnitNo);


#endif /* SEVENSEGMENT_SS_INTERFACE_H_ */
