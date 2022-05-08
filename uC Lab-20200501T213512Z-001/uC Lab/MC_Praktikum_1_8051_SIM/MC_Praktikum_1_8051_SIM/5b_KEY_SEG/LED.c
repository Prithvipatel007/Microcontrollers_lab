#include <REG51.h>

extern unsigned char keypad(void);

// ROM
// 11000000B	: 0
// 11111001B	: 1
// 10100100B	: 2
// 10110000B	: 3
// 10011001B	: 4
// 10010010B	: 5
// 10000010B	: 6
// 11111000B	: 7
// 10000000B	: 8
// 10010000B	: 9
code unsigned char table[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

sbit CS = P0^7;		// MUX CS
sbit A0 = P3^3;		// MUX A0
sbit A1 = P3^4;		// MUX A1

void main(void)
{
	signed char num;
	
	CS = 0;			// MUX CS -> SEG off
	P1 = 0xFF;	// SEG clear
	A0 = 0;			// MUX A0 = 0 -> SEG #1 select
	A1 = 0;			// MUX A1 = 0
	CS = 1;			// MUX CS -> SEG on
	
  while (1)
  {
		num = keypad();		// read keypad
		
		if (num == -1)
			P1 = 0xFF;					// no key pressed : SEG clear
		else
			P1 = table[num];		// SEG show number
  }
}
