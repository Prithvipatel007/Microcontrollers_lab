#include <SI_EFM8BB1_Register_Enums.h>

sbit LED = P1^4;

// BUT on INT1=P0.2
void extint1 (void) interrupt 2 using 3
{
	LED ^= 1;
}

void main (void)
{
	XBR2 |= (1 << 6);	// port power

	WDTCN = 0xDE; WDTCN = 0xAD;		// disable watchdog passcode

	// EFM8 specific irq configuration
	// IRQ assign 6:4 INT1=P0.2 2:0 INT0 not assigned
	IT01CF |= (2 << 4);

	// 8051 standard irq configuration
	TCON |= (1 << 2);	// enable INT1 edge
	IE |= (1 << 2 );	// enable INT1 IRQ
	IE |= (1 << 7);		// enable global

	while (1)
	{
		// wait for interrupt
	}
}
