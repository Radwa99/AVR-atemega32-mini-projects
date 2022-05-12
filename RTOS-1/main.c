/*
 * main.c
 *
 *  Created on: Sep 1, 2021
 *      Author: Radwa
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include"GINT_interface.h"
#include "TIMER_interface.h"
#include "RTOS_interface.h"


void LED1toggle(void);
void LED2toggle(void);
void LED3toggle(void);

int main()
{
	DIO_voidSetPortDirection(DIO_u8PORT_A,DIO_u8PORTOUTPUT);
	RTOSCreateTask(0,1000,LED1toggle);
	RTOSCreateTask(1,2000,LED2toggle);
	RTOSCreateTask(2,3000,LED3toggle);

	RTOSStart();

	while(1)
	{

	}
}

void LED1toggle(void)
{
	DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_0,!(DIO_u8GetPin(DIO_u8PORT_A,DIO_u8PIN_0)));
}

void LED2toggle(void)
{
	DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_1,!(DIO_u8GetPin(DIO_u8PORT_A,DIO_u8PIN_1)));
}

void LED3toggle(void)
{
	DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_2,!(DIO_u8GetPin(DIO_u8PORT_A,DIO_u8PIN_2)));
}
