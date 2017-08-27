#include "TM4C123GH6PM.h"
#include "interrupt.h"

unsigned long delay;

_Bool isprivileged(void)		//Function to check if processor is in privilege or unprivilege mode
{
	return !(__get_CONTROL()&0x01);
}

void GPIOF_Handler(void)
{
	GPIOF->ICR|=0x10;		//Clear the interrupt flag
	settoprivileged();		//Set back to privilege mode
}

void PortFInit()
{
	SYSCTL->RCGC2|=0x20;			//Enable clock to PortF
	delay=SYSCTL->RCGC2;			//NOP operation
	GPIOF->LOCK=0x4C4F434B;			//This is required to access PF0
	GPIOF->CR|=0x01;					
	GPIOF->AFSEL&=(~0x11);			//Disable alternate function
	GPIOF->DIR&=(~0x11);			//Set direction as input
	GPIOF->DEN|=0x11;				//Set as digital pins
	GPIOF->AMSEL=(~0x11);			//Disable analog function
	GPIOF->PCTL=(~0x000F000F);		//Set as GPIO pins		
	GPIOF->PUR|=0x11;				//Enable pull-up resistor
	GPIOF->IS&=(~0x10);				//Edge-detect interrupt on PF4
	GPIOF->IBE&=(~0x10);			//Disable both-edge interrupt
	GPIOF->IEV&=(~0x10);			//Interrupt on falling edge
	GPIOF->IM|=0x10;				//Allow NVIC to process the interrupt signal from PF4
	GPIOF->ICR|=0x10;				//Clear interrupt flag initially
	NVIC_EnableIRQ(30);				//Enable NVIC to process the interrupt 
	NVIC_SetPriority(30,0);			//Set priority
}


