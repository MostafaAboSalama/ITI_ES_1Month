/*
 * Bluetooth_interface.h
 *
 *  Created on: Aug 16, 2024
 *      Author: Elmag
 */

#ifndef HAL_BLUETOOTH_BLUETOOTH_INTERFACE_H_
#define HAL_BLUETOOTH_BLUETOOTH_INTERFACE_H_

void Bluetooth_Init(void);
void Bluetooth_SendData(u8 data);
u8 Bluetooth_RecieveData();

#endif /* HAL_BLUETOOTH_BLUETOOTH_INTERFACE_H_ */
