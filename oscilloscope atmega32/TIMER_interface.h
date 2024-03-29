/*
 * TIMER_interface.h
 *
 *  Created on: Oct 6, 2023
 *      Author: 20128
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

//Timer0

void TIMER0_Init(void);
void TIMER0_Stop(void);

void TIMER0_OVF_Interrupt_Enable(void);
void TIMER0_OVF_Interrupt_Disable(void);
void TIMER0_CTC_Interrupt_Enable(void);
void TIMER0_CTC_Interrupt_Disable(void);

void TIMER0_OVF_Set_Callback_Address(void (*PTR) (void));
void TIMER0_CTC_Set_Callback_Address(void (*PTR) (void));

void TIMER0_Set_TCNT0_Register(u8 Value);
void TIMER0_Set_OCR0_Register(u8 Value);

u8 TIMER0_Get_TCNT0_Register(void);
u8 TIMER0_Get_OCR0_Register(void);

u32 TIMER_Desired_time(u32 Time_Sec);


//TIMER1

void TIMER1_Init(void);
void TIMER1_CLOSE(void);

void TIMER1_OVF_Interrupt_Enable(void);
void TIMER1_OVF_Interrupt_Disable(void);

void TIMER1_CTC_A_Interrupt_Enable(void);
void TIMER1_CTC_A_Interrupt_Disable(void);

void TIMER1_CTC_B_Interrupt_Enable(void);
void TIMER1_CTC_B_Interrupt_Disable(void);

void TIMER1_ICI_Interrupt_Enable(void);
void TIMER1_ICI_Interrupt_Disable(void);
void TIMER1_ICI_Interrupt_Set_Edge(u8 edge);
void TIMER1_ICI_Set_Callback_Address(void (*PTR) (void));

void TIMER1_OVF_Set_Callback_Address(void (*PTR) (void));
void TIMER1_CTC_A_Set_Callback_Address(void (*PTR) (void));
void TIMER1_CTC_B_Set_Callback_Address(void (*PTR) (void));


void TIMER1_Set_TCNT1_Register(u16 Value);
void TIMER1_Set_OCR1A_Register(u16 Value);
void TIMER1_Set_OCR1B_Register(u16 Value);
void TIMER1_Set_ICI_Register(u16 Value);

u16 TIMER1_Get_TCNT1_Register(void);
u16 TIMER1_Get_OCR1A_Register(void);
u16 TIMER1_Get_OCR1B_Register(void);
u16 TIMER1_Get_ICI_Register(void);


//TIMER2

void TIMER2_Init(void);

void TIMER2_CTC_Interrupt_Enable(void);
void TIMER2_CTC_Interrupt_Disable(void);
void TIMER2_OVF_Interrupt_Enable(void);
void TIMER2_OVF_Interrupt_Disable(void);

void TIMER2_Set_OCR2_Register(u8 Value);
u8 TIMER2_Get_OCR2_Register(void);

void TIMER2_Set_TCNT2_Register(u8 Value);
u8 TIMER2_Get_TCNT2_Register(void);

void TIMER2_OVF_Set_Callback_Address(void (*PTR) (void));
void TIMER2_CTC_Set_Callback_Address(void (*PTR) (void));


#endif /* TIMER_INTERFACE_H_ */
