#include "TM4C123GH6PM.h"
#include "interrupt.h"

int main(void)
{
	PortFInit();		//PortF initialization
	SysTick_Config(15000000);		//SysTick Configuration
	while(1)
	{
	//Loop forever
	}	
}


