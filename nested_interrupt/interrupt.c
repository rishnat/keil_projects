#include "TM4C123GH6PM.h"
#include "interrupt.h"

unsigned long delay;
unsigned long gpiof=0;

void SysTick_Handler(void)	//This function gets called on every Systick Interrupt     
{
	GPIOF->DATA^=0x02;			//Led toggle
}


void GPIOF_Handler(void)
{
	GPIOF->ICR|=0x10;			//Clear Interrupt flag
	gpiof=gpiof+1;				//Increment variable on every GPIO interrupt 
}

void PortFInit(void)
{
	SYSCTL->RCGC2|=0x20;		//Enable clock to PortF
	delay=SYSCTL->RCGC2;		//NOP operation
	GPIOF->DIR&=(~0x10);		//Set direction as input
	GPIOF->DIR|=0x02;				//Set direction as output
	GPIOF->AFSEL&=(~0x12);	//Disable alternate function
	GPIOF->DEN|=0x12;				//Set as digital pins
	GPIOF->AMSEL&=(~0x12);	//Disable analog function
	GPIOF->PCTL&=(~0x000F00F0);	//Set as GPIO pins
	GPIOF->PUR|=0x10;				//Enable pull-up resistor
	GPIOF->IS&=(~0x10);			//Edge-detect interrupt on PF4	
	GPIOF->IBE&=(~0x10);		//Disable both-edge interrupt	
	GPIOF->IEV&=(~0x10);		//Interrupt on falling edge
	GPIOF->IM|=0x10;				//Allow NVIC to process the interrupt signal from PF4
	GPIOF->ICR|=0x10;				//Clear interrupt flag initially
	NVIC_EnableIRQ(30);			//Enable NVIC to process the interrupt		 
	NVIC_SetPriority(30,3);			//Set priority
}


