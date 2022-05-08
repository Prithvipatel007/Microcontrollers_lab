#include <REG51.h>
#include <stdio.h>

sbit ADC_WR = P3^6;
sbit ADC_RD = P3^7;
 // 8 LEDs declaration
sbit LED0 = P1^0;
sbit LED1 = P1^1;
sbit LED2 = P1^2;
sbit LED3 = P1^3;
sbit LED4 = P1^4;
sbit LED5 = P1^5;
sbit LED6 = P1^6;
sbit LED7 = P1^7;

unsigned char val _at_ 0x70;
unsigned int dec;

void int0(void) interrupt 0 using 3
{
	ADC_RD = 0; // enable ADC read
	val = P2; // read data from ADC and write into RAM address 70H
	ADC_RD = 1; // disable ADC read
	ADC_WR = 0; // enable ADC write
	ADC_WR = 1; // disable ADC write
	
	// value in val variable is compared with the 8 divided levels between 0V to 5V and blinks the LEDs accordingly
	// which specifies the level
	
	if(val < 32){	
		LED0 = 0;
		LED1 = 1;
		LED2 = 1;
		LED3 = 1;
		LED4 = 1;
		LED5 = 1;
		LED6 = 1;
		LED7 = 1;
	}
	else if(val < 64){
		LED0 = 0;
		LED1 = 0;
		LED2 = 1;
		LED3 = 1;
		LED4 = 1;
		LED5 = 1;
		LED6 = 1;
		LED7 = 1;
	}
	else if(val < 96){
		LED0 = 0;
		LED1 = 0;
		LED2 = 0;
		LED3 = 1;
		LED4 = 1;
		LED5 = 1;
		LED6 = 1;
		LED7 = 1;
	}
	else if(val < 128){
		LED0 = 0;
		LED1 = 0;
		LED2 = 0;
		LED3 = 0;
		LED4 = 1;
		LED5 = 1;
		LED6 = 1;
		LED7 = 1;
	}
	else if(val < 160){
		LED0 = 0;
		LED1 = 0;
		LED2 = 0;
		LED3 = 0;
		LED4 = 0;
		LED5 = 1;
		LED6 = 1;
		LED7 = 1;
	}
	
	else if(val < 192){
		LED0 = 0;
		LED1 = 0;
		LED2 = 0;
		LED3 = 0;
		LED4 = 0;
		LED5 = 0;
		LED6 = 1;
		LED7 = 1;
	}
	else if(val < 224){
		LED0 = 0;
		LED1 = 0;
		LED2 = 0;
		LED3 = 0;
		LED4 = 0;
		LED5 = 0;
		LED6 = 0;
		LED7 = 1;
	}
	else if(val < 256){
		LED0 = 0;
		LED1 = 0;
		LED2 = 0;
		LED3 = 0;
		LED4 = 0;
		LED5 = 0;
		LED6 = 0;
		LED7 = 0;
	}
	else{
		LED0 = 1;
		LED1 = 1;
		LED2 = 1;
		LED3 = 1;
		LED4 = 1;
		LED5 = 1;
		LED6 = 1;
		LED7 = 1;
	}
	
	
}
void main(void)
{
	TCON = 1; // INT0 edge mode
	IE = 0x81; // INT0 enable
	ADC_WR = 0; // enable ADC write
	ADC_WR = 1; // disable ADC write
	while (1);
}