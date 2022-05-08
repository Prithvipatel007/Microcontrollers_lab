#include <REG51.h>

void delay(void)
{
	volatile unsigned char n;	// prevent compiler omission
	
	for (n=0; n<250; n++) {}
}

void main(void)
{
	unsigned char idx;
	
  while (1)
  {
		for (idx=0; idx<8; idx++)		// bit index
		{
			P1 = 0xFF ^ (1 << (idx));	// running clear one LED

			delay();
    }
  }
}
