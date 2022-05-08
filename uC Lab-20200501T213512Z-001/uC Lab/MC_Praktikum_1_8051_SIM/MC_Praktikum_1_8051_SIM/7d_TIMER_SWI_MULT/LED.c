#include <REG51.h>

sbit LED1 = P1^0;
sbit LED2 = P1^1;
sbit ROW3 = P0^3;
sbit KEY1 = P0^6;

bit flag1, flag2;
unsigned short counter1, counter2;

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
  if (flag1)
  {
    if (--counter1==0)
		{
      LED1 = 1;		// switch off LED 1
			flag1 = 0;	// bath empty
		}
  }
  if (flag2)
  {
    if (--counter2==0)
		{
      LED2 = 1;		// switch off LED 1
			flag2 = 0;	// bath empty
		}
  }
}

void BathStart(void) {
  if (flag1==0)				// bath 1 ready
  {
    LED1 = 0;					// switch on LED 1
    flag1 = 1;				// bath full
    counter1 = 4000;	// counter: 1s = 4000*250us
  }
  else
  {
    if (flag2==0)				// bath 2 ready
		{
      LED2 = 0;					// switch on LED 2
      flag2 = 1;				// bath full
      counter2 = 4000;	// counter: 1s = 4000*250us
		}
  }
}

void main(void) {
  P1 = 0xFF;
  P2 = 0xFF;
	P0 |= 0x7F;	
	ROW3 = 0;
  flag1 = 0;		// bath 1 empty
	flag2 = 0;		// bath 2 empty
  T0Start();
  while (1)
  {
    if ((flag1==0 || flag2==0) && KEY1==0)	// check key 1
		{
			BathStart();
			delay();			// de-bounce
		}
  }
}
