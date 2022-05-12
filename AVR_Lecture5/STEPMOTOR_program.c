/*
 * program.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define F_CPU 8000000
#include "avr/delay.h"

#include"STEPMOTOR_config.h"
#include"DIO_interface.h"
#include"STEPMOTOR_interface.h"

void StepMotor_voidInit(void)
{
	DIO_voidSetPinDirection(STEPMOTOR_PORT,STEPMOTOR_PIN0,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(STEPMOTOR_PORT,STEPMOTOR_PIN1,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(STEPMOTOR_PORT,STEPMOTOR_PIN2,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(STEPMOTOR_PORT,STEPMOTOR_PIN3,DIO_u8OUTPUT);

}


void StepMotor_RotateRight()
{
	DIO_voidSetPinValue(STEPMOTOR_PORT,STEPMOTOR_PIN0,DIO_u8HIGH);
	_delay_ms(50);
	DIO_voidSetPinValue(STEPMOTOR_PORT,STEPMOTOR_PIN1,DIO_u8LOW);
	_delay_ms(50);
	DIO_voidSetPinValue(STEPMOTOR_PORT,STEPMOTOR_PIN2,DIO_u8LOW);
	_delay_ms(50);
	DIO_voidSetPinValue(STEPMOTOR_PORT,STEPMOTOR_PIN3,DIO_u8LOW);
	_delay_ms(50);
}

void StepMotor_RotateLeft()
{
	DIO_voidSetPinValue(STEPMOTOR_PORT,STEPMOTOR_PIN0,DIO_u8LOW);
	_delay_ms(50);
	DIO_voidSetPinValue(STEPMOTOR_PORT,STEPMOTOR_PIN1,DIO_u8LOW);
	_delay_ms(50);
	DIO_voidSetPinValue(STEPMOTOR_PORT,STEPMOTOR_PIN2,DIO_u8LOW);
	_delay_ms(50);
	DIO_voidSetPinValue(STEPMOTOR_PORT,STEPMOTOR_PIN3,DIO_u8HIGH);
	_delay_ms(50);

}

void StepMotor_RotateRightWithAngle(u8 Copy_u8Angle)
{

	u8 Local_Copy_u8NumSteps= (Copy_u8Angle/STEPMOTOR_FULLSTEP)/NUMBER_ULN_PINS;
	u8 Local_u8Stepcounter;
	for(Local_u8Stepcounter=0;Local_u8Stepcounter<Local_Copy_u8NumSteps;Local_u8Stepcounter++)
	{
		StepMotor_RotateRight();
	}
}

void StepMotor_RotateLeftWithAngle(u8 Copy_u8Angle)
{

	u8 Local_Copy_u8NumSteps= (Copy_u8Angle/STEPMOTOR_FULLSTEP)/NUMBER_ULN_PINS;
	u8 Local_u8Stepcounter;
	for(Local_u8Stepcounter=0;Local_u8Stepcounter<Local_Copy_u8NumSteps;Local_u8Stepcounter++)
	{
		StepMotor_RotateLeft();
	}
}

void StepMotor_Stop()
{
	DIO_voidSetPinValue(STEPMOTOR_PORT,STEPMOTOR_PIN0,DIO_u8LOW);
	_delay_ms(50);
	DIO_voidSetPinValue(STEPMOTOR_PORT,STEPMOTOR_PIN1,DIO_u8LOW);
	_delay_ms(50);
	DIO_voidSetPinValue(STEPMOTOR_PORT,STEPMOTOR_PIN2,DIO_u8LOW);
	_delay_ms(50);
	DIO_voidSetPinValue(STEPMOTOR_PORT,STEPMOTOR_PIN3,DIO_u8LOW);
	_delay_ms(50);

}

