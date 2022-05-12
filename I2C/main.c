/*
 * main.c
 *
 *  Created on: Aug 29, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include"I2C_interface.h"
#include"DIO_interface.h"


int main()
{
	DIO_voidSetPortDirection(DIO_u8PORT_B,DIO_u8OUTPUT);
	I2C_voidSlaveInit(0X06);
	while(1)
	{
		DIO_voidSetPortValue(DIO_u8PORT_B,I2C_u8ReadAck());

	}

}

