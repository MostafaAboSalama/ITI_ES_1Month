/*
 * Atmega32_UART_Driver.h
 *
 * Created: 1/31/2024 1:32:41 PM
 *  Author: Elmag
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_


typedef struct
{
	u8    USART_Mode ; //TX or RX or TX_RX  based on  @Ref UART_Mode_define

	u32   BaudRate ;  // this parameter set based on @Ref UART_BaudRate_define

	u8    data_size ;  // this parameter set based on @Ref UART_data_Size_define

	u8    parity ;	 // this parameter set based on   @Ref UART_Parity_define

	u8    StopBit ;   // this parameter set based on   @Ref UART_StopBits_define

	u8    IRQ_Enable ; // this parameter set based on   @Ref UART_IRQ_define

	u8   Speed_Mode ;  // this parameter set based on   @Ref  UART_Speed_Mode_define

	void(* P_IRQ_CallBack)(void); // Set the C Function() which will be called once the IRQ Happen

}UART_config;


typedef struct
{
	u8  _UBRRL ;
	u8  _UCSRB ;
	u8  _UCSRA ;
	u8  _UDR ;
    u64 _reserved0;
	u64 _reserved1;
	u16 _reserved2;
	u8  _reserved3;
 union RC_RH
	{
		u8  _UCSRC ;
		u8  _UBRRH ;
	}RC_RH;

}UART_TypeDef_t;

//=====================Macros=====================

// @Ref UART_Mode_define
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

//BaudRate
#define BAUD(_Fose_ ,_BAUD_ ,_Frac_)                (u32)(((_Fose_/_BAUD_)/_Frac_)-1)

void   MCAL_UART_init(UART_TypeDef_t *UARTx , UART_config *UART_cfg);
void   MCAL_UART_Send(u8 data);
u8  MCAL_UART_Receive(void) ;
void   MCAL_UART_SndNumberU32(u32 NUM);
u32 MCAL_UART_ReceiveNumberU32(void);
void   MCAL_UART_Send_Str(u8 *str);
void   MCAL_UART_Receive_Str(u8 *str);
u8  MCAL_UART_Receive_perodicCheck( u8 *data);
void   MCAL_UART_SendNoBlock(u8 data);
u8  MCAL_UART_ReceiveNoBlock(void);
void   MCAL_UART_SendString_Asynch(u8 * str);
#endif /* ATMEGA32_UART_DRIVER_H_ */


