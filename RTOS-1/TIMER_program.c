/*
 * TIMER0_program.c

 *
 *  Created on: Aug 27, 2021
 *      Author: Radwa
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"
#include "TIMER_reg.h"
#define NULL (void*)0

#define TIMER0_PRESCALER_MASK         0xf8
#define NO_PRESCALER                   1
#define DIVIDE_BY_8                    2
#define DIVIDE_BY_64                   3
#define DIVIDE_BY_256                  4
#define DIVIDE_BY_1024                 5

static void(*TIMER0_pvCallBack_Func)(void)=NULL;
void Timer0_voidInit(void)
{
	/*CTC*/
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*OCR0*/
	OCR0=TIMER0_COMP_MATCH_VAL;
	SET_BIT(TIMSK,OCIE0);
	/*DEVIDE BY 64*/
	TCCR0&=TIMER0_PRESCALER_MASK;
	TCCR0|=TIMER0_u8PRESCALER;
}
/*Set callback of timer0 CTC*/
void TIMER0_SetCallBackFunction(void(*ptrCallback)(void))
{
	if(ptrCallback != NULL)
	{
		TIMER0_pvCallBack_Func=ptrCallback;
	}
	else
	{
		//Do nothing
	}
}

/*TIMER0 COMPARE MATCH ISR every 1ms*/
void __vector_10 (void)
{

	if(TIMER0_pvCallBack_Func != NULL)
	{
		TIMER0_pvCallBack_Func();
	}
	else
	{
			//Do nothing
	}
}
