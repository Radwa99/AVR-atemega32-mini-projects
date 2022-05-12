/*
 * main.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define F_CPU 8000000
#include "avr/delay.h"
#include"DIO_interface.h"
#include"KPD_interface.h"
#include"KPD_config.h"
#include"LCD_interface.h"

int main()
{
	DIO_voidSetPortDirection(DIO_u8PORT_A,DIO_u8PORTOUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_1,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_2,DIO_u8OUTPUT);
	u8 putton,i=0,M=0;
	s8 Res=0,Rem;
	u8 Arr[4];
	KPD_voidInit();
	LCD_voidInit();

	while (1)
	{
		while (i<4)
		{
			putton = KPD_u8GetPressedKey();
			if (putton != KPD_u8NOTPRESSED)
			{
				if (putton != 'c')
				{
					Arr[i] = putton;
					LCD_voidSendData(Arr[i]);
					_delay_ms(100);
					if (i==3)
					{
						if (Arr[3]!='=')
						{
							LCD_voidCursor(1,0);
							LCD_voidSendString("Error Operation");
							_delay_ms(500);
							LCD_voidSendCommand(1);
							break;
						}
						else
						{
							if (Arr[1]== '+' )
							{
								Res = (Arr[0] - '0') + (Arr[2] - '0');
								if (Res > 9)
								{
									Res-=10;
									LCD_voidCursor(1,0);
									LCD_voidSendData('1');
									LCD_voidSendData(Res + '0');
									_delay_ms(500);
									LCD_voidSendCommand(1);
									break;
								}
								LCD_voidCursor(1,0);
								LCD_voidSendData(Res + '0');
								_delay_ms(500);
								LCD_voidSendCommand(1);
								break;
							}
							else if (Arr[1]== '-' )
							{
								Res = (Arr[0] - '0') - (Arr[2] - '0');
								if (Res<0)
								{
									Res*=-1;
									LCD_voidCursor(1,0);
									LCD_voidSendData('-');
									LCD_voidSendData(Res + '0');
									_delay_ms(500);
									LCD_voidSendCommand(1);
									break;
								}
								LCD_voidCursor(1,0);
								LCD_voidSendData(Res + '0');
								_delay_ms(500);
								LCD_voidSendCommand(1);
								break;
							}
							else if (Arr[1]== '*')
							{
								Res = (Arr[0] - '0') * (Arr[2] - '0');
								if (Res > 9)
								{
									do
									{
										Res-=10;
										M+=1;
									}while(Res>9);
									LCD_voidCursor(1,0);
									LCD_voidSendData(M + '0');
									LCD_voidSendData(Res + '0');
									_delay_ms(500);
									LCD_voidSendCommand(1);
									M=0;
									break;
								}
								LCD_voidCursor(1,0);
								LCD_voidSendData(Res + '0');
								_delay_ms(500);
								LCD_voidSendCommand(1);
								break;
							}
							else if (Arr[1]== '/')
							{
								if (Arr[2] == '0')
								{
									LCD_voidCursor(1,0);
									LCD_voidSendString("Infinity");
									_delay_ms(500);
									LCD_voidSendCommand(1);
									break;
								}
								else
								{
									Res = (Arr[0] - '0') / (Arr[2] - '0');
									Rem = (Arr[0] - '0') % (Arr[2] - '0');
									LCD_voidCursor(1,0);
									LCD_voidSendData(Res + '0');
									LCD_voidSendString(" ,Remainder= ");
									LCD_voidSendData(Rem + '0');
									_delay_ms(1000);
									LCD_voidSendCommand(1);
									break;
								}
							}
							else
							{
								LCD_voidCursor(1,0);
								LCD_voidSendString("Error Operation");
								_delay_ms(500);
								LCD_voidSendCommand(1);
								break;
							}
						}
					}
					i++;
				}
				else
				{
					LCD_voidSendCommand(1);
					break;
				}
		    }
		}
		i=0;
	}


	return 0;
}



