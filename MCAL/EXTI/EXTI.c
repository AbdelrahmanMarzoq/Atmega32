/*
 * EXTI.c
 *
 * Created: 10/25/2024 5:10:04 PM
 *  Author: Abdelrhman Marzoq
 */ 


#include "EXTI.h"

void (*PTR_ISR[3])(void);



void EXTI_Enable(EXTI_Pin *EXTI_Config)
{
	
	// Enable Mask For EXTIx
	GICR |= EXTI_Config->EXTI_Number;
	
	GPIO_Pin EXTI_Pin;
	// Store Call back Fun for each ISR
	if (EXTI_Config->EXTI_Number == EXTI0)
	{
		PTR_ISR[0] = EXTI_Config->ISR_CallBack;
		EXTI_Pin.Direction = INPUT;
		EXTI_Pin.GPIOx = GPIOD;
		EXTI_Pin.PIN = PIN2;
	}
	
	else if (EXTI_Config->EXTI_Number == EXTI1) 
	{
		PTR_ISR[1] = EXTI_Config->ISR_CallBack;
		EXTI_Pin.Direction = INPUT;
		EXTI_Pin.GPIOx = GPIOD;
		EXTI_Pin.PIN = PIN3;
	}
	else if (EXTI_Config->EXTI_Number == EXTI2)
	{
		PTR_ISR[2] = EXTI_Config->ISR_CallBack;
		EXTI_Pin.Direction = INPUT;
		EXTI_Pin.GPIOx = GPIOB;
		EXTI_Pin.PIN = PIN2;
	}
	GPIO_Init(&EXTI_Pin);
	
	
	
	// Init Sensing Interrupt
	if (EXTI_Config->Mode == LOW_LEVEL)
	{
		if (EXTI_Config->EXTI_Number == EXTI0)
			MCUCR &= ~(0b11 << 0);
		else if (EXTI_Config->EXTI_Number == EXTI1)
			MCUCR &= ~(0b11 << 2);	
	}
	else if (EXTI_Config->Mode == Any_Change)
	{
		if (EXTI_Config->EXTI_Number == EXTI0)
		{
			MCUCR &= ~(0b1 << 1);
			MCUCR |= (0b1 << 0);
		}
		else if (EXTI_Config->EXTI_Number == EXTI1)
		{
			MCUCR &= ~(0b1 << 3);
			MCUCR |= (0b1 << 2);		
		}
	}
	else if (EXTI_Config->Mode == Falling_Edge)
	{
		if (EXTI_Config->EXTI_Number == EXTI0)
		{
			MCUCR |= (0b1 << 1);
			MCUCR &= ~(0b1 << 0);
		}
		else if (EXTI_Config->EXTI_Number == EXTI1)
		{
			MCUCR |= (0b1 << 3);
			MCUCR &= ~(0b1 << 2);
		}
		else if (EXTI_Config->EXTI_Number == EXTI2)
		{
			MCUCSR &= ~(0b1 << 7);
		}
	}
	else if (EXTI_Config->Mode == Rising_Edge)
	{
		if (EXTI_Config->EXTI_Number == EXTI0)
			MCUCR |= (0b11 << 0);
		else if (EXTI_Config->EXTI_Number == EXTI1)
			MCUCR |= (0b11 << 2);
		else if (EXTI_Config->EXTI_Number == EXTI2)
			MCUCSR |= (0b1 << 7);
	}
	// Enable GLOBAL Interrupt
	SREG |= 1 << 7;
}


void EXTI_Disable(EXTI_Pin *EXTI_Config)
{
	// Disable INT
	GICR &= ~(GICR |= EXTI_Config->EXTI_Number);

	// De Init Global Array of ISR Functions
	if (EXTI_Config->EXTI_Number == EXTI0) PTR_ISR[0] = 0;
	else if (EXTI_Config->EXTI_Number == EXTI1) PTR_ISR[1] = 0;
	else if (EXTI_Config->EXTI_Number == EXTI2) PTR_ISR[2] = 0;
}



void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	// Clear Flag
	GIFR &= ~(0b1 << 6);
	PTR_ISR[0]();
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	// Clear Flag
	GIFR &= ~(0b1 << 7);
	PTR_ISR[1]();
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	// Clear Flag
	GIFR &= ~(0b1 << 5);
	PTR_ISR[3]();
}

