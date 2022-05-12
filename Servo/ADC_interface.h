/*
 * ADC_interface.h
 *
 *  Created on: Aug 19, 2021
 *      Author: Radwa
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define ADC_PORT     DIO_u8PORT_A

#define DIVFACT_2     0
#define DIVFACT_2_1     1
#define DIVFACT_4     2
#define DIVFACT_8     3
#define DIVFACT_16    4
#define DIVFACT_32    5
#define DIVFACT_64    6
#define DIVFACT_128   7

#define AREF_EXTSUPPLY    0
#define AREF_AVCCANDCAP   1
#define AREF_INTSUPPLY    2

#define ADC_CH1   1
#define ADC_CH2   2
#define ADC_CH3   3
#define ADC_CH4   4
#define ADC_CH5   5
#define ADC_CH6   6
#define ADC_CH7   7
#define ADC_CH8   8

#define ADC_RES_8BIT    0
#define ADC_RES_10BIT   1

#define ADC_ADJLEFT     0
#define ADC_ADJRIGHT    1

#define OK                 0
#define NOK                1

/*u8 ADC_voidADCInit(u8 Copy_u8DivisionFactorOfClk,u8 Copy_u8ArefSelect);*/
void ADC_voidADCINTEnable(void);
void ADC_voidADCINTDisable(void);
void ADC_voidRightAdj(void);
void ADC_voidLefttAdj(void);
/*u16 ADC_u8ReadChannelSingleEnded(u8 Copy_u8ChannelNum,u8 Copy_u8ResBits);*/
void ADC_voidStartConversionByPolling(void);

u8 ADC_voidADCInit(void);
u8 ADC_u8ReadChannelSingleEnded(u8 Copy_u8ChannelNum,u16* ptr);




#endif /* ADC_INTERFACE_H_ */
