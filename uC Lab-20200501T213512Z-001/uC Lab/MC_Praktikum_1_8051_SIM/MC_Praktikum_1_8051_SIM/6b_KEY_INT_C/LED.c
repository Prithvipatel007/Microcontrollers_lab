#include <REG51.h>

sbit LED1 = P1^0;
sbit LED2 = P1^1;
sbit LED3 = P1^2;

sbit KEY1 = P0^6;
sbit KEY2 = P0^5;
sbit KEY3 = P0^4;

sbit ROW1 = P0^3;

// INT1
void extint1(void) interrupt 2 using 3
{
	if (! KEY1)		// key1 pressed (=0)
		LED1 ^= 1;
	if (! KEY2)		// key2 pressed (=0)
		LED2 ^= 1;
	if (! KEY3)		// key3 pressed (=0)
		LED3 ^= 1;
}

void main(void)
{
  TCON |= (1 <<(2));	// enable INT1 edge
	IE |= (1 << (2));		// enable INT1 IRQ
	IE |= (1 << (7));		// enable global
	
	P0 |= 0x7F;					// all key lines high %0111|1111
	ROW1 = 0;						// row3 line low
	
  while (1)		// wait for IRQ
  {
  }
}
