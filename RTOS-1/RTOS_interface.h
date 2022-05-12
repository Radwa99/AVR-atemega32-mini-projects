/*
 * RTOS_interface.h
 *
 *  Created on: Aug 31, 2021
 *      Author: Radwa
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_
#define TASKS_NUM          3


void RTOSStart(void);
void RTOSCreateTask(u8 periority,u16 periodicity,void(*ptr)(void));
void RTOSschadular(void);
void RTOS_SuspendTask(u8 priority);
void RTOS_ResumedTask(u8 priority);
void RTOS_DeleteTask(u8 priority);


#endif /* RTOS_INTERFACE_H_ */
