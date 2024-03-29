/*
 * G_LCD_interface.h
 *
 *  Created on: Mar 3, 2024
 *      Author: 20128
 */

#ifndef G_LCD_INTERFACE_H_
#define G_LCD_INTERFACE_H_

#define G_LCD_OFF 0x3E
#define G_LCD_ON 0x3F

#define G_Y_StartAddress 0x40

#define G_X_Page_0 0xB8
#define G_X_Page_1 0xB9
#define G_X_Page_2 0xBA
#define G_X_Page_3 0xBB
#define G_X_Page_4 0xBC
#define G_X_Page_5 0xBD
#define G_X_Page_6 0xBE
#define G_X_Page_7 0xBF

#define G_Z_StartLine 0xC0

#define Left_Half 0
#define Right_Half 1

void G_LCD_Init(void);
void G_LCD_Write_Command(u8 Command);
void G_LCD_Write_Data(u8 Data);
//void  character(unsigned char sel);
void G_LCD_WriteChar(u8 uChar);
void G_LCD_Page_Select(u8 Page ,u8 Half);
#endif /* G_LCD_INTERFACE_H_ */
