/*
 * TIMER_reg.h



 *
 *  Created on: Aug 29, 2021
 *      Author: Radwa
 */

#ifndef TIMER_REG_H_
#define TIMER_REG_H_

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
#define TCNT0    *((volatile u8*)0x52)

/*--------------------Timer 1 --------------------------*/
#define TCCR1A     *((volatile u8*)0x4F)
#define COM1A1     7
#define COM1A0     6
#define WGM11      1
#define WGM10      0

/*CU & OV Interrupt Enable*/
#define TIMSK_TICIE1    5
#define TIMSK_TOIE1     3


#define TCCR1B     *((volatile u8*)0x4E)
#define ICES1      6
#define WGM13      4
#define WGM12      3
#define CS12       2
#define CS11       1
#define CS10       0


#define OCR1AH       *((volatile u8*)0x4B)
#define OCR1AL       *((volatile u8*)0x4A)
#define OCR1A_prt    *((volatile u16*)0x4A)

#define ICR1H        *((volatile u8*)0x47)
#define ICR1L        *((volatile u8*)0x46)
#define ICR1_ptr     *((volatile u16*)0x46)

#define TCNT1H       *((volatile u8*)0x4D)
#define TCNT1L       *((volatile u8*)0x4C)
#define TCNT1_ptr    *((volatile u16*)0x4C)



#endif /* TIMER_REG_H_ */
