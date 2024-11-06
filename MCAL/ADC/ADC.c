/*
 * ADC.c
 *
 * Created: 11/6/2024 5:37:26 PM
 *  Author: Abdelrhman Marzoq
 */ 
#include "ADC.h"


void (* Global_PTR)(void);
void ADC_init(ADC_Pin *ADC_Conf)
{
	// Select Vref Mode 
	ADMUX |= ADC_Conf->Vref_Mode;
	
	// Init IRQ 
	ADCSRA |= ADC_Conf->IRQ_Mode;	
	
	if (ADC_Conf->IRQ_Mode)
		// Enable GLOBAL Interrupt
		SREG |= 1 << 7;
	
	// Init CLOCK
	ADCSRA |= ADC_Conf->Factor;
	
	// Enable ADC
	ADCSRA |= 0b1 << 7; 
}


void ADC_init_CALL_BACK(void (*CALL_BACK)(void))
{
	// Take The Function Cal Back 
	// Need to make Array For 7 Channel (Future)
	Global_PTR = CALL_BACK;
}


unsigned short ADC_Read(ADC_Pin *ADC_Conf)
{	
	
	unsigned short Data = 0;
	// Select Channel
	ADMUX &= ~(0b1111 << 0);
	ADMUX |= ADC_Conf->CHx;
	DDRA &= ~(ADC_Conf->CHx);
	
	
	// Start Conversion
	ADCSRA |= 0b1 << 6;
	
	// Polling untill Complete Conversion can make with IRQ
	while(!(ADCSRA & (1 << 4)));

	// Clear Flag
	ADCSRA &= ~(0b1 << 4);
	
	// Read Data As Right not Left
	Data = (ADCL | ((ADCH & (0x03)) << 8) );
	
	// Return Data
	return Data;	
	
}