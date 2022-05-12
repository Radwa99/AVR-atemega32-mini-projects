/*
 * TIMER_interface.h


 *
 *  Created on: Aug 29, 2021
 *      Author: Radwa
 */



#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

extern u32 counting;

#define OK  0
#define NOK 1

#define TIMER_NORMALMODE   0
#define TIMER_CTCMODE      1
#define TIMER_PWMMODE      2

#define CTC_OC0_TOGGLE     0
#define CTC_OC0_CLR        1
#define CTC_OC0_SET        2

#define PWM_OC0_CLRONCMPMATCH        0
#define PWM_OC0_SETONCMPMATCH        1

#define CLK_NOPRE       1
#define CLK_DIV8        8
#define CLK_DIV64       64
#define CLK_DIV256      256
#define CLK_DIV1024     1024

#define ICU_RISING      0
#define ICU_FALLING     1



u8 TIMER_voidInit(void);
void Timer0_voidSetCompaerMatch(u8 Copy_u8Counter);
void TIMER_voidSendCallBack(void(*Copy_PtrtoFunc)(void));
void PreLoad(void);
void __vector_11(void)__attribute__((signal));
void __vector_10(void)__attribute__((signal));

/*----------- Timer 1---------------------*/
void TIMER1_voidInit(void);
void TIMER1_voidSetTimerValue(u16 Copy_u16Val);
u16 TIMER1_u16GetTimerValue(void);

void TIMER1_voidSetTopValue(u16 Copy_u16TopValue);
void TIMER1_voidSetChannelCompareMatch(u16 Copy_u16CompareMatchValue);
void __vector_19(void)__attribute__((signal));

/*-----------------ICU---------------*/
void ICU_voidInit(void);
void ICU_voidSelectEdge(u8 Copy_u8Edge);
void ICU_voidINTEnable(void);
void ICU_voidINTDisable(void);
u16 ICU_u16ReadICR(void);
void ICU_voidSendCallBack(void(*Copy_PtrtoFunc)(void));
void __vector_6(void)__attribute__((signal));

#endif /* TIMER_INTERFACE_H_ */
