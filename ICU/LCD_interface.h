/*
 * LCD_interface.h
 *
 *  Created on: Aug 15, 2021
 *      Author: Radwa
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_SCND_Line 0x40
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidInit(void);

void LCD_voidSendString(const char* Copy_pcString);
void LCD_voidNumAbove9(u16 Copy_u8Result);
void LCD_voidGoToXY(u8 Copy_u8XPOS,u8 Copy_u8YPOS);
void LCD_voidWriteSpecialCharacter(u8 *Copy_u8Pattern,u8 Copy_u8PatternNumber, u8 Copy_u8XPOS,u8 Copy_u8YPOS);

#endif /* LCD_INTERFACE_H_ */
