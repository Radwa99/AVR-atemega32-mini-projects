/*
 * LCD_program.c

 *
 *  Created on: Aug 15, 2021
 *      Author: Radwa
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define F_CPU 8000000
#include "avr/delay.h"

#include"DIO_interface.h"

#include"LCD_config.h"
#include"LCD_interface.h"

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*1:set RS with low to be command*/
	   DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_u8LOW);

	/*2:set Rw with low to write*/
	   DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8LOW);

	/*3:set command to data pins*/
	   DIO_voidSetPortValue(LCD_DATA,Copy_u8Command);

	/*4:Send enable pulse*/
	   DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8HIGH);

	_delay_ms(2);
	   DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8LOW);
}


void LCD_voidSendData(u8 Copy_u8Data)
{
	/*1:set RS with high to be data*/
		DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_u8HIGH);

	/*2:set Rw with low to write*/
		DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8LOW);

	/*3:set data to data pins*/
		DIO_voidSetPortValue(LCD_DATA,Copy_u8Data);

	/*4:Send enable pulse*/
		DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8HIGH);

	_delay_ms(2);
		DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8LOW);
}


void LCD_voidInit(void)
{
	/*1: wait 30ms*/
	   _delay_ms(30);

    /*2:Function set command: 2lines,5*8fontsize*/
	   LCD_voidSendCommand(0b00111000);

	/*3:For display on courser off and blank off*/
	   LCD_voidSendCommand(0b00001100);

	/*clear command*/
	   LCD_voidSendCommand(1);
}

void LCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter=0;
	while(Copy_pcString[Local_u8Counter]!='\0')
	{
		LCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}

}

void LCD_voidCursor(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	if(((Copy_u8XPos ==0) | (Copy_u8XPos ==1)) & ((Copy_u8XPos >= 0x00) | (Copy_u8XPos <= 0x0f)))
	{
	   u8 Local_u8Address;
	   if(Copy_u8XPos==0)
	   {
	      Local_u8Address=Copy_u8YPos;
	   }
	   else if(Copy_u8XPos==1)
	   {
		  Local_u8Address=0x40 + Copy_u8YPos;
	   }
	   LCD_voidSendCommand(Local_u8Address | 0x80);
	}
	else{/*Nothing*/}
}


void LCD_voidWriteSpecialCharacter(u8* Copy_u8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8Xpos,u8 Copy_u8Ypos)
{
	//8*5 Location
	u8 Local_u8CopyCounter;

	/*1:start address of location of GCRAM*/
	u8 Local_u8CGRAMaddress = (Copy_u8PatternNumber*8);

	/*2:Send command to CGRAM instead of DDRAM*/
	LCD_voidSendCommand(Local_u8CGRAMaddress + 64);

	/*3:STORE /WRITE in certain location in CGRAM*/
	for(Local_u8CopyCounter=0; Local_u8CopyCounter<8 ;Local_u8CopyCounter++)
	{
	  LCD_voidSendData(Copy_u8Pattern[Local_u8CopyCounter]);
	}

	/*4:DISPLAY in LCD*/
	LCD_voidCursor(Copy_u8Xpos,Copy_u8Ypos);

	/*5:DISPLAT the pattern in the location received*/
	LCD_voidSendData(Copy_u8PatternNumber);
}
