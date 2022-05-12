/*
 * GINT_reg.h
 *
 *  Created on: Aug 23, 2021
 *      Author: shahd
 */

#ifndef GINT_REG_H_
#define GINT_REG_H_

/*SREG -- > Status Register */
#define SREG              *((volatile u8*)0x5F)
/*SREG_I --> Global Interrupt Enable*/
#define SREG_I            7

#endif /* GINT_REG_H_ */
