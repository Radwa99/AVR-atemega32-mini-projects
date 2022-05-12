/*
 * LCD_interface.h
 *
 *  Created on: Aug 15, 2021
 *      Author: Radwa
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidInit(void);
void LCD_voidSendString(const char* Copy_pcString);
void LCD_voidCursor(u8 Copy_u8XPos,u8 Copy_u8YPos);
void LCD_voidWriteSpecialCharacter(u8* Copy_u8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8Xpos,u8 Copy_u8Ypos);
#endif /* LCD_INTERFACE_H_ */
