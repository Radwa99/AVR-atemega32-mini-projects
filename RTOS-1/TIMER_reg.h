/*
 * TIMER0_reg.h
 *
 *  Created on: Aug 27, 2021
 *      Author: Radwa
 */

#ifndef TIMER_REG_H_
#define TTIMER_REG_H_

/*-------------------Timer 0--------------------------*/
/*Control register*/
#define TCCR0    *((volatile u8*)0x53)
/*For modes : normal or CTC or ..*/
#define WGM00    6
#define WGM01    3
/*For Compare match mode on Pin OC0*/
#define COM01    5
#define COM00    4
/*For clk prescaler*/
#define CS02     2
#define CS01     1
#define CS00     0


/*Timer0 INT*/
#define TIMSK    *((volatile u8*)0x59)
/*Timer0 OvFlow INT Enable*/
#define TOIE0    0
/*Timer0 CTC INT enable*/
#define OCIE0    1


/*OCR0 Register of CTC mode value : Top*/
#define OCR0    *((volatile u8*)0x5C)
/*For preload value*/
#define TCNT0   *((volatile u8*)0x52)


#endif /* TITIMER_REG_H_*/
