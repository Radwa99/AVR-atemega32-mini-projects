/*
 * DIO_programm.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include"DIO_interface.h"
#include"DIO_reg.h"


void DIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinDir)
{
	if((Copy_u8PortId <= DIO_u8PORT_D) && (Copy_u8PinId <= DIO_u8PIN_7))
	{

	    if(Copy_u8PinDir == DIO_u8OUTPUT)
	    {
	       switch(Copy_u8PortId)
	       {
	         case DIO_u8PORT_A:  SET_BIT(DDRA,Copy_u8PinId); break;
	         case DIO_u8PORT_B:  SET_BIT(DDRB,Copy_u8PinId); break;
	         case DIO_u8PORT_C:  SET_BIT(DDRC,Copy_u8PinId); break;
             case DIO_u8PORT_D:  SET_BIT(DDRD,Copy_u8PinId); break;
	       }
	}
	   else if(Copy_u8PinDir == DIO_u8INPUT)
	    {
		   switch(Copy_u8PortId)
	       {
		      case DIO_u8PORT_A:  CLR_BIT(DDRA,Copy_u8PinId); break;
	          case DIO_u8PORT_B:  CLR_BIT(DDRB,Copy_u8PinId); break;
	          case DIO_u8PORT_C:  CLR_BIT(DDRC,Copy_u8PinId); break;
		      case DIO_u8PORT_D:  CLR_BIT(DDRD,Copy_u8PinId); break;
		   }
	    }
	    else{/*Nothing*/}
	}
}


void DIO_voidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinVal)
{
	if((Copy_u8PortId <= DIO_u8PORT_D) && (Copy_u8PinId <= DIO_u8PIN_7))
		{

		    if(Copy_u8PinVal == DIO_u8HIGH)
		    {
		       switch(Copy_u8PortId)
		       {
		         case DIO_u8PORT_A:  SET_BIT(PORTA,Copy_u8PinId); break;
		         case DIO_u8PORT_B:  SET_BIT(PORTB,Copy_u8PinId); break;
		         case DIO_u8PORT_C:  SET_BIT(PORTC,Copy_u8PinId); break;
	             case DIO_u8PORT_D:  SET_BIT(PORTD,Copy_u8PinId); break;
		       }
		}
		   else if(Copy_u8PinVal == DIO_u8LOW)
		    {
			   switch(Copy_u8PortId)
		       {
			      case DIO_u8PORT_A:  CLR_BIT(PORTA,Copy_u8PinId); break;
		          case DIO_u8PORT_B:  CLR_BIT(PORTB,Copy_u8PinId); break;
		          case DIO_u8PORT_C:  CLR_BIT(PORTC,Copy_u8PinId); break;
			      case DIO_u8PORT_D:  CLR_BIT(PORTD,Copy_u8PinId); break;
			   }
		    }
		    else{/*Nothing*/}
		}
}


u8 DIO_u8GetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId)
{
	u8 Local_u8ReadPinVal;
	if((Copy_u8PortId <= DIO_u8PORT_D) && (Copy_u8PinId <= DIO_u8PIN_7))
			{
			    switch(Copy_u8PortId)
			     {
			         case DIO_u8PORT_A: Local_u8ReadPinVal= GET_BIT(PINA,Copy_u8PinId); break;
			         case DIO_u8PORT_B: Local_u8ReadPinVal= GET_BIT(PINB,Copy_u8PinId); break;
			         case DIO_u8PORT_C: Local_u8ReadPinVal= GET_BIT(PINC,Copy_u8PinId); break;
		             case DIO_u8PORT_D: Local_u8ReadPinVal= GET_BIT(PIND,Copy_u8PinId); break;
			     }
			}
	else
	{
		Local_u8ReadPinVal=0xff;
	}
	return Local_u8ReadPinVal;
}

/***************************************************************************/


void DIO_voidSetPortDirection(u8 Copy_u8PortId,u8 Copy_u8PortDirection)
{
		switch(Copy_u8PortId)
		{
		case DIO_u8PORT_A: DDRA=Copy_u8PortDirection; break;
		case DIO_u8PORT_B: DDRB=Copy_u8PortDirection; break;
		case DIO_u8PORT_C: DDRC=Copy_u8PortDirection; break;
		case DIO_u8PORT_D: DDRD=Copy_u8PortDirection; break;
		default : /*Error*/ break;
		}


}

void DIO_voidSetPortValue(u8 Copy_u8PortId,u8 Copy_u8PortVal)
{

		switch(Copy_u8PortId)
		{
		case DIO_u8PORT_A: PORTA=Copy_u8PortVal; break;
		case DIO_u8PORT_B: PORTB=Copy_u8PortVal; break;
		case DIO_u8PORT_C: PORTC=Copy_u8PortVal; break;
		case DIO_u8PORT_D: PORTD=Copy_u8PortVal; break;
		default : /*Error*/ break;
		}


}
