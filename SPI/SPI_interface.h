/*
 * SPI_interface.h
 *
 *  Created on: Aug 28, 2021
 *      Author: Radwa
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
u8 SPI_voidTransceiverData(u8 Copy_u8Data, u8* ptr);

#endif /* SPI_INTERFACE_H_ */
