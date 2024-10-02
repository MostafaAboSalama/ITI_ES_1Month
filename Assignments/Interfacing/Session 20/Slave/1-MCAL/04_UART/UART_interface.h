#ifndef  UART_INTERFACE_H_
#define  UART_INTERFACE_H_


#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

		/* MODE*/
#define UART_MODE_ASYNC		0
#define UART_MODE_SYNC		1

		/* PARITY */
#define UART_PARITY_DISABLED	0
#define UART_PARITY_EVEN		2
#define UART_PARITY_ODD			3

		/* STOP BITS */
#define UART_STOPBITS_1			0
#define UART_STOPBITS_2			1

		/* CHAR SIZE */
#define	UART_CHAR_SIZE_5		0
#define	UART_CHAR_SIZE_6		1
#define	UART_CHAR_SIZE_7		2
#define	UART_CHAR_SIZE_8		3
#define	UART_CHAR_SIZE_9		7

		/* BAUDRATE*/
#define	UART_BAUDRATE_2400		207
#define	UART_BAUDRATE_4800		103
#define	UART_BAUDRATE_9600		51
#define	UART_BAUDRATE_14400		34

		/* FUNCTIONS */

void UART_voidInit(void);

void UART_voidSendByte(u8 data);

u8 UART_u8RecieveByte(void);

void UART_voidDisable(void);

#endif /*UART_INTERFACE_H_*/
