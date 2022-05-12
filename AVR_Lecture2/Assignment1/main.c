/*
 * main.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define F_CPU 8000000
#include "avr/delay.h"

#include"DIO_interface.h"

int main()
{
	u8 i;
	DIO_voidSetPortDirection(DIO_u8PORT_A,DIO_u8OUTPUT);

	while(1)
	{
		DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_1,DIO_u8HIGH);
		DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_2,DIO_u8LOW);
		DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_3,DIO_u8LOW);
		for(i=0;i<10;i++) {_delay_ms(1000);}


		DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_1,DIO_u8LOW);
		DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_2,DIO_u8HIGH);
		DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_3,DIO_u8LOW);
		for(i=0;i<3;i++) {_delay_ms(1000);}

		DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_1,DIO_u8LOW);
		DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_2,DIO_u8LOW);
		DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_3,DIO_u8HIGH);
		for(i=0;i<10;i++) {_delay_ms(1000);}
	}
	return 0;

}

