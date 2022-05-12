/*
 * TIMER_program.c


 *
 *  Created on: Aug 29, 2021
 *      Author: Radwa
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "DIO_interface.h"

#include "TIMER_config.h"
#include "TIMER_interface.h"
#include "TIMER_reg.h"

#include "GINT_interface.h"
#include "avr/delay.h"
#define NULL (void*)0

void (*PvFunc)(void) = NULL;
u16 OVTIME_MICROSEC =0;
u32 counting=0;

u8 TIMER_voidInit(void)
{
	u8 Local_u8Return = OK;

#if TIMER_MODE == TIMER_NORMALMODE
	/*Normal Mode*/
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	/*NORMAL INT enable*/
	SET_BIT(TIMSK,TOIE0);
#elif TIMER_MODE == TIMER_CTCMODE
	/*CTC Mode*/
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*CTC INT enable*/
	SET_BIT(TIMSK,OCIE0);
	OCR0 = 250;
	/*OC0 as output*/
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_3,DIO_u8OUTPUT);
	if (CTC_OC0PIN_MODE == CTC_OC0_TOGGLE)
	{
		CLR_BIT(TCCR0,COM01);
		SET_BIT(TCCR0,COM00);
	}
	else if (CTC_OC0PIN_MODE == CTC_OC0_CLR)
	{
		SET_BIT(TCCR0,COM01);
		CLR_BIT(TCCR0,COM00);
	}
	else if (CTC_OC0PIN_MODE == CTC_OC0_SET)
	{
		SET_BIT(TCCR0,COM01);
		SET_BIT(TCCR0,COM00);
	}
	else
	{
		Local_u8Return = NOK;
	}
#elif TIMER_MODE == TIMER_PWMMODE
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*OC0 as output*/
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_3,DIO_u8OUTPUT);
	if (PWM_OC0PIN_MODE == PWM_OC0_CLRONCMPMATCH)
	{
		SET_BIT(TCCR0,COM01);
		CLR_BIT(TCCR0,COM00);
	}
	else if (PWM_OC0PIN_MODE == PWM_OC0_SETONCMPMATCH)
	{
		SET_BIT(TCCR0,COM01);
		SET_BIT(TCCR0,COM00);
	}
	else
	{
		Local_u8Return = NOK;
	}
#else
	Local_u8Return = NOK;
#endif

#if CLK_PRESCALER == CLK_NOPRE
	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
	OVTIME_MICROSEC = 256 * (CLK_NOPRE/8);
#elif CLK_PRESCALER == CLK_DIV8
	CLR_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
	OVTIME_MICROSEC = 256 * (CLK_DIV8/8);
#elif CLK_PRESCALER == CLK_DIV64
	CLR_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
	OVTIME_MICROSEC = 256 * (CLK_DIV64/8);
#elif CLK_PRESCALER == CLK_DIV256
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
	OVTIME_MICROSEC = 256 * (CLK_DIV256/8);
#elif CLK_PRESCALER == CLK_DIV1024
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
	OVTIME_MICROSEC = 256 * (CLK_DIV1024/8);
#else
	Local_u8Return = NOK;
#endif

	return Local_u8Return;

}

void Timer0_voidSetCompaerMatch(u8 Copy_u8Counter)
{
	OCR0 = Copy_u8Counter;
}

void PreLoad(void)
{
	TCNT0 = 265 - (265*.25);
}


void TIMER_voidSendCallBack(void(*Copy_PtrtoFunc)(void))
{
	if (Copy_PtrtoFunc!=NULL)
	{
		PvFunc=Copy_PtrtoFunc;
	}

}

void __vector_11(void)
{

	static u16 counter = 0;
	counter ++;
	if (counter == 3907)
	{
		if (PvFunc!=NULL)
		{
			PvFunc();
		}
		PreLoad();
		counter =0;
	}


}
void __vector_10(void)
{

	static u16 counter = 0;
	counter ++;
	if (counter == 4000)
	{
		if (PvFunc!=NULL)
		{
			PvFunc();
		}
		counter =0;
	}


}

/*--------------------Timer 1 ------------------------*/
void TIMER1_voidInit(void)
{
	/*Wave form generation : Normal*/
	CLR_BIT(TCCR1B,WGM13);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);
	/*CLK selection*/
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1A,CS10);


}

void TIMER1_voidSetTimerValue(u16 Copy_u16Val)
{
	TCNT1_ptr=Copy_u16Val;
}
 u16 TIMER1_u16GetTimerValue(void)
 {
	return  TCNT1_ptr;
 }

void TIMER1_voidSetTopValue(u16 Copy_u16TopValue)
{
	ICR1_ptr=Copy_u16TopValue;
}
void TIMER1_voidSetChannelCompareMatch(u16 Copy_u16CompareMatchValue)
{
	OCR1A_prt=Copy_u16CompareMatchValue;

}

void __vector_9(void)
{

	counting ++;

}

/*-----------------ICU HW-----------------*/
void ICU_voidInit(void)
{
	/*Enable INT*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
	/*Select Rising Edge*/
	SET_BIT(TCCR1B,ICES1);
	/*ICP as Input*/
	DIO_voidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_6,DIO_u8INPUT);
}

void ICU_voidSelectEdge(u8 Copy_u8Edge)
{
	switch (Copy_u8Edge)
	{
	case ICU_RISING :
		SET_BIT(TCCR1B,ICES1);
		break;
	case ICU_FALLING:
		CLR_BIT(TCCR1B,ICES1);
		break;

	}
}

u16 ICU_u16ReadICR(void)
{
	return ICR1_ptr;
}
void ICU_voidINTEnable(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void ICU_voidINTDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

void ICU_voidSendCallBack(void(*Copy_PtrtoFunc)(void))
{
	if (Copy_PtrtoFunc!=NULL)
	{
		PvFunc=Copy_PtrtoFunc;
	}

}

void __vector_6(void)
{
	if (PvFunc!=NULL)
	{
		PvFunc();
	}
}
