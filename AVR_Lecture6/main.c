/*
 * main.c
 *
 *  Created on: Aug 18, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define F_CPU 8000000
#include "avr/delay.h"

#include"DIO_interface.h"
#include"EXTI_interface.h"

int main()
{

	DIO_voidSetPinDirection(DIO_u8PORT_A,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_A,DIO_u8PIN_1,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_A,DIO_u8PIN_2,DIO_u8OUTPUT);
	EXTI0_voidInit(EXTI_FALLINGEDGE);
	EXTI1_voidInit(EXTI_FALLINGEDGE);
	EXTI2_voidInit(EXTI_FALLINGEDGE);
	while(1)
	{

	}
}

void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
  static u8 SW1=0;
	if(SW1==0)
	{
	   DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_0,DIO_u8HIGH);
	   (SW1)++;
	}
	else
	{
		DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_0,DIO_u8LOW);
		SW1=0;
	}
}

void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
  static u8 SW2=0;
	if(SW2==0)
	{
	   DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_1,DIO_u8HIGH);
	   (SW2)++;
	}
	else
	{
		DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_1,DIO_u8LOW);
		SW2=0;
	}
}

void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
  static u8 SW3=0;
	if(SW3==0)
	{
	   DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_2,DIO_u8HIGH);
	   (SW3)++;
	}
	else
	{
		DIO_voidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_2,DIO_u8LOW);
		SW3=0;
	}
}
