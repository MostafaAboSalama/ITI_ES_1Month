/*
 * EXTI_private.h
 *
 *  Created on: Jul 30, 2024
 *      Author: Mohammed Mansour
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_


/* EXTI registers */
#define MCUCR_Register	 	*((volatile u8 *) 0x55)
#define MCUCSR_Register 	*((volatile u8 *) 0x54)
#define GICR_Register		*((volatile u8 *) 0x5B)
#define GIFR_Register		*((volatile u8 *) 0x5A)

/* MCUCR register bits */
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

/* MCUCSR register bits */
#define ISC2	6

/* GICR register bits */
#define INT2	5
#define INT0	6
#define INT1	7

/* GIFR register bits */
#define INTF2	5
#define INTF0	6
#define INTF1	7

void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
