/*
 * main.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define F_CPU 8000000
#include "avr/delay.h"
#include"DIO_interface.h"
#include"STEPMOTOR_interface.h"
int main()
{
	DIO_voidSetPortDirection(DIO_u8PORT_A,DIO_u8INPUT);

	 StepMotor_voidInit();

	while(1)
	{
		u8 R=DIO_u8GetPinValue(DIO_u8PORT_A,DIO_u8PIN_0);
		u8 L=DIO_u8GetPinValue(DIO_u8PORT_A,DIO_u8PIN_1);
		u8 RA=DIO_u8GetPinValue(DIO_u8PORT_A,DIO_u8PIN_2);
		u8 LA=DIO_u8GetPinValue(DIO_u8PORT_A,DIO_u8PIN_3);
		u8 S=DIO_u8GetPinValue(DIO_u8PORT_A,DIO_u8PIN_4);
		if((R==1) & (L==0) & (RA==0) & (LA==0) & (S==0))
		{
			StepMotor_RotateRight();
		}
		else if((L==1) & (R==0) & (RA==0) & (LA==0) & (S==0))
		{
			StepMotor_RotateLeft();
		}
		else if((RA==1) & (L==0) & (R==0) & (LA==0) & (S==0))
		{
			StepMotor_RotateRightWithAngle(30);
		}
		else if((LA==1) & (L==0) & (R==0) & (RA==0) & (S==0))
		{
			StepMotor_RotateLeftWithAngle(30);
		}
		else if((S==1) & (L==0) & (RA==0) & (LA==0) & (R==0))
		{
			StepMotor_Stop();
		}
		else
		{
			StepMotor_Stop();
		}
	}
	return 0;

}

