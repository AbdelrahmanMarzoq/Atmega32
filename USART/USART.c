/*
 * USART.c
 *
 * Created: 10/25/2024 10:08:20 PM
 *  Author: Abdelrhman Marzoq
 */ 



#include "USART.h"

#define F_CPU 8000000UL

void USART_Init(USART_Pins *USART_Config)
{
	
	
	/*  This Code run good */
	UCSRA = 0b00000000;
	UCSRB = 0b00011000;
	UCSRC = 0b10000110;
	//UBRRH = 0;
	UBRRL = 51;
	/*********/
	
	
	/**   This Init Need Some Enhancment */
	/*
	// Disable IRQ first Before Init
	UCSRB &= ~(0b111 << 5);			  // Disable IRQ for USART
	
	
	// Init BaudRate Mode
	// To Write In UBRRH Reg must Clear Bit 7 in UCSRC & bit 15 in UBRRH
	UCSRC &= ~(0b1 << 7);
	UBRRH &= ~(0b1 << 7);
	unsigned short BaudRate_Value;
	BaudRate_Value = (F_OSC / (16 * USART_Config->BaudRate_Mode)) - 1;
	
	//UBRRH |= 0;
	UBRRL  = (unsigned char)(BaudRate_Value & 0xFF);
	
	// Set Bit 7 In Reg UCSRC to Write in UCSRC if it 0 you will Write in Reg UBRRH
	UBRRH |= (0b1 << 7);
	
	// Clear Bit u2x to not Doubling BaudRate
	UCSRA &= ~(0b1 << 1);
	
	
	// Init Stop Mode
	if (USART_Config->Stop_Mode == STOP_1)
		UCSRC &= ~(0b1 << 3);
	else if (USART_Config->Stop_Mode == STOP_2)
		UCSRC |= (0b1 << 3);
		
	// Init Parity Mode
	if (USART_Config->Parity_Mode == Parity_NONE)
		UCSRC &= ~(0b11 << 4);
	else if (USART_Config->Parity_Mode == Parity_Even)
	{
		UCSRC &= ~(0b1 << 4);
		UCSRC |=  (0b1 << 5);
	}
	else if (USART_Config->Parity_Mode == Parity_Odd)
		UCSRC |= (0b11 << 4);
		
		
	// Clear UMSEL Bit in UCSRC Reg to enable Asynch mode for USART 
	UCSRC &= ~(0b1 << 6);
	
	
	// Init Data Frame Mode
	if (USART_Config->Data_Mode == BIT_5)
	{
		UCSRC &= ~(0b11 << 0);
		UCSRB &= ~(0b1  << 2);
	}
	else if (USART_Config->Data_Mode == BIT_6)
	{
		UCSRC |= (0b1 << 0);
		UCSRC &= ~(0b1  << 1);
		UCSRB &= ~(0b1  << 2);
	}		
	else if (USART_Config->Data_Mode == BIT_7)
	{
		UCSRC &= ~(0b1 << 0);
		UCSRC |= (0b1  << 1);
		UCSRB &= ~(0b1  << 2);		
	}
	else if (USART_Config->Data_Mode == BIT_8)
	{
		UCSRC |= (0b11  << 0);
		UCSRB &= ~(0b1  << 2);
	}
	else if (USART_Config->Data_Mode == BIT_9)
	{
		UCSRC |= (0b11  << 0);
		UCSRB |= (0b1  << 2);	
	}
	
	// Init RX & TX Mode
	if (USART_Config->RX_TX_Mode == USART_TX_En)
	{
		UCSRB |= (USART_Config->RX_TX_Mode);
		UCSRB &= ~(USART_RX_EN);
	}
	else if (USART_Config->RX_TX_Mode == USART_RX_EN)
	{
		UCSRB |= (USART_Config->RX_TX_Mode);
		UCSRB &= ~(USART_TX_En);	
	}
	else if (USART_Config->RX_TX_Mode == USART_RX_TX_EN)
		UCSRB |= (USART_Config->RX_TX_Mode);	
	
	
	// Init IRQ Mode
	if (USART_Config->IRQ_Mode != USART_IRQ_NONE)
	{
		UCSRB |= (USART_Config->IRQ_Mode); // Enable IRQ 
		// Enable GLOBAL Interrupt
		SREG |= 1 << 7;
	}
	else if (USART_Config->IRQ_Mode == USART_IRQ_NONE)
		UCSRB &= ~(0b111 << 5);			  // Disable IRQ for USART
		*/
}

void USART_TX(USART_Pins *USART_Config, const unsigned char *TX_Buffer)
{
	// Polling untill UDR is Ready

	if (USART_Config->Parity_Mode == Parity_NONE)
	{
		if (USART_Config->Data_Mode == BIT_8)
			UDR = *TX_Buffer;
		else
		{
			// To Do
		}
	}
	else
	{
		// To Do
	}
	while (! ( UCSRA & (1 << 5) ) );
	
}

void USART_RX(USART_Pins *USART_Config, unsigned char *RX_Buffer)
{
	// Polling untill Recieve Is Non Empty
	while (! ( UCSRA & (1 << 7) ) );
	if (USART_Config->Parity_Mode == Parity_NONE)
	{
		if (USART_Config->Data_Mode == BIT_8)
			*RX_Buffer = UDR;
		else
		{
			// To Do	
		}
	}
	else 
	{
		// To Do
	}
	
}

void USART_DeInit(USART_Pins *USART_Config)
{
	UCSRB &= ~(USART_RX_EN);
	UCSRB &= ~(USART_TX_En);
}