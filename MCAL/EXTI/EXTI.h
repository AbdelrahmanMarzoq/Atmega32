/*
 * EXTI.h
 *
 * Created: 10/25/2024 5:09:56 PM
 *  Author: Abdelrhman Marzoq
 */ 



#ifndef EXTI_H_
#define EXTI_H_


#include "Atmega32.h"
#include "GPIO.h"


#define INT0_BIT_Pos			6
#define INT1_BIT_Pos			7
#define INT2_BIT_Pos			5


typedef enum
{
	LOW_LEVEL,
	Any_Change,
	Falling_Edge,
	Rising_Edge
}Request_Mode;




typedef enum
{
	EXTI0 = 1 << INT0_BIT_Pos,
	EXTI1 = 1 << INT1_BIT_Pos,
	EXTI2 = 1 << INT2_BIT_Pos
}EXTIx;




typedef struct  
{
	EXTIx		 EXTI_Number;
	Request_Mode Mode;
	void (*ISR_CallBack)(void);
}EXTI_Pin;


void EXTI_Enable(EXTI_Pin *EXTI_Config);


void EXTI_Disable(EXTI_Pin *EXTI_Config);




#endif /* EXTI_H_ */