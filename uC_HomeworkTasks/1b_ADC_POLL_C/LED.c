#include <REG51.h>

sbit ADC_WR = P3^6;
sbit ADC_RD = P3^7;
sbit ADC_INTR = P3^2;
sbit DAC_WR = P0^7; 


void main(void){
	while (1)
	{
		ADC_WR = 0;		// enables ADC write
		ADC_WR = 1;		// disables ADC write
		
		while(ADC_INTR);	// ADC_INTR pin used for polling
		
		ADC_RD = 0;			// enables ADC read
		P1 = P2;			// stores data for the write process
		ADC_RD = 1;			// disables ADC read
		
		DAC_WR = 0;			// enables writing
		DAC_WR = 1;			// diables writing
		
	}
}

