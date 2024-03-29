/*
 * ADC_interface.h
 *
 *  Created on: Sep 29, 2023
 *      Author: aminz
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

#define ADC_result    *((volatile u16*)(0x24))

void ADC_Init(void);
u16 ADC_StartConversion_SYNC(u8 Channel); // No interrupt enable
void ADC_StartConversion_ASYNC(u8 Channel); //ISR _ ADCinterrupt enable
void ADC_Set_Callback_Address(void (*PTR) (void));
void ADC_Interrupt_Enable(void);
void ADC_Interrupt_Disable(void);
u32 ADC_Mapping(u32 Range_X_Minimum,u32 Range_X_Maximum,u32 Range_Y_Minimum,u32 Range_Y_Maximum,u32 X_reading);

#endif /* ADC_INTERFACE_H_ */
