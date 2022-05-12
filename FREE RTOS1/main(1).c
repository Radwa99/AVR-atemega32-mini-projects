/*
 * main.c
 *
 *  Created on: Sep 1, 2021
 *      Author: Radwa
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include"FreeRTOS.h"
#include"task.h"
#include"DIO_interface.h"
#include"LCD_interface.h"




void TASK1(void *);
void TASK2(void *);


int main()
{
    LCD_voidInit();
	xTaskCreate(TASK1,NULL,100,NULL,0,NULL);
    xTaskCreate(TASK2,NULL,100,NULL,1,NULL);
    vTaskStartScheduler();

    while(1)
    {

    }
    return 0;
}

void TASK1(void *params)
{


	 while(1)
			{
                vTaskDelay(1000);
				LCD_voidSendString("TASK1");
			}
}

void TASK2(void *params)
{


	 while(1)
			{
		        vTaskDelay(2000);
		       LCD_voidSendString("TASK2");
			}
}

