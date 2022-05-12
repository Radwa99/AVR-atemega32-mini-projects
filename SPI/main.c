/*
 * main2.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "avr/delay.h"
#include"DIO_interface.h"
#include "SPI_interface.h"


int main()
{

	u8 x =0;
		DIO_voidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_0,DIO_u8OUTPUT);
		DIO_voidSetPinValue(DIO_u8PORT_D,DIO_u8PIN_0,DIO_u8LOW);
		DIO_voidSetPinDirection(DIO_u8PORT_C,DIO_u8PIN_0,DIO_u8OUTPUT);
		SPI_voidMasterInit();
		while(1)
		{

			SPI_voidTransceiverData(5,&x);
			if (x==0xff)
			{
				DIO_voidSetPinValue(DIO_u8PORT_C,DIO_u8PIN_0,DIO_u8HIGH);
			}
			_delay_ms(500);
		}
}

