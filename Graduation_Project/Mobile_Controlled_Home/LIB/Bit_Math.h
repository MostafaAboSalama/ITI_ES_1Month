/*
 * Bit_Math.h
 *
 *  Created on: Jul 25, 2024
 *      Author: Mohammed Mansour
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(port, pin_no) (port |= (1 << (pin_no)))
#define CLEAR_BIT(port, pin_no) (port &= ~(1 << (pin_no)))
#define GET_BIT(port, pin_no) ((port>>pin_no)&1)


#endif /* BIT_MATH_H_ */
