/*
 * DIO_program.c
 *
 *  Created on: Sep 1, 2023
 *      Author: aminz
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"

void DIO_SetPortDirection(u8 PortNo, u8 Direction){
	switch(PortNo){
	case PORT_A:
		DDRA_register=Direction;
		break;
	case PORT_B:
		DDRB_register=Direction;
		break;
	case PORT_C:
		DDRC_register=Direction;
		break;
	case PORT_D:
		DDRD_register=Direction;
		break;
	default:
		break;
	}
}

void DIO_SetPinDirection(u8 PortNo, u8 PinNo ,u8 Direction){
	if(PinNo>=PIN_0 && PinNo<=PIN_7){
		switch(PortNo){
		case PORT_A:
			if(Direction==PIN_OUTPUT){
				Set_Bit(DDRA_register,PinNo);
			}
			else if(Direction==PIN_INPUT){
				Clr_Bit(DDRA_register,PinNo);
			}
			else{

			}
			break;
		case PORT_B:
			if(Direction==PIN_OUTPUT){
				Set_Bit(DDRB_register,PinNo);
			}
			else if(Direction==PIN_INPUT){
				Clr_Bit(DDRB_register,PinNo);
			}
			else{

			}
			break;
		case PORT_C:
			if(Direction==PIN_OUTPUT){
				Set_Bit(DDRC_register,PinNo);
			}
			else if(Direction==PIN_INPUT){
				Clr_Bit(DDRC_register,PinNo);
			}
			else{

			}
			break;
		case PORT_D:
			if(Direction==PIN_OUTPUT){
				Set_Bit(DDRD_register,PinNo);
			}
			else if(Direction==PIN_INPUT){
				Clr_Bit(DDRD_register,PinNo);
			}
			else{

			}
			break;
		default:
			break;
		}
	}
	else{

	}
}

void DIO_SetPortValue(u8 PortNo, u8 Value){
	switch(PortNo){
	case PORT_A:
		PORTA_register=Value;
		break;
	case PORT_B:
		PORTB_register=Value;
		break;
	case PORT_C:
		PORTC_register=Value;
		break;
	case PORT_D:
		PORTD_register=Value;
		break;
	default:
		break;
	}

}
void DIO_SetPinValue(u8 PortNo, u8 PinNo ,u8 Value){
	if(PinNo>=PIN_0 && PinNo<=PIN_7){
		switch(PortNo){
		case PORT_A:
			if(Value==PIN_HIGH){
				Set_Bit(PORTA_register,PinNo);
			}
			else if(Value==PIN_LOW){
				Clr_Bit(PORTA_register,PinNo);
			}
			else{

			}
			break;
		case PORT_B:
			if(Value==PIN_HIGH){
				Set_Bit(PORTB_register,PinNo);
			}
			else if(Value==PIN_LOW){
				Clr_Bit(PORTB_register,PinNo);
			}
			else{

			}
			break;
		case PORT_C:
			if(Value==PIN_HIGH){
				Set_Bit(PORTC_register,PinNo);
			}
			else if(Value==PIN_LOW){
				Clr_Bit(PORTC_register,PinNo);
			}
			else{

			}
			break;
		case PORT_D:
			if(Value==PIN_HIGH){
				Set_Bit(PORTD_register,PinNo);
			}
			else if(Value==PIN_LOW){
				Clr_Bit(PORTD_register,PinNo);
			}
			else{

			}
			break;
		default:
			break;
		}
	}
	else{

	}
}

u8 DIO_GetPortValue(u8 PortNo){

	u8 local_return;
	switch(PortNo){
	case PORT_A:
		local_return=PINA_register;
		break;
	case PORT_B:
		local_return=PINB_register;
		break;
	case PORT_C:
		local_return=PINC_register;
		break;
	case PORT_D:
		local_return=PIND_register;
		break;
	default:
		break;
	}

	return local_return;

}
u8 DIO_GetPinValue(u8 PortNo, u8 PinNo){
	u8 local_return;
	if(PinNo>=PIN_0 && PinNo<=PIN_7){
		switch(PortNo){
		case PORT_A:
			local_return=Get_Bit(PINA_register,PinNo);
			break;
		case PORT_B:
			local_return=Get_Bit(PINB_register,PinNo);
			break;
		case PORT_C:
			local_return=Get_Bit(PINC_register,PinNo);
			break;
		case PORT_D:
			local_return=Get_Bit(PIND_register,PinNo);
			break;
		default:
			break;
		}
	}
	else{

	}
	return local_return;
}


void DIO_TogglePortValue(u8 PortNo){
	switch(PortNo){
		case PORT_A:
			PORTA_register=PORTA_register^0xFF;
			break;
		case PORT_B:
			PORTB_register=PORTB_register^0xFF;
			break;
		case PORT_C:
			PORTC_register=PORTC_register^0xFF;
			break;
		case PORT_D:
			PORTD_register=PORTD_register^0xFF;
			break;
		default:
			break;
		}
}

void DIO_TogglePinValue(u8 PortNo, u8 PinNo){
	if(PinNo>=PIN_0 && PinNo<=PIN_7){
		switch(PortNo){
		case PORT_A:
			Tog_Bit(PORTA_register,PinNo);
			break;
		case PORT_B:
			Tog_Bit(PORTB_register,PinNo);
			break;
		case PORT_C:
			Tog_Bit(PORTC_register,PinNo);
			break;
		case PORT_D:
			Tog_Bit(PORTD_register,PinNo);
			break;
		default:
			break;
		}
	}
	else{

	}
}
