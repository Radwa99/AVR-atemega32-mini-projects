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

/*void ISR(void);*/
int main()
{
	u8 i;
	TIMER_voidInit();
	for (i=0;i<256;i++)
	{
		Timer0_voidSetCompaerMatch(i);
	}
}

