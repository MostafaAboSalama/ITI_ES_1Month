/*
 * UART_program.c
 *
 *  Created on: Jul 30, 2024
 *      Author: Mostafa AboSalama
 */

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#include "UART_private.h"
#include "UART_config.h"
#include "UART_interface.h"

void UART_voidInit(void)
{
    /* MODE */
    #if UART_MODE == UART_MODE_ASYNC
        CLR_BIT(UCSRC, UMSEL);
    #else
        SET_BIT(UCSRC, UMSEL);
    #endif

    /* PARITY */
    #if UART_PARITY == UART_PARITY_DISABLED
        CLR_BIT(UCSRC, UPM0); CLR_BIT(UCSRC, UPM1);
    #elif UART_PARITY == UART_PARITY_EVEN
        CLR_BIT(UCSRC, UPM0); SET_BIT(UCSRC, UPM1);
    #else
        SET_BIT(UCSRC, UPM0); SET_BIT(UCSRC, UPM1);
    #endif

    /* STOP BITS */
    #if UART_STOPBITS == UART_STOPBITS_1
        CLR_BIT(UCSRC, USBS);
    #else
        SET_BIT(UCSRC, USBS);
    #endif

    /* CHAR SIZE */
    #if UART_CHAR_SIZE == UART_CHAR_SIZE_5
        CLR_BIT(UCSRB, UCSZ2); CLR_BIT(UCSRC, UCSZ1); CLR_BIT(UCSRC, UCSZ0);
    #elif UART_CHAR_SIZE == UART_CHAR_SIZE_6
        CLR_BIT(UCSRB, UCSZ2); CLR_BIT(UCSRC, UCSZ1); SET_BIT(UCSRC, UCSZ0);
    #elif UART_CHAR_SIZE == UART_CHAR_SIZE_7
        CLR_BIT(UCSRB, UCSZ2); SET_BIT(UCSRC, UCSZ1); CLR_BIT(UCSRC, UCSZ0);
    #elif UART_CHAR_SIZE == UART_CHAR_SIZE_8
        CLR_BIT(UCSRB, UCSZ2); SET_BIT(UCSRC, UCSZ1); SET_BIT(UCSRC, UCSZ0);
    #elif UART_CHAR_SIZE == UART_CHAR_SIZE_9
        SET_BIT(UCSRB, UCSZ2); SET_BIT(UCSRC, UCSZ1); SET_BIT(UCSRC, UCSZ0);
    #endif

    /* BAUD RATE */
    UBRRL = (u8)(UART_BAUDRATE);
    UBRRH = (u8)((UART_BAUDRATE >> 8) & 0x7F);  // Make sure URSEL is clear

    /* Enable TX, RX */
    SET_BIT(UCSRB, TXEN);
    SET_BIT(UCSRB, RXEN);
}

void UART_voidSendByte(u8 data)
{
    while(GET_BIT(UCSRA, UDRE) == 0);  // Wait until UDR is ready
    UDR = data;
}

u8 UART_u8RecieveByte(void)
{
    while(GET_BIT(UCSRA, RXC) == 0);  // Wait until data is received
    return UDR;
}

void UART_voidDisable(void)
{
    CLR_BIT(UCSRB, TXEN);
    CLR_BIT(UCSRB, RXEN);
}
