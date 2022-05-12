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
#include"avr\delay.h"

int main()
{
	I2C_voidMasterInit();
	I2C_u8StartCondition(0x06);
	while(1)
	{
		I2C_u8WriteData(0x01);
		_delay_ms(100);
		I2C_u8WriteData(0x02);
		_delay_ms(100);
		I2C_u8WriteData(0x03);
		_delay_ms(100);
	}

}

