#include <REG51.h>
#include <stdio.h>

sbit ADC_WR = P3^6;
sbit ADC_RD = P3^7;
sbit DAC_WR = P0^7;

// ROM - Stored in table
// 11000000B	: 0
// 11111001B	: 1
// 10100100B	: 2
// 10110000B	: 3
// 10011001B	: 4

unsigned char val _at_ 0x70;

code unsigned char table[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92};

void int0(void) interrupt 0 using 3
{
	ADC_RD = 0; // enable ADC read
	val = P2; // read data from ADC and write into RAM address 70H
	ADC_RD = 1; // disable ADC read
	ADC_WR = 0; // enable ADC write
	ADC_WR = 1; // disable ADC write
	
	// Variable val is compared with the voltage levels,
	// 0V - 0.99V -> represents 0 in 7 segment LEDs
	// 1V - 1.99V -> represents 1 in 7 segment LEDs
	// 2V - 2.99V -> represents 2 in 7 segment LEDs
	// 3V - 3.99V -> represents 3 in 7 segment LEDs
	// 4V - 4.99V -> represents 4 in 7 segment LEDs
	// greater than 4.99 -> represents 5 in 7 segment LEDs
	
	if(val >= 103 && val <= 153){
		P1 = table[2];
	}
	else if(val >= 154 && val <= 204) {
		P1 = table[3];
	}
	else if(val >= 0 && val <= 51){
		P1 = table[0];
	}
	else if(val >= 52 && val <= 102){
		P1 = table[1];
	}
	
	else if(val >= 205 && val <= 254){
		P1 = table[4];
	}
	else if(val > 254){
		P1 = table[5];
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