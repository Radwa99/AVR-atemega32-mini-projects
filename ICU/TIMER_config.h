/*
 * TIMER_config.h



 *
 *  Created on: Aug 29, 2021
 *      Author: Radwa
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*Your options : TIMER_NORMALMODE or TIMER_CTCMODE or TIMER_PWMMODE */
#define TIMER_MODE         TIMER_PWMMODE

/*Your options : CTC_OC0_TOGGLE or CTC_OC0_CLR or CTC_OC0_SET*/
#define CTC_OC0PIN_MODE    CTC_OC0_TOGGLE

/*Your options : PWM_OC0_CLRONCMPMATCH  or PWM_OC0_SETONCMPMATCH*/
#define PWM_OC0PIN_MODE   PWM_OC0_CLRONCMPMATCH

/*Your options : CLK_NOPRE or CLK_DIV8 or CLK_DIV64  or CLK_DIV256 or CLK_DIV1024 */
#define CLK_PRESCALER    CLK_DIV8


#endif /* TIMER_CONFIG_H_ */
