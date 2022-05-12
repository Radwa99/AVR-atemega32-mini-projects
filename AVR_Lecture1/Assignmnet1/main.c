/*
 * main.c
 *
 *  Created on: Aug 11, 2021
 *      Author: Radwa
 */
#include<avr/io.h>
#define F_CPU 8000000
#include "avr/delay.h"

int main()
{
	DDRA=0xff;
	while(1)
	{
		PORTA=0b00000001;    //GREEN
		_delay_ms(10000);
		PORTA=0b00000010;    //YELLOW
		_delay_ms(3000);
		PORTA=0b00000100;    //RED
		_delay_ms(10000);
	}
	return 0;
}

