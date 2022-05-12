/*
 * main2.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define F_CPU 8000000
#include "avr/delay.h"

#include"DIO_interface.h"

int main()
{
	DIO_voidSetPortDirection(DIO_u8PORT_A,DIO_u8INPUT);
	u8 x = DIO_u8GetPinValue(DIO_u8PORT_A,DIO_u8PIN_0);

	DIO_voidSetPortDirection(DIO_u8PORT_C,DIO_u8OUTPUT);
	DIO_voidSetPortValue(DIO_u8PORT_C,DIO_u8LOW);

	while(1)
	{
      if(x== 1)
      {
		DIO_voidSetPortValue(DIO_u8PORT_C,DIO_u8HIGH);
		_delay_ms(500);
		DIO_voidSetPortValue(DIO_u8PORT_C,DIO_u8LOW);
      }
      else if(x== 0)
	  {
    	DIO_voidSetPortValue(DIO_u8PORT_C,DIO_u8LOW);
	  }

	}
	return 0;
}

