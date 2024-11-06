/*
 * USART.h
 *
 * Created: 10/25/2024 10:08:31 PM
 *  Author: Abdelrhman Marzoq
 */ 


#ifndef USART_H_
#define USART_H_


#include "UART_Configuration.h"
#include "Atmega32.h"
#include "GPIO.h"


typedef enum
{
	USART_IRQ_NONE,				   // Disable IRQ
	USART_IRQ_UDRIE = 1 << 6,	   // Enable IRQ When Transmit byte
	USART_IRQ_TXCIE = 1 << 5,	   // Enable IRQ When Transmit Complete
	USART_IRQ_RXCIE	= 1 << 7	   // Enable IRQ When recieve byte in RX Buffer
}USART_IRQ;

typedef enum
{
	Parity_NONE,
	Parity_Even,
	Parity_Odd
}Parity;

typedef enum
{
	BIT_5,
	BIT_6,
	BIT_7,
	BIT_8,
	BIT_9
}Data_Frame;

typedef enum
{
	USART_BAUDRATE_2400   = 2400,
	USART_BAUDRATE_4800   = 4800,
	USART_BAUDRATE_9600   = 9600,
	USART_BAUDRATE_14400  = 14400,
	USART_BAUDRATE_19200  = 19200,
	USART_BAUDRATE_28800  = 28800,
	USART_BAUDRATE_38400  = 38400,
	USART_BAUDRATE_57600  = 57600,
	USART_BAUDRATE_76800  = 76800,
	USART_BAUDRATE_115200 = 115200,
	USART_BAUDRATE_230400 = 230400,
	USART_BAUDRATE_250000 = 250000
}BaudRate;

typedef enum
{
	STOP_1,
	STOP_2
}Stop;

typedef enum
{
	USART_TX_En    = 0b1  << 3,
	USART_RX_EN    = 0b1  << 4,
	USART_RX_TX_EN = 0b11 << 3
}RX_TX;

typedef struct 
{
	Parity		 Parity_Mode;
	USART_IRQ    IRQ_Mode;
	Data_Frame	 Data_Mode;
	BaudRate	 BaudRate_Mode;
	Stop		 Stop_Mode;	
	RX_TX		 RX_TX_Mode;
	void (*CallBACK)(void);
}USART_Pins;



void USART_Init(USART_Pins *USART_Config);

void USART_TX(USART_Pins *USART_Config, const unsigned char *TX_Buffer);

void USART_RX(USART_Pins *USART_Config, unsigned char *RX_Buffer);

void USART_DeInit(USART_Pins *USART_Config);

#endif /* USART_H_ */