#include <REG51.h>

sbit adc_write = P3^6;		//adc writing to digital value of voltage for showing
sbit adc_read = P3^7;		// adc reading from analog value of voltage
sbit adc_intr = P3^2;	// polling 
sbit adc_read = P0^7; 	// dac writing


void main(void){
	while (1)
	{
		adc_write = 0;		// enabling ADC write
		adc_write = 1;		// disabling ADC write
		
		while(adc_intr);	// polling
		
		adc_read = 0;			// enabling ADC read
		P1 = P2;			// copy data
		adc_read = 1;			// disabling ADC read
		
		adc_read = 0;			// enabling writing
		adc_read = 1;			// diabling writing
		
	}
}

