#include <SI_EFM8BB1_Register_Enums.h>

sbit LED = P1^4;

void timer0 (void) interrupt 1 using 3
{
	LED ^= 1;

	// timer 0 reload
	TH0 = 0x80;			// fast
	// TH0 = 0x00;			// slow
	TL0 = 0x00;
}

void main (void)
{
	XBR2 |= (1 << 6);	// port power

	// timer 0
	TMOD |= (1 << 0);	// timer 0 mode 1
	TH0 = 0x80;			// fast
	// TH0 = 0x00;			// slow
	TL0 = 0x00;

	// 8051 standard irq configuration
	IE |= (1 << 1);		// enable timer 0 IRQ
	IE |= (1 << 7);		// enable global

	TCON_TR0 = 1;		// timer 0 start

	while (1)
	{
		// wait for interrupt
	}
}
