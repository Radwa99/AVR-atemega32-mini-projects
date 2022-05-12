/*
 * main.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Radwa
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "DIO_Interface.h"
#include "UART_Interface.h"

int main()
{
	u8 Rec;
	/*For RX*/
	DIO_voidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_0,DIO_u8INPUT);
	/*For TX*/
	DIO_voidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_1,DIO_u8OUTPUT);
	/*For led*/
	DIO_voidSetPinDirection(DIO_u8PORT_C,DIO_u8PIN_0,DIO_u8OUTPUT);
	UART_voidInit();
	while(1)
	{
		Rec = UART_voidRX();
		if (Rec == 'H')
		{
			DIO_voidSetPinValue(DIO_u8PORT_C,DIO_u8PIN_0,DIO_u8HIGH);
			UART_voidTX('H');
		}
		else if (Rec == 'L')
		{
			DIO_voidSetPinValue(DIO_u8PORT_C,DIO_u8PIN_0,DIO_u8LOW);
			UART_voidTX('L');
		}

	}


}
