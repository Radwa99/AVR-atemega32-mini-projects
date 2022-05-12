/*
 * main.c
 *
 *  Created on: Aug 19, 2021
 *      Author: Radwa
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include"DIO_interface.h"
#include"ADC_interface.h"


int main()
{

	ADC_voidInit();

	while(1)
	{


		ADC_voidRead(0);	/* Read ADC channel 0 */
	}
	return 0;
}
