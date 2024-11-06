/*
 * GPIO.C
 *
 * Created: 10/24/2024 9:35:12 PM
 *  Author: Abdelrhman Marzoq
*/ 


#include "GPIO.h"


static unsigned char volatile *DDRx[]  = {DDRA, DDRB, DDRC, DDRD};
static unsigned char volatile *PORTx[] = {PORTA, PORTB, PORTC, PORTD};
static unsigned char volatile *PINx[]  = {PINA, PINB, PINC, PIND};


void GPIO_Init(GPIO_Pin *GPIO_Config)
{
	if (GPIO_Config->Direction == INPUT)
		*DDRx[GPIO_Config->GPIOx] &= ~(GPIO_Config->PIN);	
	else if (GPIO_Config->Direction == INPUT_PULLUP)
	{
		*DDRx[GPIO_Config->GPIOx] &= ~(GPIO_Config->PIN);
		*PORTx[GPIO_Config->GPIOx] |= (GPIO_Config->PIN);
	}
	else if (GPIO_Config->Direction == OUTPUT)
		*DDRx[GPIO_Config->GPIOx] |= (GPIO_Config->PIN);
}

State GPIO_Read(GPIO_Pin *GPIO_Config)
{
	if (((*PINx[GPIO_Config->GPIOx]) & (GPIO_Config->PIN)))
		return HIGH;
	else 
		return LOW;
}

void GPIO_Write(GPIO_Pin *GPIO_Config, State Logic)
{
	if (Logic == LOW)
		*PORTx[GPIO_Config->GPIOx] &= ~(GPIO_Config->PIN);
	else if (Logic == HIGH)
		*PORTx[GPIO_Config->GPIOx] |= (GPIO_Config->PIN);
}

void GPIO_Toggle(GPIO_Pin *GPIO_Config)
{
	*PORTx[GPIO_Config->GPIOx] ^= (GPIO_Config->PIN);
}