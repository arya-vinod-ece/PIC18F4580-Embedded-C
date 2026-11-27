#include<pic18.h>
void main(void)
{
    int i,j;
    TRISC=0X00;
    LATC=0X80;
    for(j=0;j<1000;j++);
    for(i=0;i<=7;i++)
    {
      LATC=LATC>>1;
      for(j=0;j<2000;j++);
    }
    return;
}