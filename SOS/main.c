//A simple SOS application for TIVA C launchpad
//PF4 pin(SW1) is used to start the signal
//PF0 pin(SW2) is used to stop the signal
//PF1 pin (RED led) is used for indicating SOS signal 


#include "TM4C123GH6PM.h"		//Board specific header file
 
 
//Function declaration 
void Delay1ms(unsigned long);			//Delay function
void S_signal(void);							//Implements S part of SOS
void O_signal(void);							//Implements O part of SOS
void PortF_Init(void);						//PortF initialization
void SOS_start(void);							//SOS start function


int main()
{
	PortF_Init();			//Initializing portF
	
	while(1)
	{
	unsigned int SW1;
	unsigned int SW2;
	
	do
	{
		SW1=GPIOF->DATA&0x10;
	}while(SW1);
	
	do
	{
		SOS_start();		//Start of SOS signal
		SW2=GPIOF->DATA&0x01;		
	}while(SW2);
			
	}
	
}


void PortF_Init()
{
	SYSCTL->RCGC2|=0x20;			//Enabling clock to PortF
	GPIOF->LOCK=0x4C4F434B;		//This is required for PF0 as it is locked
	GPIOF->CR|=0x01;					//Commit value to unlock PF0
	GPIOF->DIR|=0x02;					//Setting PF1 as output(RED led)
	GPIOF->DIR&=(~0x11);			//Setting PF0 and PF4 as input
	GPIOF->AFSEL&=(~0x13);		//Disabling any alternate functionality
	GPIOF->DEN|=0x13;					//Enabling pins for digital mode
	GPIOF->AMSEL&=(~0x13);		//Disabling analog functionality
	GPIOF->PUR|=0x11;					//Enabling pull up registers for switches (PF0 and PF4)
	GPIOF->PCTL&=0x000000000;	//Setting pis as GPIO 
}


void SOS_start()
{
	S_signal();		//Red Led will toggle with 1/2 sec gap
	O_signal();		//Red Led will toggle with 2 sec gap
	S_signal();
	Delay1ms(5000);		//Delay of 5 sec till the start of next SOS
}


void S_signal()
{
	GPIOF->DATA|=0x02;
	Delay1ms(500);			//Delay of 1/2 sec
	GPIOF->DATA&=(~0x02);
	Delay1ms(500);
	
	GPIOF->DATA|=0x02;
	Delay1ms(500);
	GPIOF->DATA&=(~0x02);
	Delay1ms(500);
	
	
	GPIOF->DATA|=0x02;
	Delay1ms(500);
	GPIOF->DATA&=(~0x02);
	Delay1ms(500);
}


void O_signal()
{
	GPIOF->DATA|=0x02;
	Delay1ms(2000);			//Delay of 2 sec
	GPIOF->DATA&=(~0x02);
	Delay1ms(2000);
	
	GPIOF->DATA|=0x02;
	Delay1ms(2000);
	GPIOF->DATA&=(~0x02);
	Delay1ms(2000);
	
	
	GPIOF->DATA|=0x02;
	Delay1ms(2000);
	GPIOF->DATA&=(~0x02);
	Delay1ms(2000);
}


void Delay1ms(unsigned long msec)
{
	const unsigned long value=5000; //This number has been hardcoded(For accurate results use timer)
	
	for(long i=0;i<value*msec;i++)
	{
	}
	
}	

 