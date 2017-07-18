/*A simple RGB Led Blink example for EK-TM4C123GXL Launchpad*/ 


#include "TM4C123GH6PM.h"			//Include board specific header file

void delay(void);							//delay function

int main()
{
	SYSCTL->RCGCGPIO|=0x20;			//Providing clock to PortF 
	GPIOF->AFSEL&=(~0x0E);			//Disabling any alternate functionality for pin PF0, PF1 and PF2
	GPIOF->DIR|=0x0E;						//Setting the pins as output
	GPIOF->DEN|=0x0E;						//Setting the pins as digital pins
	GPIOF->AMSEL&=(~0x0E);			//Disabling analog functionality
	GPIOF->DATA&=(~0xE0);				//Clearing the pins initially
	
	while(1)
	{
	GPIOF->DATA&=(~0x08);			//Green led OFF
	GPIOF->DATA|=0x02;				//Red led ON 		
	delay();
	GPIOF->DATA&=(~0x02);			//Red led OFF
	GPIOF->DATA|=0x04;				//Blue led ON
	delay();
	GPIOF->DATA&=(~0x04);			//Blue led OFF
	GPIOF->DATA|=0x08;				//Green led ON
	delay();
	}
	
	return 0;
	
}

//Delay module
void delay(void)
{
	unsigned long volatile i=2000000;  //This value can be changed accordingly to adjust the delay
	   
	while(i)
	{
		i--;
	}
	
}


