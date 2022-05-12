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
#include "avr/delay.h"

int main()
{

	u8 x=0;
		DIO_voidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_0,DIO_u8OUTPUT);
		DIO_voidSetPinValue(DIO_u8PORT_D,DIO_u8PIN_0,DIO_u8LOW);
		SPI_voidSlaveInit();

		while(1)
		{
			u8 Read = SPI_voidTransceiverData(6,&x);
			if (Read == 5)
			{
				DIO_voidSetPinValue(DIO_u8PORT_D,DIO_u8PIN_0,DIO_u8HIGH);
			}
		}
}

