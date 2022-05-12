/*
 * main.c
 *
 *  Created on: Aug 29, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "DIO_interface.h"
#include "ADC_interface.h"
#include "TIMER_interface.h"
#include "LCD_interface.h"
#include "avr/delay.h"

int main()
{
	u16 ReadVal;
	u16 Read;
	u16 CMP;
	DIO_voidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_5,DIO_u8OUTPUT);
	ADC_voidADCInit();
	TIMER1_voidInit();
	LCD_voidInit();
	TIMER1_voidSetTopValue(20000);
	while (1)
	{
		ADC_u8ReadChannelSingleEnded(ADC_CH1,&Read);
		ReadVal = Read;
		LCD_voidNumAbove9(ReadVal);
		CMP= ReadVal+1000;
		TIMER1_voidSetChannelCompareMatch(CMP);
		_delay_ms(10);
	}

}

