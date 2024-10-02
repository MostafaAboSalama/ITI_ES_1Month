/*
 * I2C_interface.h
 *
 *  Created on: Aug 11, 2024
 *      Author: Elmag
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_

#define I2C_READ_OPP   0b01
#define I2C_WRITE_OPP  0b00

#define I2C_STAT_STA  0X08
#define I2C_STAT_REP_STA  0X10

#define I2C_STAT_ADDRESS_ACK  0X18
#define I2C_STAT_DATA_ACK      0X28

void I2C_InitMaster(u16 SCL_Clock);
void I2C_InitSlave(void);
u8 I2C_SendStart(void);
u8 I2C_SendRepStart(void);
u8 I2C_SendAddress(u8 address , u8 opp);
u8 I2C_SendData(u8 data);
u8 I2C_SendStop(void);
u8 I2C_ReceiveWithAck(void);
u8 I2C_ReceiveWithoutAck(void);
u8 I2C_SendFram(u8 address , u8*buf , u8 len);
#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
