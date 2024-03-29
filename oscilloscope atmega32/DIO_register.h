/*
 * DIO_register.h
 *
 *  Created on: Sep 1, 2023
 *      Author: aminz
 */

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

#define PORTA_register    *((volatile u8*)(0x3B))
#define DDRA_register     *((volatile u8*)(0x3A))
#define PINA_register     *((volatile u8*)(0x39))

#define PORTB_register    *((volatile u8*)(0x38))
#define DDRB_register     *((volatile u8*)(0x37))
#define PINB_register     *((volatile u8*)(0x36))

#define PORTC_register    *((volatile u8*)(0x35))
#define DDRC_register     *((volatile u8*)(0x34))
#define PINC_register     *((volatile u8*)(0x33))

#define PORTD_register    *((volatile u8*)(0x32))
#define DDRD_register     *((volatile u8*)(0x31))
#define PIND_register     *((volatile u8*)(0x30))


#endif /* DIO_REGISTER_H_ */
