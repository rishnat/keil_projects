#include "TM4C123GH6PM.h"
#include "interrupt.h"


int main(void)
{
	PortFInit();
	while(1)
	{
		if((GPIOF->DATA&0x01)==0)
		{
		settounprivileged();		//Set to unprivileged mode
		}
		else
		{	
			while(1)							//Wait for interrupt
			{
				if(isprivileged())
				{		
						break;				
				}
			}					
		}
	}
}





