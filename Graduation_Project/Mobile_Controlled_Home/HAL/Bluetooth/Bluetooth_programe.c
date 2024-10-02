/*
 * Bluetooth_programe.c
 *
 *  Created on: Aug 16, 2024
 *      Author: Elmag
 */

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "../../MCAL/UART/UART_interface.h"

#include "Bluetooth_interface.h"
#include "Bluetooth_private.h"


void Bluetooth_Init(void)
{
	UART_config UART_CFG ;
	UART_CFG.BaudRate  = UART_BaudRate_9600 ;
	UART_CFG.data_size = UART_data_Size_8B ;
	UART_CFG.IRQ_Enable= UART_Interrupt_Enable_NONE ;
	UART_CFG.P_IRQ_CallBack = NULL ;
	UART_CFG.parity =UART_Parity_NONE ;
	UART_CFG.Speed_Mode = UART_Speed_Mode_Normal ;
	UART_CFG.StopBit = UART_StopBits_1 ;
	UART_CFG.USART_Mode = UART_Mode_TX_AND_RX ;
    MCAL_UART_init(UART1 , &UART_CFG);

}
void Bluetooth_SendData(u8 data)
{
	MCAL_UART_Send(data);
}
u8 Bluetooth_RecieveData()
{
	return MCAL_UART_Receive();
}

