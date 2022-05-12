/*
 * ADC_program.c
 *
 *  Created on: Aug 19, 2021
 *      Author: Radwa
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define F_CPU 8000000
#include "avr/delay.h"

#include"DIO_interface.h"
#include"ADC_interface.h"
#include"ADC_reg.h"

void ADC_voidInit()
{
	DIO_voidSetPortDirection(ADC_INPUT_PORT,DIO_u8OUTPUT);			                /* Make ADC port as input */
	ADCSRA = (1<<ADCSRA_ADEN)|(1<<ADCSRA_ADPS2)|(1<<ADCSRA_ADPS1)|(1<<ADCSRA_ADPS0);		                                       /* Enable ADC, fr/128  */
	ADMUX = AVCC ;			                                                         /* Vref: Avcc, ADC channel: 0 */
}

u8 ADC_voidRead(u8 Copy_u8channel)
{
	u8 Ain,AinLow;

	ADMUX=ADMUX|( Copy_u8channel & 0x0f);	/* Set input channel to read */

	ADCSRA |= (1<<ADCSRA_ADSC);		/* Start conversion */
	while((ADCSRA&(1<<ADCSRA_ADIF))==0);	/* Monitor end of conversion interrupt */

	_delay_us(10);
	AinLow = (u8)ADCL;		/* Read lower byte*/
	Ain = (u8)ADCH*256;		/* Read higher 2 bits and Multiply with weight */
	Ain = Ain + AinLow;
	return(Ain);			/* Return digital value*/
}


