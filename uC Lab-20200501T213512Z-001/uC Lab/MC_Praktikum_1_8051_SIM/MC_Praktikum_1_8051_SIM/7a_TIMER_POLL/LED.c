#include <REG51.h>

void T1Start()
{
  TMOD=0x20;
  TH1=0x5;
  TF1=0;
  TR1=1;
}

void T1Wait()
{
  while (TF1==0);
  TF1=0;
}

void main(void) {
  T1Start();
  while (1)
  {
    P1=0x00;
    T1Wait();
    P1=0xff;
    T1Wait();
  }
}
