/*
 * ADC_interface.h
 *
 *  Created on: Aug 19, 2021
 *      Author: Radwa
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_INPUT_PORT  DIO_u8PORT_A
#define ADC_INPUT_PIN0  DIO_u8PIN_0
#define ADC_INPUT_PIN1  DIO_u8PIN_1
#define ADC_INPUT_PIN2  DIO_u8PIN_2
#define ADC_INPUT_PIN3  DIO_u8PIN_3
#define ADC_INPUT_PIN4  DIO_u8PIN_4
#define ADC_INPUT_PIN5  DIO_u8PIN_5
#define ADC_INPUT_PIN6  DIO_u8PIN_6
#define ADC_INPUT_PIN7  DIO_u8PIN_7

#define AREF_PIN      0x00
#define AVCC          0x40
#define RESERVED      0x80
#define INTERNAL2     0xc0


void ADC_voidInit();
u8 ADC_voidRead(u8 Copy_u8channel);



#endif /* ADC_INTERFACE_H_ */
