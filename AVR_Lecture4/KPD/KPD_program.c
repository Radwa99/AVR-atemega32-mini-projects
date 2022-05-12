/*
 * KPD_program.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define F_CPU 8000000
#include "avr/delay.h"

#include"DIO_interface.h"

#include"KPD_config.h"
#include"KPD_interface.h"

void KPD_voidInit(void)
{
	DIO_voidSetPinDirection(KPD_PORT,KPD_U8COLUMN0,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_U8COLUMN1,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_U8COLUMN2,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_U8COLUMN3,DIO_u8OUTPUT);

	DIO_voidSetPinDirection(KPD_PORT,KPD_U8ROW0,DIO_u8INPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_U8ROW1,DIO_u8INPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_U8ROW2,DIO_u8INPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_U8ROW3,DIO_u8INPUT);

	DIO_voidSetPinValue(KPD_PORT,KPD_U8COLUMN0,DIO_u8HIGH);
	DIO_voidSetPinValue(KPD_PORT,KPD_U8COLUMN1,DIO_u8HIGH);
	DIO_voidSetPinValue(KPD_PORT,KPD_U8COLUMN2,DIO_u8HIGH);
	DIO_voidSetPinValue(KPD_PORT,KPD_U8COLUMN3,DIO_u8HIGH);

	DIO_voidSetPinValue(KPD_PORT,KPD_U8ROW0,DIO_u8HIGH);
	DIO_voidSetPinValue(KPD_PORT,KPD_U8ROW1,DIO_u8HIGH);
	DIO_voidSetPinValue(KPD_PORT,KPD_U8ROW2,DIO_u8HIGH);
	DIO_voidSetPinValue(KPD_PORT,KPD_U8ROW3,DIO_u8HIGH);
}



u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8ColIdx,Local_u8RowIdx,Local_u8PinState;
	u8 Local_u8PressedKey = KPD_u8NOTPRESSED;
	u8 Local_u8KPDARR[KPD_u8ROWNNUMB][KPD_u8COLUMNNUMB]=KPD_u8ARRVAL;
	u8 Local_u8ColArr[4]={KPD_U8COLUMN0,KPD_U8COLUMN1,KPD_U8COLUMN2,KPD_U8COLUMN3};
	u8 Local_u8RowArr[4]={KPD_U8ROW0,KPD_U8ROW1,KPD_U8ROW2,KPD_U8ROW3};

	for(Local_u8ColIdx=0;Local_u8ColIdx<KPD_u8COLUMNNUMB;Local_u8ColIdx++)
	{
		DIO_voidSetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIdx],DIO_u8LOW);
		for(Local_u8RowIdx=0;Local_u8RowIdx<KPD_u8ROWNNUMB;Local_u8RowIdx++)
		{
			Local_u8PinState= DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIdx]);

             if(Local_u8PinState==DIO_u8LOW)
             {
            	 while(Local_u8PinState==DIO_u8LOW)
            	 {
            		 Local_u8PinState= DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIdx]);
            	 }
            	 Local_u8PressedKey = Local_u8KPDARR[Local_u8RowIdx][Local_u8ColIdx];
            	 return Local_u8PressedKey;
             }
		}
		DIO_voidSetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIdx],DIO_u8HIGH);
}
	return Local_u8PressedKey;
}
