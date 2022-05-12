/*
 * TIMER_interface.h

 *
 *  Created on: Aug 27, 2021
 *      Author: Radwa
 */


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_




void TIMER0_voidInit(void);
void TIMER0_SetCallBackFunction(void(*ptrCallback)(void));

void __vector_10 (void)__attribute__((signal));

#endif /* TIMER_INTERFACE_H_ */
