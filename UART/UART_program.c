/*
 * UART_program.c

 *
 *  Created on: Sep 5, 2021
 *      Author: Radwa
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "UART_Reg.h"

void UART_voidInit(void)
{
	u8 Local_u8Var =0;
	/*Choose UCSRC*/
	SET_BIT(Local_u8Var,URSEL);
	/*Choose Asynch*/
	CLR_BIT(Local_u8Var,UMSEL);
	/*No parity*/
	CLR_BIT(Local_u8Var,UPM1);
	CLR_BIT(Local_u8Var,UPM0);
	/*Stop : 1BIT*/
	CLR_BIT(Local_u8Var,USBS);
	/*8 Data bits*/
	SET_BIT(Local_u8Var,UCSZ1);
	SET_BIT(Local_u8Var,UCSZ0);
	CLR_BIT(UCSRB,UCSZ2);

	UCSRC = Local_u8Var;
	/*Bound Rate*/
	UBRRL = 51;
	/*Enable RX & TX*/
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);

}

void UART_voidTX(u8 Copy_u8Data)
{
	while (GET_BIT(UCSRA,UDRE)==0);
	UDR = Copy_u8Data;
}

u8 UART_voidRX(void)
{
	while (GET_BIT(UCSRA,RXC)==0);
	return UDR;
}


