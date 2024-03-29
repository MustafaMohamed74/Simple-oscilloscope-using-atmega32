/*
 * GLOBAL_INTERRUPT_program.c
 *
 *  Created on: Sep 22, 2023
 *      Author: aminz
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GLOBAL_INTERRUPT_register.h"
#include "GLOBAL_INTERRUPT_interface.h"

void GLOBAL_INTERRUPT_Enable(void){
	Set_Bit(SREG_register,I);
}
void GLOBAL_INTERRUPT_Disable(void){
	Clr_Bit(SREG_register,I);
}








