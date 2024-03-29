/*,0
 * main.c
 *
 *  Created on: Sep 1, 2023
 *      Author: aminz
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "G_LCD_interface.h"
#include "TIMER_interface.h"
#include "GLOBAL_INTERRUPT_interface.h"
#include"ADC_interface.h"
#include "avr/delay.h"
#include "cycles.h"
#define FALLING_EDGE  0
#define RISING_EDGE   1

#define F_CPU 16000000
#define prescaler 64

u8 G_u8_flag ;

u16 G_u16_T_OFF;
u16 G_u16_T_ON;

u32 G_u32_Frequency;
u8 G_u8_DutyCycle;
u8 my_duty ;
u8 j ;

u32 timer0_ov ;

void ICU_V_ISR(void);
void rotate(void);
void timer0(void);
void fill(void);

void Hz(u32 freq);
void KHz(u32 freq);
void MHz(u32 freq);

int main(void){
	G_LCD_Init();



	TIMER1_Init();
	TIMER1_ICI_Interrupt_Set_Edge(RISING_EDGE);
	TIMER1_ICI_Set_Callback_Address(ICU_V_ISR);
	TIMER1_ICI_Interrupt_Enable();

	TIMER0_Init();
	TIMER0_OVF_Set_Callback_Address(timer0);
	TIMER0_OVF_Interrupt_Enable();

	GLOBAL_INTERRUPT_Enable();
	fill();

	while(2>1){

		G_LCD_Page_Select(G_X_Page_1,Left_Half);
		G_LCD_WriteChar(' ');
		G_LCD_WriteChar('F');
		G_LCD_WriteChar('r');
		G_LCD_WriteChar('e');
		G_LCD_WriteChar('q');
		G_LCD_WriteChar('u');
		G_LCD_WriteChar('e');
		G_LCD_WriteChar('n');
		G_LCD_WriteChar('c');
		G_LCD_WriteChar('y');
		G_LCD_WriteChar(' ');

		G_u8_DutyCycle = (G_u16_T_ON*100)/(G_u16_T_ON+G_u16_T_OFF);
		G_u32_Frequency= (F_CPU/prescaler)/((G_u16_T_ON+G_u16_T_OFF));
		my_duty=ADC_Mapping(0,100,0,24,G_u8_DutyCycle);
		G_LCD_Page_Select(G_X_Page_3,Left_Half);
		if( G_u32_Frequency >= 1000000) {
			MHz(G_u32_Frequency);
		}
		else if ( G_u32_Frequency >= 1000){
			KHz(G_u32_Frequency);
		}
		else if (G_u32_Frequency < 1000){
			Hz(G_u32_Frequency);
		}
		G_LCD_Page_Select(G_X_Page_1,Right_Half);
		G_LCD_WriteChar(' ');
		G_LCD_WriteChar('D');
		G_LCD_WriteChar('u');
		G_LCD_WriteChar('t');
		G_LCD_WriteChar('y');
		G_LCD_WriteChar(' ');
		G_LCD_WriteChar('c');
		G_LCD_WriteChar('y');
		G_LCD_WriteChar('c');
		G_LCD_WriteChar('l');
		G_LCD_WriteChar('e');

		G_LCD_Page_Select(G_X_Page_3,Right_Half);
		G_LCD_WriteChar(' ');
		G_LCD_WriteChar(' ');
		G_LCD_WriteChar(' ');

		G_LCD_WriteChar(((G_u8_DutyCycle)/100)%10 + 48);
		G_LCD_WriteChar(((G_u8_DutyCycle)/10)%10 + 48);
		G_LCD_WriteChar(( G_u8_DutyCycle%10) + 48);
		G_LCD_WriteChar(' ');
		G_LCD_WriteChar(' ');
		G_LCD_WriteChar(' ');
		G_LCD_WriteChar(' ');
		G_LCD_WriteChar(' ');


		G_LCD_Page_Select(G_X_Page_5,Left_Half);
		u8 i;
		for(u8 j=0 ; j<2 ; j++){
			for( i =0  ; i <= 32 ; i++){
				G_LCD_Write_Data(cycles_array[my_duty][i]);
			}
		}
		G_LCD_Page_Select(G_X_Page_5,Right_Half);
		for(u8 k=0 ; k<2 ; k++){
			for( i =0  ; i <= 32 ; i++){
				G_LCD_Write_Data(cycles_array[my_duty][i]);
			}
		}
		for(u8 i=0 ; i<13 ; i++){
			rotate();

		}

		TIMER1_ICI_Interrupt_Enable();
	}
	return 0 ;
}
void rotate(void){
	u8 temp ;
	temp = cycles_array[my_duty][32];
	for(u8 i=32 ; i !=0 ;i--){

		cycles_array[my_duty][i]=cycles_array[my_duty][i-1];

	}
	cycles_array[my_duty][0]=temp;
}
void fill(void){
	G_LCD_Page_Select(G_X_Page_0,Left_Half);
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');

	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_Page_Select(G_X_Page_0,Right_Half);
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');

	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_Page_Select(G_X_Page_2,Left_Half);
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');

	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_Page_Select(G_X_Page_2,Right_Half);
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');

	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_Page_Select(G_X_Page_4,Left_Half);
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');

	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_Page_Select(G_X_Page_4,Right_Half);
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');

	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_Page_Select(G_X_Page_6,Left_Half);
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');

	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_Page_Select(G_X_Page_6,Right_Half);
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');

	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_Page_Select(G_X_Page_7,Left_Half);
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');

	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_Page_Select(G_X_Page_7,Right_Half);
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');

	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
}
void ICU_V_ISR(void){

	switch(G_u8_flag){
	case 0:
		G_u16_T_ON = 0 ;
		G_u16_T_OFF = 0 ;
		TIMER1_Set_TCNT1_Register(0);
		TIMER1_ICI_Interrupt_Set_Edge(FALLING_EDGE);
		G_u8_flag++;
		break ;
	case 1 :
		G_u16_T_ON = TIMER1_Get_ICI_Register();
		TIMER1_Set_TCNT1_Register(0);
		TIMER1_ICI_Interrupt_Set_Edge(RISING_EDGE);
		G_u8_flag++;
		break;
	case 2 :
		G_u16_T_OFF = TIMER1_Get_ICI_Register();
		G_u8_flag ++ ;
		TIMER1_ICI_Interrupt_Disable();
		break ;
	case 3 :
		G_u8_flag=0 ;
		break ;

	default :
		break;

	}
}

void timer0(void){
	timer0_ov ++ ;
}
void MHz(u32 freq){
	//	LCD_Write_String("Freq =", 6 );
	G_LCD_WriteChar(((freq%100000000)/10000000) + '0' );
	G_LCD_WriteChar(((freq%10000000)/1000000) + '0' );
	G_LCD_WriteChar('.');
	G_LCD_WriteChar(((freq%1000000)/100000) + '0' );
	G_LCD_WriteChar(((freq%100000)/10000) + '0' );
	G_LCD_WriteChar(((freq%10000)/1000) + '0' );
	G_LCD_WriteChar('M');
	G_LCD_WriteChar('H');
	G_LCD_WriteChar('z');

	//	LCD_Write_String("MHz", 3 );

}
void KHz(u32 freq){
	//	LCD_Write_String("Freq =", 6 );
	G_LCD_WriteChar(' ');

	G_LCD_WriteChar(((freq%1000000)/100000) + '0' );
	G_LCD_WriteChar(((freq%100000)/10000) + '0' );
	G_LCD_WriteChar(((freq%10000)/1000) + '0' );

	//	G_LCD_WriteChar(((freq%1000)/100) +   '0' );
	//	G_LCD_WriteChar(((freq%100)/10) +     '0' );
	//	G_LCD_WriteChar(((freq%10)/1) +        '0' );
	G_LCD_WriteChar('K');
	G_LCD_WriteChar('H');
	G_LCD_WriteChar('z');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');

	//	LCD_Write_String("KHz", 3 );

}
void Hz(u32 freq){
	//	LCD_Write_String("Freq =", 6 );
	G_LCD_WriteChar(((freq%1000)/100) +   '0' );
	G_LCD_WriteChar(((freq%100)/10) +     '0' );
	G_LCD_WriteChar(((freq%10)/1) +        '0' );
	G_LCD_WriteChar('H');
	G_LCD_WriteChar('z');
	G_LCD_WriteChar(' ');
	G_LCD_WriteChar(' ');

	//	LCD_Write_String("Hz", 2 );
}
