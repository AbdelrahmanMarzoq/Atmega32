/*
 * GPIO.h
 *
 * Created: 10/24/2024 9:35:29 PM
 *  Author: Abdelrhman Marzoq
*/ 


#ifndef GPIO_H_
#define GPIO_H_

#include "Atmega32.h"

typedef enum
{
	GPIOA = 0,
	GPIOB = 1,
	GPIOC = 2,
	GPIOD = 3
}GPIO;

typedef enum
{
	PIN0 = 1 << 0,
	PIN1 = 1 << 1,
	PIN2 = 1 << 2,
	PIN3 = 1 << 3,
	PIN4 = 1 << 4,
	PIN5 = 1 << 5,
	PIN6 = 1 << 6,
	PIN7 = 1 << 7,
}PIN_Number;

typedef enum
{
	LOW,
	HIGH
}State;

typedef enum
{
	INPUT,
	INPUT_PULLUP,
	OUTPUT
}DIR;

typedef struct
{
	GPIO GPIOx;
	PIN_Number PIN;
	DIR Direction;
}GPIO_Pin;




void GPIO_Init(GPIO_Pin *GPIO_Config);
State GPIO_Read(GPIO_Pin *GPIO_Config);
void GPIO_Write(GPIO_Pin *GPIO_Config, State Logic);
void GPIO_Toggle(GPIO_Pin *GPIO_Config);




#endif /* GPIO_H_ */