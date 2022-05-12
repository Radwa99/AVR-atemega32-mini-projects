/*
 * main.c
 *
 *  Created on: Aug 29, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "DIO_interface.h"

#include "TIMER_interface.h"
#include "GINT_interface.h"
#include "LCD_interface.h"
#include "avr/delay.h"

void ICU(void);
u16 ReadPeriod;
u16 ReadTon;
u16 Read1;
u16 Read2;
u16 Read3;

int main()
{
	/*GINT Enable*/
	GINT_voidEnable();
	/*ICU*/
	ICU_voidSendCallBack(ICU);
	ICU_voidInit();
	/*Timer 0 : Generate PWM Signal*/
	TIMER_voidInit();
	/*Make duty cycle = 25%*/
	Timer0_voidSetCompaerMatch(128);
	/*Timer 1*/
	TIMER1_voidInit();
	/*LCD*/
	LCD_voidInit();
    while (1)
    {
    	LCD_voidSendString("Period : ");
        LCD_voidNumAbove9(ReadPeriod);
        LCD_voidGoToXY(1,0);
    	LCD_voidSendString("Ton : ");
        LCD_voidNumAbove9(ReadTon);

    }
    return 0;
}

void ICU(void)
{
	static u8 var =0;
	if (var==0)
	{
		Read1 = ICU_u16ReadICR();
		var =1;
	}
	else if (var==1)
	{
		Read2 = ICU_u16ReadICR();
		ReadPeriod= Read2 - Read1;
		ICU_voidSelectEdge(ICU_FALLING);
		var=2;
	}
	else
	{
		Read3 = ICU_u16ReadICR();
		ReadTon = Read3 - Read2;
		ICU_voidSelectEdge(ICU_RISING);
		var=0;
	}

}
