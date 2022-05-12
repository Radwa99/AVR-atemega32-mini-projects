/*
 * ADC_reg.h

 *
 *  Created on: Aug 19, 2021
 *      Author: Radwa
 */

#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX     *((volatile u8*)0x27)
/*Reference selection bits*/
#define ADMUX_REFS1   7
#define ADMUX_REFS0   6
/*For left adjustment*/
#define ADMUX_ADLAR   5
/*For selecting channels and differential*/
#define ADMUX_MUX4    4
#define ADMUX_MUX3    3
#define ADMUX_MUX2    2
#define ADMUX_MUX1    1
#define ADMUX_MUX0    0

/*ADC control & status*/
#define ADCSRA    *((volatile u8*)0x26)
/*Enable and disable ADC*/
#define ADCSRA_ADEN     7
/*Start conversion : single mode or free */
#define ADCSRA_ADSC     6
/*Auto trigger enable*/
#define ADCSRA_ADATE    5
/*Interrupt flag */
#define ADCSRA_ADIF     4
/*Interrupt enable*/
#define ADCSRA_ADIE     3
/*Prescaler select bits : frequency of clock*/
#define ADCSRA_ADPS2    2
#define ADCSRA_ADPS1    1
#define ADCSRA_ADPS0    0

/*Data registers : 10bit data*/
#define ADCH      *((volatile u8*)0x25)
#define ADCL      *((volatile u8*)0x24)
#define ADC_VAL   *((volatile u16*)0x24)

/*Special function IO register*/
#define SFIOR     *((volatile u8*)0x50)
/*Auto trigger source*/
#define SFIOR_ADTS2    7
#define SFIOR_ADTS1    6
#define SFIOR_ADTS0    5

#endif /* ADC_REG_H_ */
