/*
 * EXTI_program.c
 *
 *  Created on: Aug 18, 2021
 *      Author: Radwa
 */

#ifndef EXTI_PROGRAM_C_
#define EXTI_PROGRAM_C_

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include"DIO_interface.h"
#include"EXTI_interface.h"
#include"EXTI_reg.h"


u8 EXTI0_voidInit(u8 Copy_u8SenseLevel)
{
	u8 Local_u8Return= OK;
	/*1:Set Direction pin...>input*/
		DIO_voidSetPinDirection(EXTI_INT0_PORT,EXTI_INT0_PIN,DIO_u8INPUT);

	/*2:Enable pull_up Resistor*/
		DIO_voidSetPinValue(EXTI_INT0_PORT,EXTI_INT0_PIN,DIO_u8HIGH);

	/*3:Enable PIE of INT0*/
		SET_BIT(GICR,GICR_INT0);

	/*4:Enable global interrupt*/
		SET_BIT(SREG,SREG_I);

	/*5:choose sense level*/
		switch(Copy_u8SenseLevel)
		{
		case EXTI_LOWLEVEL: CLR_BIT(MCUCR,MCUCR_IS00);
		                    CLR_BIT(MCUCR,MCUCR_IS01);
		                    break;

		case EXTI_RISINGEDGE:SET_BIT(MCUCR,MCUCR_IS00);
                             SET_BIT(MCUCR,MCUCR_IS01);
                             break;

		case EXTI_FALLINGEDGE:CLR_BIT(MCUCR,MCUCR_IS00);
                              SET_BIT(MCUCR,MCUCR_IS01);
                              break;

		case EXTI_ONCHANGE:SET_BIT(MCUCR,MCUCR_IS00);
                           CLR_BIT(MCUCR,MCUCR_IS01);
                           break;

		default: Local_u8Return=NOTOK;
		         break;
		}
		return Local_u8Return;
}


u8 EXTI1_voidInit(u8 Copy_u8SenseLevel)
{
	u8 Local_u8Return= OK;
	/*1:Set Direction pin...>input*/
		DIO_voidSetPinDirection(EXTI_INT1_PORT,EXTI_INT1_PIN,DIO_u8INPUT);

	/*2:Enable pull_up Resistor*/
		DIO_voidSetPinValue(EXTI_INT1_PORT,EXTI_INT1_PIN,DIO_u8HIGH);

	/*3:Enable PIE of INT1*/
		SET_BIT(GICR,GICR_INT1);

	/*4:Enable global interrupt*/
		SET_BIT(SREG,SREG_I);

	/*5:choose sense level*/
		switch(Copy_u8SenseLevel)
		{
		case EXTI_LOWLEVEL: CLR_BIT(MCUCR,MCUCR_IS10);
		                    CLR_BIT(MCUCR,MCUCR_IS11);
		                    break;

		case EXTI_RISINGEDGE:SET_BIT(MCUCR,MCUCR_IS10);
                             SET_BIT(MCUCR,MCUCR_IS11);
                             break;

		case EXTI_FALLINGEDGE:CLR_BIT(MCUCR,MCUCR_IS10);
                              SET_BIT(MCUCR,MCUCR_IS11);
                              break;

		case EXTI_ONCHANGE:SET_BIT(MCUCR,MCUCR_IS10);
                           CLR_BIT(MCUCR,MCUCR_IS11);
                           break;

		default: Local_u8Return=NOTOK;
		         break;
		}
		return Local_u8Return;
}

u8 EXTI2_voidInit(u8 Copy_u8SenseLevel)
{
	u8 Local_u8Return= OK;
	/*1:Set Direction pin...>input*/
		DIO_voidSetPinDirection(EXTI_INT2_PORT,EXTI_INT2_PIN,DIO_u8INPUT);

	/*2:Enable pull_up Resistor*/
		DIO_voidSetPinValue(EXTI_INT2_PORT,EXTI_INT2_PIN,DIO_u8HIGH);

	/*3:Enable PIE of INT2*/
		SET_BIT(GICR,GICR_INT2);

	/*4:Enable global interrupt*/
		SET_BIT(SREG,SREG_I);

	/*5:choose sense level*/
		switch(Copy_u8SenseLevel)
		{
		case EXTI_RISINGEDGE:SET_BIT(MCUCSR,MCUCSR_ISC2);
                             break;

		case EXTI_FALLINGEDGE:CLR_BIT(MCUCSR,MCUCSR_ISC2 );
                              break;


		default: Local_u8Return=NOTOK;
		         break;
		}
		return Local_u8Return;
}



#endif /* EXTI_PROGRAM_C_ */
