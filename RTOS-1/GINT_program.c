/*
 * GINT_program.c

 *
 *  Created on: Aug 23, 2021
 *      Author: shahd
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "GINT_reg.h"
#include "GINT_interface.h"

void GINT_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GINT_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);

}


