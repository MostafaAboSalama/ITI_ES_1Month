#ifndef  I2C_INTERFACE_H_
#define  I2C_INTERFACE_H_


#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"

#define I2C_READ_OPERATION  0b1
#define I2C_WRITE_OPERATION 0b0

#define I2C_STATE_STA          0x08
#define I2C_START_ADDRESS_ACK  0x18
#define I2C_START_DATA_ACK     0x28

#define MASTER 0
#define SLAVE  1
void I2C_voidInitMaster(u32 Copy_u32BitRate);
void I2C_voidInitSlave(void);
u8 I2C_u8SendStart(void);
u8 I2C_u8SendAddress(u8 Copy_u8address ,u8 Copy_u8Operation);
u8 I2C_u8SendData(u8 Copy_u8data);
u8 I2C_u8SendStop(void);
u8 I2C_u8Recive_With_ACK(void);
u8 I2C_u8Recive_Without_ACK(void);
u8 I2C_u8SendFrame(u8 Copy_u8Address , u8 *Copy_pu8Buffer , u8 Copy_u8Length);
u8 I2C_u8RepeatStart(void);

#endif /*I2C_INTERFACE_H_*/
