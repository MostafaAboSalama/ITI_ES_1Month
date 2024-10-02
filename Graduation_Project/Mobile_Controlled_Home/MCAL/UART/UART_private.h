/*
 * UART_private.h
 *
 * Created: 1/31/2024 1:32:41 PM
 *  Author: Elmag
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

//UART
#define UART_BASE           0x29UL

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: UART
//-*-*-*-*-*-*-*-*-*-*-*-
//==============================================================


#define UART1         ((UART_TypeDef_t*)UART_BASE)

/* analog comparator */
#define ACSR    _SFR_IO8(0x08)

/* USART */
#define UBRRH   *((volatile u8*) 0x40)
#define UBRRL   *((volatile u8*) 0x29)
#define UCSRC   *((volatile u8*) 0x40)
#define UCSRB   *((volatile u8*) 0x2A)
#define UCSRA   *((volatile u8*) 0x2B)
#define UDR     *((volatile u8*) 0x2C)

/* UCSRA */
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0

/* UCSRB */
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

/* UCSRC */
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0

#endif /* MCAL_UART_UART_PRIVATE_H_ */
