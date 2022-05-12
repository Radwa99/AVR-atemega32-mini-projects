/*
 * KPD_config.h
 *
 *  Created on: Aug 16, 2021
 *      Author: Radwa
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_PORT            DIO_u8PORT_C

#define KPD_U8COLUMN0       DIO_u8PIN_0
#define KPD_U8COLUMN1       DIO_u8PIN_1
#define KPD_U8COLUMN2       DIO_u8PIN_2
#define KPD_U8COLUMN3       DIO_u8PIN_3

#define KPD_U8ROW0          DIO_u8PIN_4
#define KPD_U8ROW1          DIO_u8PIN_5
#define KPD_U8ROW2          DIO_u8PIN_6
#define KPD_U8ROW3          DIO_u8PIN_7

#define KPD_u8NOTPRESSED    0xff

#define KPD_u8COLUMNNUMB     4
#define KPD_u8ROWNNUMB       4


#define KPD_u8ARRVAL         {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}}

#endif /* KPD_CONFIG_H_ */
