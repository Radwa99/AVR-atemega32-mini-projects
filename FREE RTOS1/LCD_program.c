/*
 * LCD_program.c

 *
 *  Created on: Aug 15, 2021
 *      Author: shahd
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include"DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "avr/delay.h"


void LCD_voidSendCommand(u8 Copy_u8Command)
{
/*1-Set RS with low --> command*/
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_u8LOW);
/*2-Set RW with low --> write*/
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8LOW);
/*3-Set Command on Pins --> write*/
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Command);
/*4-Set E  --> Send pulse*/
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8LOW);
}
void LCD_voidSendData(u8 Copy_u8Data)
{
/*1-Set RS with high --> command*/
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_u8HIGH);
/*2-Set RW with low --> write*/
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8LOW);
/*3-Set Command on Pins --> write*/
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Data);
/*4-Set E  --> Send pulse*/
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8LOW);
}
void LCD_voidInit(void)
{
	/*Initialization Direction of LCD PINS*/
	DIO_voidSetPortDirection(LCD_DATA_PORT,DIO_u8PORTOUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8OUTPUT);
	_delay_ms(30);
	/*Function Set : 2 Lines and 5*8 */
	LCD_voidSendCommand(0b00111000);
	/*No need delay*/
	/*Function OV OFF Display*/
	LCD_voidSendCommand(0b00001100);
	/*CLR Command*/
	LCD_voidSendCommand(1);

}
void LCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_counter = 0;
	while(Copy_pcString[Local_counter] != '\0')
	{
		LCD_voidSendData(Copy_pcString[Local_counter]);
		Local_counter ++;
	}
}

void LCD_voidGoToXY(u8 Copy_u8XPOS,u8 Copy_u8YPOS)
{
	if (Copy_u8YPOS <= 15 && ((Copy_u8XPOS == 0) || (Copy_u8XPOS == 1)))
	{
		if (Copy_u8XPOS==1)
		{
			Copy_u8YPOS += LCD_SCND_Line;
		}
		LCD_voidSendCommand(Copy_u8YPOS + 128);
	}
	else
	{
		/*Out of range*/
	}

}

