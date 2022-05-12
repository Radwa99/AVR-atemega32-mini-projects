/*
 * UART_reg.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Radwa
 */

#ifndef UART_REG_H_
#define UART_REG_H_

/*For Tx or Rx*/
#define UDR     *((volatile u8*)0x2C)

/*For Flags*/
#define UCSRA   *((volatile u8*)0x2B)
/*Rx & Tx complete*/
#define RXC     7
#define TXC     6
/*UDR empty to write on it*/
#define UDRE    5
/*Frame error*/
#define FE      4
/*Data over run*/
#define DOR     3
/*Parity Error*/
#define PE      2
/*Douple Speed*/
#define U2X     1
/*Multiprocessor*/
#define MPCM    0

/*For INT*/
#define UCSRB   *((volatile u8*)0x2A)
/*Complete INT Enable*/
#define RXCIE     7
#define TXCIE     6
/*Reg Empty INT enable*/
#define UDRIE     5
/*TX & RX enable*/
#define RXEN      4
#define TXEN      3
/*For Char size*/
#define UCSZ2    2
/*For 9th bit*/
#define RXB0     1
#define TXB0     0


#define UCSRC   *((volatile u8*)0x40)
/*Choose UCSRC or UBRRH*/
#define URSEL    7
/*Mode Select Asynch or Synch*/
#define UMSEL    6
/*Parity Mode*/
#define UPM1     5
#define UPM0     4
/*Choose Stop*/
#define USBS     3
/*For char size : 8 or 9 or ....*/
#define UCSZ1    2
#define UCSZ0    1
/*Clk polarity if synch*/
#define UCPOL    0

/*For Boud Rate*/
#define UBRRH   *((volatile u8*)0x40)
#define UBRRL   *((volatile u8*)0x29)


#endif /* UART_REG_H_ */
