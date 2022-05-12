/*
 * I2C_interface.h
 *
 *  Created on: Aug 29, 2021
 *      Author: Radwa
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

void I2C_voidMasterInit(void);
void I2C_voidSlaveInit(u8 SlaveAddress);
u8 I2C_u8StartCondition(u8 write_address);
void I2C_voidWriteSLA(u8 SlaveAddress);
u8 I2C_u8WriteData(u8 data);
void I2C_voidStop(void);
u8 I2C_u8ReadAck(void);

#endif /* I2C_INTERFACE_H_ */
