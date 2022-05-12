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
#include"LCD_interface.h"

int main()
{
	DIO_voidSetPortDirection(DIO_u8PORT_A,DIO_u8PORTOUTPUT);

	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_1,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_B,DIO_u8PIN_2,DIO_u8OUTPUT);

	LCD_voidInit();
	u8 i,j;

	u8 ARR1[4][8]={{
						    0b00000001,
						    0b00000001,
						    0b00000010,
							0b00000100,
							0b00001000,
							0b00010000,
							0b00100000
				        },{
				           0b00000010,
						   0b00000111,
						   0b00001001,
						   0b00011111
			           	},{
			           	   0b00001110,
						   0b00001010,
						   0b00001111,
						   0b00000010,
						   0b00000010,
						   0b00000100,
						   0b00001000,
						   0b00010000
				        },{
				           0b00000111,
						   0b00000101,
						   0b00100100,
						   0b00010010,
						   0b00010010,
						   0b00011100
				        }};
			u8 ARR2[4][8]={{0}};

	while(1)
	{

		for(i=0;i<10;i+=4)
		{
			for(j=0;j<2;j++)
			{
			      LCD_voidWriteSpecialCharacter(ARR1[0],1,j,i+3+2*j);
				  LCD_voidWriteSpecialCharacter(ARR1[1],2,j,i+2+2*j);
				  LCD_voidWriteSpecialCharacter(ARR1[2],3,j,i+1+2*j);
				  LCD_voidWriteSpecialCharacter(ARR1[3],4,j,i+2*j);
				  _delay_ms(500);
				  LCD_voidWriteSpecialCharacter(ARR2[0],5,j,i+3+2*j);
				  LCD_voidWriteSpecialCharacter(ARR2[1],6,j,i+2+2*j);
				  LCD_voidWriteSpecialCharacter(ARR2[2],7,j,i+1+2*j);
				  LCD_voidWriteSpecialCharacter(ARR2[3],8,j,i+2*j);
			}
			if(i==10)
			{
				i=0;
			}
		}
	}
}



