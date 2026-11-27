#include<pic18.h>
void delay();
void main(void)
{
    TRISC=0X00;
    TRISD=0X00;
    TRISB=0XFF;
    ADCON1=0X0F;
    INTCON=0XD0;
    while(1)
    {
        PORTC= 0XFF;
        delay();
        PORTC =0X00;
        delay();
    }
}
void __interrupt() isr()
{ 
    int i;
    while(INT0IF==0);
     LATC=0X01;
     delay(300);
     for(i=0;i<7;i++)
        {
            LATC=PORTC<<1;
            delay(300);
        }
     INT0IF=0;
}
void delay()
{
    int j,i;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++);
    }
}
    
