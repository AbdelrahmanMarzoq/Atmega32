/*
 * ADC.h
 *
 * Created: 11/6/2024 5:37:33 PM
 *  Author: Abdelrhman Marzoq
 */ 


#ifndef ADC_H_
#define ADC_H_


#include "Atmega32.h"
#include <avr/interrupt.h>


typedef enum
{
	CH0,
	CH1,
	CH2,
	CH3,
	CH4,
	CH5,
	CH6,
	CH7
}CH_t;

typedef enum
{
	Vref_External = 0x00, 
	Vref_5        = 0x40,
	Vref_2_56     = 0xC0
}Vref;

typedef enum
{
	Clock_Prescaller_By_2,
	Clock_Prescaller_By_4 = 2,
	Clock_Prescaller_By_8 = 3,
	Clock_Prescaller_By_16 = 4,
	Clock_Prescaller_By_32,
	Clock_Prescaller_By_64,
	Clock_Prescaller_By_128	
}Clock_Prescaller;

typedef enum
{
	IRQ_Disable,
	IRQ_Enable	= 0b1 << 3
}IRQ;

typedef struct
{
	CH_t				CHx;
	Vref				Vref_Mode;
	Clock_Prescaller	Factor;
	IRQ					IRQ_Mode;
}ADC_Pin;



void ADC_init(ADC_Pin *ADC_Conf);
void ADC_init_CALL_BACK(void (*CALL_BACK)(void));
unsigned short ADC_Read(ADC_Pin *ADC_Conf);


#endif /* ADC_H_ */