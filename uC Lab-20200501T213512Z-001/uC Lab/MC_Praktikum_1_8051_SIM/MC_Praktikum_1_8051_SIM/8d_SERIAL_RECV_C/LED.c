#include <REG51.h>

unsigned char receive(void)
{
  unsigned char ch;

  while (!RI);			// wait until received
  RI=0;

  ch = SBUF;

  return ch;
}

void main(void)
{
  unsigned char ch;

  SCON=0x50;			// USART mode %01 = 8-bit data + enable receiver
  PCON=0x80;			// set double baud rate
  TMOD=0x20;			// timer 1 mode 2
  TH1=-12;				// timer 1 = -12: baud = 2400: double = 4800
  TL1=-12;				// timer 1 sync
  TR1=1; 					// timer 1 start

  ch = 0;
  while (ch!=0x8D)
  {
    ch = receive();
		P1 = ch & 0x7F;		// clear parity bit and show on LEDs
  }

  while (1)
  {
  }
}
