/*
 * SPI_program.c
 *
 *  Created on: Aug 28, 2021
 *      Author: Radwa
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "avr/delay.h"

#include"DIO_interface.h"
#include"SPI_interface.h"
#include"SPI_reg.h"

void SPI_voidMasterInit(void)
{
	/*MOSI & SCK as o/p & MISO_SS as i/p*/
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_5,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_7,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_6,DIO_u8INPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_4,DIO_u8INPUT);
	/*Pull up for SS to not equal 0*/
	DIO_voidSetPinValue(DIO_u8PORT_B,DIO_u8PIN_4,DIO_u8HIGH);
	/*SPCR*/
	/*Enable or Disable INT*/
	CLR_BIT(SPCR,SPIE);
	/*LSB first*/
	SET_BIT(SPCR,DORD);
	/*MASTER select*/
	SET_BIT(SPCR,MSTR);
	/*Clk polarity % phase*/
	CLR_BIT(SPCR,CPOL);
	SET_BIT(SPCR,CPHA);
	/*Clk Select*/
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPCR,SPR0);
	/*Double Clk*/
	CLR_BIT(SPSR,SPI2X);
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
}

void SPI_voidSlaveInit(void)
{
	/*MOSI & SCK & SS as i/p & MISO as o/p*/
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_5,DIO_u8INPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_7,DIO_u8INPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_6,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_4,DIO_u8INPUT);
	/*LSB first*/
	SET_BIT(SPCR,DORD);
	/*Slave select*/
	CLR_BIT(SPCR,MSTR);
	/*Clk polarity % phase*/
	CLR_BIT(SPCR,CPOL);
	SET_BIT(SPCR,CPHA);
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
}
u8 SPI_voidTransceiverData(u8 Copy_u8Data, u8* ptr)
{
	/*Start Transfer*/
	SPDR = Copy_u8Data;
	if (GET_BIT(SPSR,WCOL)==1)
	{
		*ptr = 0xff;
	}
	/*Wait for Flag as Transfer complete*/
	while (GET_BIT(SPSR,SPIF)==0);
	return SPDR;
}

