#include <REG51.h>

sbit LED1 = P1^0;
sbit ROW3 = P0^3;
sbit KEY1 = P0^6;

bit flag;
unsigned short counter;

void delay(void)
{
	volatile unsigned int n;	// prevent compiler omission
	
	for (n=0; n<2500; n++) {}
}

void T0Start() {
  TMOD=0x02;
  TH0=0x05;			// 250us
  IE=0x82;
  TR0=1;
}

void T0Event(void) interrupt 1 using 3 {
  if (flag)
  {
    if (--counter==0)
		{
      LED1 = 1;		// switch off LED 1
			flag = 0;		// bath empty
		}
  }
}

void BathStart(void) {
  LED1 = 0;			// switch on LED 1
  flag = 1;			// bath full
  counter = 4000;	// counter: 1s = 4000*250us
}

void main(void) {
  P1 = 0xFF;
  P2 = 0xFF;
	P0 |= 0x7F;	
	ROW3 = 0;
  flag = 0;			// bath empty
  T0Start();
  while (1)
  {
    if (!flag && KEY1==0)	// check key 1
		{
			BathStart();
			delay();			// de-bounce
		}
  }
}
