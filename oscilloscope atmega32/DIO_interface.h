/*
 * DIO_interface.h
 *
 *  Created on: Sep 1, 2023
 *      Author: aminz
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

#define PORT_INPUT 0x00
#define PORT_OUTPUT 0xFF

#define PIN_INPUT 0x00
#define PIN_OUTPUT 0x01

#define PORT_LOW 0x00
#define PORT_HIGH 0xFF

#define PIN_LOW 0x00
#define PIN_HIGH 0x01

void DIO_SetPortDirection(u8 PortNo, u8 Direction);
void DIO_SetPinDirection(u8 PortNo, u8 PinNo ,u8 Direction);

void DIO_SetPortValue(u8 PortNo, u8 Value);
void DIO_SetPinValue(u8 PortNo, u8 PinNo ,u8 Value);

u8 DIO_GetPortValue(u8 PortNo);
u8 DIO_GetPinValue(u8 PortNo, u8 PinNo);

void DIO_TogglePortValue(u8 PortNo);
void DIO_TogglePinValue(u8 PortNo, u8 PinNo);

#endif /* DIO_INTERFACE_H_ */
