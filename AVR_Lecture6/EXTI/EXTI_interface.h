/*
 * EXTI_interface.h
 *
 *  Created on: Aug 18, 2021
 *      Author: Radwa
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define EXTI_INT0_PORT           DIO_u8PORT_D
#define EXTI_INT1_PORT           DIO_u8PORT_D
#define EXTI_INT2_PORT           DIO_u8PORT_B

#define EXTI_INT0_PIN            DIO_u8PIN_2
#define EXTI_INT1_PIN            DIO_u8PIN_3
#define EXTI_INT2_PIN            DIO_u8PIN_2


#define EXTI_LOWLEVEL                  0
#define EXTI_RISINGEDGE                1
#define EXTI_FALLINGEDGE               2
#define EXTI_ONCHANGE                  3

#define OK      1
#define NOTOK   0

void __vector_1(void)__attribute__((signal));
void __vector_2(void)__attribute__((signal));
void __vector_3(void)__attribute__((signal));
u8 EXTI0_voidInit(u8 Copy_u8SenseLevel);
u8 EXTI1_voidInit(u8 Copy_u8SenseLevel);
u8 EXTI2_voidInit(u8 Copy_u8SenseLevel);



#endif /* EXTI_INTERFACE_H_ */
