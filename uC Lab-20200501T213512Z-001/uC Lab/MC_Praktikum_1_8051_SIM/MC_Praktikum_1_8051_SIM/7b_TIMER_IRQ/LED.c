#include <REG51.h>

void T0Start() {
  TMOD=0x02;
  TH0=0x05;
  IE=0x82;
  TR0=1;
}

void T0Event(void) interrupt 1 using 3 {
  P1 = ~P1;
}

void main(void) {
  T0Start();
  P1=0xff;
  while (1)
  {
  }
}
