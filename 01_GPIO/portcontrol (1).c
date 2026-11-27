#include<pic18.h>
void delay(int a);
void main(void)
{
    int i;
    int n[]={0X81,0X42,0X24,0X18,0X24,0X42,0X81};
    TRISC=0X00;
    TRISB=0XFF;
    ADCON1=0X0F;
   
    while(1)
    {
        if(RB0 ==0)
        {
            LATC=0XFF;
            delay(300);
            LATC=0X00;
            delay(300);
        }
        if(RB1==0)
        {
            LATC=0X55;
            delay(300);
            LATC=0XAA;
            delay(300);
        }
        if(RB2==0)
        {
            LATC=0X01;
            delay(300);
            for(i=0;i<7;i++)
            {
                LATC=PORTC<<1;
                delay(300);
            }
        }
        if(RB3==0)
        {
            LATC=0X80;
            delay(300);
            for(i=0;i<7;i++)
            {
                LATC=PORTC>>1;
                delay(300);
            }
        }
        if(RB4==0)
        {
            for(i=0;i<7;i++)
            {
                LATC=n[i];
                delay(300);
            }
            
            
        }
    }
}
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++);
    
}