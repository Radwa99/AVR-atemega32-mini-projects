/*
 * SPI_reg.h
 *
 *  Created on: Aug 28, 2021
 *      Author: Radwa
 */

#ifndef SPI_REG_H_
#define SPI_REG_H_

/*Data Tx and Rx*/
#define SPDR  *((volatile u8*)0x2F)

/*Status Reg*/
#define SPSR  *((volatile u8*)0x2E)
/*SPI INT Flag*/
#define SPIF   7
/*Write COLision Flag*/
#define WCOL   6
/*Double SPI Speed*/
#define SPI2X  0



#define SPCR  *((volatile u8*)0x2D)
/*INT enable*/
#define SPIE   7
/*SPI enable*/
#define SPE    6
/*Data ordor */
#define DORD   5
/*Maste/Slave Select*/
#define MSTR   4
/*Clk polarity*/
#define CPOL   3
/*Clk phase*/
#define CPHA   2
/*Clk rate select*/
#define SPR1   2
#define SPR0   1


#endif /* SPI_REG_H_ */
