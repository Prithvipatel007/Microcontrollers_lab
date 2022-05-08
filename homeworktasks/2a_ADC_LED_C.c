#include <REG51.h>
#include <stdio.h>

sbit adc_write = P3^6;
sbit adc_read = P3^7;
 // 8 leds for outut
sbit led0 = P1^0;
sbit led1 = P1^1;
sbit led2 = P1^2;
sbit led3 = P1^3;
sbit led4 = P1^4;
sbit led5 = P1^5;
sbit led6 = P1^6;
sbit led7 = P1^7;

unsigned char num _at_ 0x70;

void int0(void) interrupt 0 using 3
{
	adc_read = 0; // enabling ADC read
	num = P2; // copy data into RAM address 70H
	adc_read = 1; // disabling ADC read
	adc_write = 0; // enabling ADC write
	adc_write = 1; // disabling ADC write
	
	// The number in num variable is checked with the 8 divided levels (0V to 5V ) and shows the led lvl
	
	if(num < 32){	
		led0 = 0;
		led1 = 1;
		led2 = 1;
		led3 = 1;
		led4 = 1;
		led5 = 1;
		led6 = 1;
		led7 = 1;
	}
	else if(num < 64){
		led0 = 0;
		led1 = 0;
		led2 = 1;
		led3 = 1;
		led4 = 1;
		led5 = 1;
		led6 = 1;
		led7 = 1;
	}
	else if(num < 96){
		led0 = 0;
		led1 = 0;
		led2 = 0;
		led3 = 1;
		led4 = 1;
		led5 = 1;
		led6 = 1;
		led7 = 1;
	}
	else if(num < 128){
		led0 = 0;
		led1 = 0;
		led2 = 0;
		led3 = 0;
		led4 = 1;
		led5 = 1;
		led6 = 1;
		led7 = 1;
	}
	else if(num < 160){
		led0 = 0;
		led1 = 0;
		led2 = 0;
		led3 = 0;
		led4 = 0;
		led5 = 1;
		led6 = 1;
		led7 = 1;
	}
	
	else if(num < 192){
		led0 = 0;
		led1 = 0;
		led2 = 0;
		led3 = 0;
		led4 = 0;
		led5 = 0;
		led6 = 1;
		led7 = 1;
	}
	else if(num < 224){
		led0 = 0;
		led1 = 0;
		led2 = 0;
		led3 = 0;
		led4 = 0;
		led5 = 0;
		led6 = 0;
		led7 = 1;
	}
	else if(num < 256){
		led0 = 0;
		led1 = 0;
		led2 = 0;
		led3 = 0;
		led4 = 0;
		led5 = 0;
		led6 = 0;
		led7 = 0;
	}
	else{
		led0 = 1;
		led1 = 1;
		led2 = 1;
		led3 = 1;
		led4 = 1;
		led5 = 1;
		led6 = 1;
		led7 = 1;
	}
	
	
}
void main(void)
{
	TCON = 1; // INT0 edge mode
	IE = 0x81; // INT0 enable
	adc_write = 0; // enable ADC write
	adc_write = 1; // disable ADC write
	while (1);
}