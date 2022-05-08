#include <REG51.h>

void send(unsigned char ch)
{
  unsigned char par;

  par = ((unsigned char) P) << 7;	// add parity to char
  SBUF = ch | par;								// place value in buffer
  while (!TI);										// wait until transmitted
  TI=0;
}

void main(void)
{
  SCON=0x40;			// USART mode %01 = 8-bit data
  PCON=0x80;			// set double baud rate
  TMOD=0x20;			// timer 1 mode 2
  TH1=-12;				// timer 1 = -12: baud = 2400: double = 4800
  TL1=-12;				// timer 1 sync
  TR1=1; 					// timer 1 start

  send('a');
  send('b');
  send('c');

  while (1)
  {
  }
}
