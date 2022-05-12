/*
 * EXTI_reg.h
 *
 *  Created on: Aug 18, 2021
 *      Author: Radwa
 */

#ifndef EXTI_REG_H_
#define EXTI_REG_H_


/* MCUCR ...> sense level INT1  INT0*/
#define MCUCR         *((volatile u8*)0x55)
#define MCUCR_IS00               0
#define MCUCR_IS01               1
#define MCUCR_IS10               2
#define MCUCR_IS11               3

/*MCUR......>INT2*/
#define MCUCSR        *((volatile u8*)0x54)
#define MCUCSR_ISC2              6

/*GUCR*/
#define GICR         *((volatile u8*)0x5B)
#define GICR_INT2                5
#define GICR_INT0                6
#define GICR_INT1                7

/*GIFR*/
#define GIFR         *((volatile u8*)0xA5)
#define GIFR_INTF2              5
#define GIFR_INTF0               6
#define GIFR_INTF1               7

/*SREG*/
#define SREG          *((volatile u8*)0x5F)
#define SREG_I                   7

#endif /* EXTI_REG_H_ */
