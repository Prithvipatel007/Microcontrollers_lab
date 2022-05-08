#include <SI_EFM8BB1_Register_Enums.h>

void delay(void)
{
	volatile unsigned short n;	// prevent compiler omission

	for (n=0; n<0xFFFF; n++) {}
}

sbit LED = P1^4;

void main (void)
{
	XBR2 |= (1 << 6);	// port power

	while (1)
	{
		LED ^= 1;
		delay();
	}
}
