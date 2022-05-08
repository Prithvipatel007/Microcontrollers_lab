#include <REG51.h>

sbit ADC_WR = P3^6;
sbit ADC_RD = P3^7;
sbit DAC_WR = P0^7;

void ext0(void) interrupt 0 using 3 {	// ADC has aquired
	ADC_RD = 0;	// enable ADC read
	P1 = P2;		// read data from ADC and write into DAC
	ADC_RD = 1;	// disable ADC read
}

void timer0(void) interrupt 1 using 3 {	// send sampling pulse to ADC
	ADC_WR = 0;	// enable ADC write
							// NOP not required since C is slow
	ADC_WR = 1;	// disable ADC write
}

void main(void)
{
	DAC_WR = 0;		// enable DAC write
	TCON = 1;			// external interrupt 0 edge mode
	IE = 0x83;
	TMOD = 2;
	TH0 = -20;
	TR0 = 1;
	
	while (1);
}