void LCD_voidWriteSpecialCharacter(u8 *Copy_u8Pattern,u8 Copy_u8PatternNumber, u8 Copy_u8XPOS,u8 Copy_u8YPOS)
{
	u8 Local_u8Address;
	u8 Local_u8Counter;
	/*1- Calculate CGRAM Block Address,Start Add of Location */
	Local_u8Address = Copy_u8PatternNumber*8;

	/*2- Send command to Go to CGRAM instead of DDRAM*/
	LCD_voidSendCommand(Local_u8Address + 64);

	/*3- Write in the location in CGRAM*/
	for (Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
	{
		LCD_voidSendData(Copy_u8Pattern[Local_u8Counter]);
	}

	/*4- Change to point on DDRAM */
	LCD_voidGoToXY(Copy_u8XPOS,Copy_u8YPOS);

	/*5 - Display the pattern in the location received */
	LCD_voidSendData(Copy_u8PatternNumber);



}

void LCD_voidNumAbove9(u16 Copy_u8Result)
{
	u8 Local_u8Counter=0;
	if (Copy_u8Result >9999 && Copy_u8Result<100000 )
	{
		do
		{
			Copy_u8Result-=10000;
			Local_u8Counter+=1;
		}while(Copy_u8Result>9999);
		LCD_voidSendData(Local_u8Counter + '0');
		Local_u8Counter=0;
		if (Copy_u8Result > 999)
		{
			do
			{
				Copy_u8Result-=1000;
				Local_u8Counter+=1;
			}while (Copy_u8Result > 999);
			LCD_voidSendData(Local_u8Counter + '0');
			Local_u8Counter=0;
				if (Copy_u8Result > 99)
				{
					do
					{
						Copy_u8Result-=100;
						Local_u8Counter+=1;
					}while (Copy_u8Result > 99);
					LCD_voidSendData(Local_u8Counter + '0');
					Local_u8Counter=0;
					if (Copy_u8Result > 9)
					{
						do
						{
							Copy_u8Result-=10;
							Local_u8Counter+=1;
						}while (Copy_u8Result > 9);
						LCD_voidSendData(Local_u8Counter + '0');
						LCD_voidSendData(Copy_u8Result + '0');
						_delay_ms(500);
						LCD_voidSendCommand(1);
					}
					else
					{
						LCD_voidSendData('0');
						LCD_voidSendData(Copy_u8Result + '0');
						_delay_ms(500);
						LCD_voidSendCommand(1);
					}
				}
				else
				{
					if (Copy_u8Result > 9)
					{
						LCD_voidSendData('0');
						do
						{
							Copy_u8Result-=10;
							Local_u8Counter+=1;
						}while (Copy_u8Result > 9);
						LCD_voidSendData(Local_u8Counter + '0');
						LCD_voidSendData(Copy_u8Result + '0');
						_delay_ms(500);
						LCD_voidSendCommand(1);
					}
					else
					{
						LCD_voidSendData('0');
						LCD_voidSendData('0');
						LCD_voidSendData(Copy_u8Result + '0');
						_delay_ms(500);
						LCD_voidSendCommand(1);
					}
				}
			}
		else
		{
			if (Copy_u8Result > 99)
			{
				LCD_voidSendData('0');
				do
				{
					Copy_u8Result-=100;
					Local_u8Counter+=1;
				}while (Copy_u8Result > 99);
				LCD_voidSendData(Local_u8Counter + '0');
				Local_u8Counter=0;
				if (Copy_u8Result > 9)
				{
					do
					{
						Copy_u8Result-=10;
						Local_u8Counter+=1;
					}while (Copy_u8Result > 9);
					LCD_voidSendData(Local_u8Counter + '0');
					LCD_voidSendData(Copy_u8Result + '0');
					_delay_ms(500);
					LCD_voidSendCommand(1);
				}
				else
				{
					LCD_voidSendData('0');
					LCD_voidSendData(Copy_u8Result + '0');
					_delay_ms(500);
					LCD_voidSendCommand(1);
				}
			}
			else
			{
				if (Copy_u8Result>9 && Copy_u8Result<100)
				{
					LCD_voidSendData('0');
					LCD_voidSendData('0');
					do
					{
						Copy_u8Result-=10;
						Local_u8Counter+=1;
					}while (Copy_u8Result > 9);
					LCD_voidSendData(Local_u8Counter + '0');
					LCD_voidSendData(Copy_u8Result + '0');
					_delay_ms(500);
					LCD_voidSendCommand(1);
				}
				else
				{
					LCD_voidSendData('0');
					LCD_voidSendData('0');
					LCD_voidSendData('0');
					LCD_voidSendData(Copy_u8Result + '0');
					_delay_ms(500);
					LCD_voidSendCommand(1);
				}
			}
		}
	}
	else if (Copy_u8Result >999 && Copy_u8Result<10000)
	{
		do
		{
			Copy_u8Result-=1000;
			Local_u8Counter+=1;
		}while (Copy_u8Result > 999);
		LCD_voidSendData(Local_u8Counter + '0');
		Local_u8Counter=0;
			if (Copy_u8Result > 99)
			{
				do
				{
					Copy_u8Result-=100;
					Local_u8Counter+=1;
				}while (Copy_u8Result > 99);
				LCD_voidSendData(Local_u8Counter + '0');
				Local_u8Counter=0;
				if (Copy_u8Result > 9)
				{
					do
					{
						Copy_u8Result-=10;
						Local_u8Counter+=1;
					}while (Copy_u8Result > 9);
					LCD_voidSendData(Local_u8Counter + '0');
					LCD_voidSendData(Copy_u8Result + '0');
					_delay_ms(500);
					LCD_voidSendCommand(1);
				}
				else
				{
					LCD_voidSendData('0');
					LCD_voidSendData(Copy_u8Result + '0');
					_delay_ms(500);
					LCD_voidSendCommand(1);
				}
			}
			else
			{
				if (Copy_u8Result>9 && Copy_u8Result<100)
				{
					LCD_voidSendData('0');
					do
					{
						Copy_u8Result-=10;
						Local_u8Counter+=1;
					}while (Copy_u8Result > 9);
					LCD_voidSendData(Local_u8Counter + '0');
					LCD_voidSendData(Copy_u8Result + '0');
					_delay_ms(500);
					LCD_voidSendCommand(1);
				}
				else
				{
					LCD_voidSendData('0');
					LCD_voidSendData('0');
					LCD_voidSendData(Copy_u8Result + '0');
					_delay_ms(500);
					LCD_voidSendCommand(1);
				}
			}
	}
	else if (Copy_u8Result >99 && Copy_u8Result<1000)
	{
		do
		{
			Copy_u8Result-=100;
			Local_u8Counter+=1;
		}while (Copy_u8Result > 99);
		LCD_voidSendData(Local_u8Counter + '0');
		Local_u8Counter=0;
		if (Copy_u8Result > 9)
		{
			do
			{
				Copy_u8Result-=10;
				Local_u8Counter+=1;
			}while (Copy_u8Result > 9);
			LCD_voidSendData(Local_u8Counter + '0');
			LCD_voidSendData(Copy_u8Result + '0');
			_delay_ms(500);
			LCD_voidSendCommand(1);
		}
		else
		{
			LCD_voidSendData('0');
			LCD_voidSendData(Copy_u8Result + '0');
			_delay_ms(500);
			LCD_voidSendCommand(1);
		}
	}
	else if (Copy_u8Result >9 && Copy_u8Result<100)
	{
		do
		{
			Copy_u8Result-=10;
			Local_u8Counter+=1;
		}while (Copy_u8Result > 9);
		LCD_voidSendData(Local_u8Counter + '0');
		LCD_voidSendData(Copy_u8Result + '0');
		_delay_ms(500);
		LCD_voidSendCommand(1);
	}
	else if (Copy_u8Result >=0 && Copy_u8Result <10 )
	{
		LCD_voidSendData(Copy_u8Result + '0');
		_delay_ms(500);
		LCD_voidSendCommand(1);
	}
	else
	{
		LCD_voidGoToXY(1,0);
		LCD_voidSendString("Out Of Range");
		_delay_ms(500);
		LCD_voidSendCommand(1);
	}
}
