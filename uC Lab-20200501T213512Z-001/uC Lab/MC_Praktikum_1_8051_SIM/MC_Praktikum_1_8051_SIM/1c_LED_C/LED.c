#include <REG51.h>

void delay(void)
{
	volatile unsigned char n;	// prevent compiler omission
	
	for (n=0; n<250; n++) {}
}

sbit LED = P1^0;
sbit SWITCH = P2^0;

void main(void)
{
	LED = 1;			// LED off (high)
	SWITCH = 1;		// switch off (high)
	
	while (1)
	{
		if (SWITCH)		// check switch (low)
			LED = 1;		// if not : LED off (high)
		else
		{
			LED = 0;		// LED on (low)
			delay();		// switch de-bounce
		}
	}
}
