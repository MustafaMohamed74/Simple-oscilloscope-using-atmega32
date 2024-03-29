/*
 * TIMER_program.c
 *
 *  Created on: Oct 6, 2023
 *      Author: 20128
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_register.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"

void (* TIMER0_CTC_CALLBACK_PTR) (void)=NULL;
void (* TIMER0_OVF_CALLBACK_PTR) (void)=NULL;

void TIMER0_Init(void){
	//Select mode
	Clr_Bit(TCCR0_register,WGM00);
	Clr_Bit(TCCR0_register,WGM01);

	//set output mode
	Clr_Bit(TCCR0_register,COM00);
	Clr_Bit(TCCR0_register,COM01);

	//select prescalar
	Set_Bit(TCCR0_register,CS00);
	Set_Bit(TCCR0_register,CS01);
	Set_Bit(TCCR0_register,CS02);

}
void TIMER0_Stop(void){
	Clr_Bit(TCCR0_register,CS00);
	Clr_Bit(TCCR0_register,CS01);
	Clr_Bit(TCCR0_register,CS02);
}

void TIMER0_OVF_Interrupt_Enable(void){
	Set_Bit(TIMSK_register,TOIE0);
}
void TIMER0_OVF_Interrupt_Disable(void){
	Clr_Bit(TIMSK_register,TOIE0);
}
void TIMER0_CTC_Interrupt_Enable(void){
	Set_Bit(TIMSK_register,OCIE0);
}
void TIMER0_CTC_Interrupt_Disable(void){
	Clr_Bit(TIMSK_register,OCIE0);
}

void TIMER0_OVF_Set_Callback_Address(void (*PTR) (void)){
	TIMER0_OVF_CALLBACK_PTR=PTR;
}
void TIMER0_CTC_Set_Callback_Address(void (*PTR) (void)){
	TIMER0_CTC_CALLBACK_PTR=PTR;
}

void TIMER0_Set_TCNT0_Register(u8 Value){

	TCNT0_register=Value;

}
void TIMER0_Set_OCR0_Register(u8 Value){
	OCR0_register=Value;

}

u8 TIMER0_Get_TCNT0_Register(void){
	u8 CurrentValue;
	CurrentValue=TCNT0_register;
	return CurrentValue;
}
u8 TIMER0_Get_OCR0_Register(void){
	u8 CurrentValue;
	CurrentValue=OCR0_register;
	return CurrentValue;
}
//u32 TIMER_Preload_time(u32 Time_Sec){
//	u32 preload;
//if ((Time_Sec*(10^6))==OVT){
//	return Time_Sec ;
//}
//else if ((Time_Sec*(10^6))<OVT){
//		preload=((2)^resolution)*(1-(Time_Sec/OVT));
//
//}
//#endif
//}

//TIMER CTC ISR
void __vector_10 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_10 (void){
	TIMER0_CTC_CALLBACK_PTR();
}
//TIMER OVF ISR
void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_11 (void){
	TIMER0_OVF_CALLBACK_PTR();
}

//TIMER1
void (* TIMER1_CTC_A_CALLBACK_PTR) (void)=NULL;
void (* TIMER1_CTC_B_CALLBACK_PTR) (void)=NULL;
void (* TIMER1_OVF_CALLBACK_PTR) (void)=NULL;
void (* TIMER1_ICI_CALLBACK_PTR) (void)=NULL;

void TIMER1_Init(void){
	//selsect mode
	Clr_Bit(TCCR1B_register,WGM12);
	Clr_Bit(TCCR1B_register,WGM13);
	Clr_Bit(TCCR1A_register,WGM10);
	Clr_Bit(TCCR1A_register,WGM11);

	Clr_Bit(TCCR1A_register,COM1A0);
	Clr_Bit(TCCR1A_register,COM1A1);
	Clr_Bit(TCCR1A_register,COM1B0);
	Clr_Bit(TCCR1A_register,COM1A1);

	Set_Bit(TCCR1B_register,CS10);
	Set_Bit(TCCR1B_register,CS11);
	Clr_Bit(TCCR1B_register,CS12);


	//out mode


}

void TIMER1_CLOSE(void){
	    Clr_Bit(TCCR1B_register,CS11);
		Clr_Bit(TCCR1B_register,CS10);
		Clr_Bit(TCCR1B_register,CS12);
}

void TIMER1_OVF_Interrupt_Enable(void){
	Set_Bit(TIMSK_register,TOIE1);
}
void TIMER1_OVF_Interrupt_Disable(void){
	Clr_Bit(TIMSK_register,TOIE1);

}

void TIMER1_CTC_A_Interrupt_Enable(void){
	Set_Bit(TIMSK_register,OCIE1A);
}
void TIMER1_CTC_A_Interrupt_Disable(void){
	Clr_Bit(TIMSK_register,OCIE1A);
}

void TIMER1_CTC_B_Interrupt_Enable(void){
	Set_Bit(TIMSK_register,OCIE1B);
}

void TIMER1_CTC_B_Interrupt_Disable(void){
	Clr_Bit(TIMSK_register,OCIE1B);
}

void TIMER1_ICI_Interrupt_Enable(void){
	Set_Bit(TIMSK_register,TICIE1);
}
void TIMER1_ICI_Interrupt_Disable(void){
	Clr_Bit(TIMSK_register,TICIE1);
}
void TIMER1_ICI_Interrupt_Set_Edge(u8 edge){
	switch(edge){
	case RISING_EDGE:
		Set_Bit(TCCR1B_register,ICES1);
		break;
	case FALLING_EDGE:
		Clr_Bit(TCCR1B_register,ICES1);
		break;
	default:
		break;
	}
}
void TIMER1_ICI_Set_Callback_Address(void (*PTR) (void)){
	TIMER1_ICI_CALLBACK_PTR=PTR;
}

void TIMER1_OVF_Set_Callback_Address(void (*PTR) (void)){
	TIMER1_OVF_CALLBACK_PTR=PTR;
}
void TIMER1_CTC_A_Set_Callback_Address(void (*PTR) (void)){
	TIMER1_CTC_A_CALLBACK_PTR=PTR;
}
void TIMER1_CTC_B_Set_Callback_Address(void (*PTR) (void)){
	TIMER1_CTC_B_CALLBACK_PTR=PTR;
}


void TIMER1_Set_TCNT1_Register(u16 Value){
	TCNT1_register=Value;
}
void TIMER1_Set_OCR1A_Register(u16 Value){
	OCR1A_register=Value;
}
void TIMER1_Set_OCR1B_Register(u16 Value){
	OCR1B_register=Value;
}
void TIMER1_Set_ICI_Register(u16 Value){
	ICR1_register=Value;
}

u16 TIMER1_Get_TCNT1_Register(void){
	return TCNT1_register;
}
u16 TIMER1_Get_OCR1A_Register(void){
	return OCR1A_register;
}
u16 TIMER1_Get_OCR1B_Register(void){
	return OCR1B_register;
}
u16 TIMER1_Get_ICI_Register(void){
	return ICR1_register;
}
void __vector_6 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_6 (void){
	TIMER1_ICI_CALLBACK_PTR();
}
void __vector_7 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_7 (void){
	TIMER1_CTC_A_CALLBACK_PTR();
}
void __vector_8 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_8 (void){
	TIMER1_CTC_B_CALLBACK_PTR();
}
void __vector_9 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_9 (void){
	TIMER1_OVF_CALLBACK_PTR();
}


//TIMER2
void (* TIMER2_CTC_CALLBACK_PTR) (void)=NULL;
void (* TIMER2_OVF_CALLBACK_PTR) (void)=NULL;

void TIMER2_Init(void){
	//Select mode
	Clr_Bit(TCCR2_register,WGM20);
	Clr_Bit(TCCR2_register,WGM21);

	//set output mode
	Clr_Bit(TCCR2_register,COM20);
	Clr_Bit(TCCR2_register,COM21);

	//select prescalar
	Clr_Bit(TCCR2_register,CS20);
	Set_Bit(TCCR2_register,CS21);
	Clr_Bit(TCCR2_register,CS22);

	//Set_Bit(ASSR_register,AS2);
}

void TIMER2_CTC_Interrupt_Enable(void){
	Set_Bit(TIMSK_register,OCIE2);
}

void TIMER2_CTC_Interrupt_Disable(void){
	Clr_Bit(TIMSK_register,OCIE2);
}

void TIMER2_OVF_Interrupt_Enable(void){
	Set_Bit(TIMSK_register,TOIE2);
}
void TIMER2_OVF_Interrupt_Disable(void){
	Clr_Bit(TIMSK_register,TOIE2);

}

void TIMER2_Set_OCR2_Register(u8 Value){
	OCR2_register=Value;
}
u8 TIMER2_Get_OCR2_Register(void){
	return OCR2_register;
}

void TIMER2_Set_TCNT2_Register(u8 Value){
	TCNT2_register=Value;
}
u8 TIMER2_Get_TCNT2_Register(void){
	return TCNT2_register;
}

void TIMER2_OVF_Set_Callback_Address(void (*PTR) (void)){
	TIMER2_OVF_CALLBACK_PTR=PTR;
}
void TIMER2_CTC_Set_Callback_Address(void (*PTR) (void)){
	TIMER2_CTC_CALLBACK_PTR=PTR;
}
void __vector_4 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_4 (void){
	TIMER2_CTC_CALLBACK_PTR();
}
//TIMER OVF ISR
void __vector_5 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_5 (void){
	TIMER2_OVF_CALLBACK_PTR();
}


