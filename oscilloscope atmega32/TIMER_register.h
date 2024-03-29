/*
 * TIMER_register.h
 *
 *  Created on: Oct 6, 2023
 *      Author: 20128
 */

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0_register  *((volatile u8*)(0x53))
#define TCNT0_register  *((volatile u8*)(0x52))
#define TIMSK_register  *((volatile u8*)(0x59))
#define TIFR_register  *((volatile u8*)(0x58))
#define OCR0_register  *((volatile u8*)(0x5C))



#define FOC0  7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02  2
#define CS01  1
#define CS00  0

#define OCIE2    7
#define TOIE2    6
#define TICIE1   5
#define OCIE1A   4
#define OCIE1B   3
#define TOIE1    2
#define OCIE0    1
#define TOIE0    0

#define OCF2      7
#define TOV2      6
#define ICF1      5
#define OCF1A     4
#define OCF1B     3
#define TOV1      2
#define OCF0      1
#define TOV0      0


#define TCCR2_register  *((volatile u8*)(0x45))
#define TCNT2_register  *((volatile u8*)(0x44))
#define OCR2_register  *((volatile u8*)(0x43))
#define ASSR_register  *((volatile u8*)(0x42))
//TCCR2
#define FOC2  7
#define WGM20 6
#define COM21 5
#define COM20 4
#define WGM21 3
#define CS22  2
#define CS21  1
#define CS20  0

//TIMSK
#define OCIE2    7
#define TOIE2    6
#define TICIE1   5
#define OCIE1A   4
#define OCIE1B   3
#define TOIE1    2
#define OCIE0    1
#define TOIE0    0

//ASSR
#define AS2    3
#define TCN2UB 2
#define OCR2UB 1
#define TCR2UB 0
//TIMER1
#define TCNT1_register  *((volatile u16*)(0x4C))
#define OCR1A_register  *((volatile u16*)(0x4A))
#define OCR1B_register  *((volatile u16*)(0x48))
#define ICR1_register   *((volatile u16*)(0x46))
#define TCCR1B_register  *((volatile u8*)(0x4E))
#define TCCR1A_register  *((volatile u8*)(0x4F))

//TCCR1A

#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

//TCCR1B
#define ICNC1  7
#define ICES1  6
//#define –      5
#define WGM13  4
#define WGM12  3
#define CS12   2
#define CS11   1
#define CS10   0

#endif /* TIMER_REGISTER_H_ */
