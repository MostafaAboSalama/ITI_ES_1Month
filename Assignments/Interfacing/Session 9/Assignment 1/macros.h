/*
 * macros.h
 *
 *  Created on: Jul 26, 2024
 *      Author: user
 */

#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define GET_BIT(reg,bit)    (reg&(1<<bit))>>bit

#endif /* MACROS_H_ */
