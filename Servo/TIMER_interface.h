/*
 * TIMER_interface.h


 *
 *  Created on: Aug 29, 2021
 *      Author: Radwa
 */



#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

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



u8 TIMER_voidInit(void);
void Timer0_voidSetCompaerMatch(u8 Copy_u8Counter);
void TIMER_voidSendCallBack(void(*Copy_PtrtoFunc)(void));
void PreLoad(void);
void __vector_11(void)__attribute__((signal));
void __vector_10(void)__attribute__((signal));

#endif /* TIMER_INTERFACE_H_ */
