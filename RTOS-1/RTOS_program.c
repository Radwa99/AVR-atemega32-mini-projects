/*
 * RTOS_program.c
 *
 *  Created on: Aug 31, 2021
 *      Author: Radwa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include"DIO_interface.h"
#include "GINT_interface.h"
#include "TIMER_interface.h"
#include "RTOS_interface.h"

#define NULL         (void*)0
#define TASK_RESUMED    0
#define TASK_SUSPEND    1

typedef struct
{
	u16 TaskPeriodicity;
	void (*Taskfunc)(void);
	u8 state;
	u8 flag;
	u8 FirstDelay;

}task_t;


task_t SystemTasks[TASKS_NUM]={{0}};


void RTOSCreateTask(u8 periority,u16 periodicity,void(*ptr)(void))
{
	if(SystemTasks[periority].flag == 0)
	{

	   SystemTasks[periority].TaskPeriodicity = periodicity;
	   SystemTasks[periority].Taskfunc = ptr;
	   SystemTasks[periority].state = TASK_RESUMED;
	   SystemTasks[periority].flag =1;
	   /*SystemTasks[periority].FirstDelay=FD;*/
	}
	else
	{

	}
}



void RTOSschadular(void)
{
	static u16 counter = 0;
	counter ++;
	u8 i;
	for(i=0;i<TASKS_NUM;i++)
	{

			if(SystemTasks[i].state == TASK_RESUMED)
			{
				if(SystemTasks[i].Taskfunc != NULL)
				{
					if(counter % SystemTasks[i].TaskPeriodicity ==0)
					{
						SystemTasks[i].Taskfunc();
					}
					else
					{

					}

				}
				else
				{

				}
			}
			else
			{

	        }

    }
}

void RTOSStart(void)
{
	TIMER0_SetCallBackFunction(& RTOSschadular);
	GINT_voidEnable();
	Timer0_voidInit();
}


void RTOS_SuspendTask(u8 priority)
{
	SystemTasks[TASKS_NUM].state = TASK_SUSPEND;
}

void RTOS_ResumedTask(u8 priority)
{
	SystemTasks[TASKS_NUM].state = TASK_RESUMED;
}

void RTOS_DeleteTask(u8 priority)
{
	SystemTasks[TASKS_NUM].flag =0;
}

