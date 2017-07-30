/*A simple RGB Led Blink example for EK-TM4C123GXL Launchpad*/ 


#include "TM4C123GH6PM.h"			//Include board specific header file

//Function declarations

void delay(unsigned long);						
void PortF_Init(void);
void Red_led_ON(void);
void Red_led_OFF(void);
void Green_led_ON(void);
void Green_led_OFF(void);
void Blue_led_ON(void);
void Blue_led_OFF(void);

int main()
{
	PortF_Init();
	while(1)
	{
	Green_led_OFF();
	Red_led_ON();
	delay(1000);			//Delay in msec
	Red_led_OFF();
	Blue_led_ON();
	delay(1000);
	Blue_led_OFF();
	Green_led_ON();
	delay(1000);
	}
	
}

//Port Initilization
void PortF_Init()
{
	unsigned int delay;
	SYSCTL->RCGC2|=0x20;				//Providing clock to PortF
	delay=SYSCTL->RCGC2;				//Equivalent to NOP for clock initilization to happen	properly
	GPIOF->AFSEL&=(~0x0E);			//Disabling any alternate functionality for pin PF0, PF1 and PF2
	GPIOF->DIR|=0x0E;						//Setting the pins as output
	GPIOF->DEN|=0x0E;						//Setting the pins as digital pins
	GPIOF->AMSEL&=(~0x0E);			//Disabling analog functionality
	GPIOF->DATA&=(~0xE0);				//Clearing the pins initially
}


void Red_led_ON()
{
	GPIOF->DATA|=0x02;				//Red led ON
}


void Red_led_OFF()
{
	GPIOF->DATA&=(~0x02);			//Red led OFF
}


void Green_led_ON()
{
	GPIOF->DATA|=0x08;				//Green led ON
}


void Green_led_OFF()
{
	GPIOF->DATA&=(~0x08);			//Green led OFF
}


void Blue_led_ON()
{
	GPIOF->DATA|=0x04;				//Blue led ON
}

void Blue_led_OFF()
{
	GPIOF->DATA&=(~0x04);			//Blue led OFF
}


//Delay module
void delay(unsigned long msec)
{
	const unsigned long value=7000;  //Equivalent to 1ms delay(For accurate delays use timer)
	   
	for(int i=0;i<value*msec;i++)
	{
		
	}
	
}


