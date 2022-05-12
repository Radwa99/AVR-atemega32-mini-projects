/*
 * DIO_interface.h

 *
 *  Created on: Aug 12, 2021
 *      Author: Radwa
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

// Port definitions

#define DIO_u8PORT_A    0
#define DIO_u8PORT_B    1
#define DIO_u8PORT_C    2
#define DIO_u8PORT_D    3

//Pins defines

#define DIO_u8PIN_0     0
#define DIO_u8PIN_1     1
#define DIO_u8PIN_2     2
#define DIO_u8PIN_3     3
#define DIO_u8PIN_4     4
#define DIO_u8PIN_5     5
#define DIO_u8PIN_6     6
#define DIO_u8PIN_7     7

//Value
#define DIO_u8OUTPUT      1
#define DIO_u8INPUT       0

// out/in
#define DIO_u8HIGH      1
#define DIO_u8LOW       0

#define DIO_u8PORTHIGH      0xff
#define DIO_u8PORTOUTPUT       0xff


//ID pins
void DIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinDirection);

void DIO_voidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinVal);

u8 DIO_u8GetPin(u8 Copy_u8PortId,u8 Copy_u8PinId);

// Port pins
void DIO_voidSetPortDirection(u8 Copy_u8PortId,u8 Copy_u8PortDirection);

void DIO_voidSetPortValue(u8 Copy_u8PortId,u8 Copy_u8PortVal);


#endif /* DIO_INTERFACE_H_ */
