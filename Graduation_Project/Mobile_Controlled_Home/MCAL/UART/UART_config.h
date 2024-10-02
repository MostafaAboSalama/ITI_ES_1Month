/*
 * UART_config.h
 *
 * Created: 1/31/2024 1:32:41 PM
 *  Author: Elmag
 */

#ifndef MCAL_UART_UART_CONFIG_H_
#define MCAL_UART_UART_CONFIG_H_

#define UART_Mode_TX               (u8)(1<<4)
#define UART_Mode_RX               (u8)(1<<3)
#define UART_Mode_TX_AND_RX        (u8)(1<<3 | 1<<4)


//@Ref UART_BaudRate_define
#define UART_BaudRate_2400		2400
#define UART_BaudRate_4800		4800
#define UART_BaudRate_9600		9600
#define UART_BaudRate_14400	    14400
#define UART_BaudRate_19200	    19200
#define UART_BaudRate_28800	    28800
#define UART_BaudRate_14400	    14400
#define UART_BaudRate_38400	    38400
#define UART_BaudRate_57600	    57600
#define UART_BaudRate_76800	    76800

//@Ref UART_data_Size_define
#define UART_data_Size_5B             1
#define UART_data_Size_6B             2
#define UART_data_Size_7B             3
#define UART_data_Size_8B             4
#define UART_data_Size_9B             5

//@Ref UART_StopBits_define
#define UART_StopBits_1            (u8)(0)
#define UART_StopBits_2            (u8)(1<<3)

//@Ref UART_Parity_define
#define UART_Parity_NONE            (u8)(0)
#define UART_Parity_EVEN           (u8)(2<<4)
#define UART_Parity_ODD            (u8)(3<<4)


//@Ref  UART_Speed_Mode_define
#define UART_Speed_Mode_Normal              (u8)(0)
#define UART_Speed_Mode_Double              (u8)(1<<1)

//@Ref UART_IRQ_define
#define  UART_Interrupt_Enable_NONE       (u8)(0)
#define  UART_Interrupt_Enable_TXCIE      (u8)(1<<6)
#define  UART_Interrupt_Enable_RXCIE      (u8)(1<<7)
#define  UART_Interrupt_Enable_UDRIE      (u8)(1<<5)



#endif /* MCAL_UART_UART_CONFIG_H_ */
