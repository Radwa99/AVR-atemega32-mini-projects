/*
 * STEPMOTOR_interface.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Radwa
 */

#ifndef STEPMOTOR_INTERFACE_H_
#define STEPMOTOR_INTERFACE_H_

void StepMotor_voidInit(void);
void StepMotor_RotateRight();
void StepMotor_RotateLeft();
void StepMotor_RotateRightWithAngle(u8 Copy_u8Angle);
void StepMotor_RotateLeftWithAngle(u8 Copy_u8Angle);
void StepMotor_Stop();



#endif /* STEPMOTOR_INTERFACE_H_ */
