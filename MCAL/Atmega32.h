/*
 * Atmega32.h
 *
 * Created: 10/24/2024 9:36:09 PM
 *  Author: Abdelrhman Marzoq
 */ 

#ifndef ATMEGA32_H_
#define ATMEGA32_H_
#include <stdint.h>

//				Registers For AVR

#define SREG        (*((volatile unsigned char *)0x5F))
		
//				End AVR Section

//				Registers For GPIO
#define PORTA        (((volatile unsigned char *)0x3B))
#define DDRA		 (((volatile unsigned char *)0x3A))
#define PINA		 (((volatile unsigned char *)0x39))

#define PORTB		 (((volatile unsigned char *)0x38))
#define DDRB		 (((volatile unsigned char *)0x37))
#define PINB		 (((volatile unsigned char *)0x36))

#define PORTC		 (((volatile unsigned char *)0x35))
#define DDRC		 (((volatile unsigned char *)0x34))
#define PINC		 (((volatile unsigned char *)0x33))

#define PORTD		 (((volatile unsigned char *)0x32))
#define DDRD		 (((volatile unsigned char *)0x31))
#define PIND		 (((volatile unsigned char *)0x30))
//				End GPIO Section


//				Registers For EXTI

#define MCUCR        (*((volatile unsigned char *)0x55))
#define MCUCSR       (*((volatile unsigned char *)0x54))
#define GICR		 (*((volatile unsigned char *)0x5B))
#define GIFR		 (*((volatile unsigned char *)0x5A))

//				End EXTI Section


//				Registers For USART

#define UDR      	(*((volatile unsigned char *)0x2C))
#define UCSRA      	(*((volatile unsigned char *)0x2B))
#define UCSRB      	(*((volatile unsigned char *)0x2A))
#define UCSRC      	(*((volatile unsigned char *)0x40))
#define	UBRRH		(*((volatile unsigned char *)0x40))
#define UBRRL		(*((volatile unsigned char *)0x29))

//				End USART Section


//				Registers For WatchDog Timer

#define WDTCR		(*((volatile unsigned char *)0x41))

//				End WatchDog Timer Section



//				Registers For ADC

#define ADMUX		(*((volatile unsigned char *)0x27))
#define ADCSRA		(*((volatile unsigned char *)0x26))
#define SFIOR		(*((volatile unsigned char *)0x50))
#define ADCH		(*((volatile unsigned char *)0x25))
#define ADCL		(*((volatile unsigned char *)0x24))

//				End ADC Section




#endif /* ATMEGA32_H_ */