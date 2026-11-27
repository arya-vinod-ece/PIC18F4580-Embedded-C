#include<pic18.h>
void main(void)
{
    TRISC=0X00;
    TRISD=0X00;
    TRISB=0XFF;
    ADCON1=0X0F;
    T2CON=0X07;
    TMR2=0;
    PR2=0XFF;
    CCP1CON=0X0C;
    RC0=1;
    RC1=0;
    while(1)
    {
        if(RB0==0)
        {
            LATD=0X80;
            CCPR1L=0XC0;
        }
        if(RB1==0)
        {
            LATD=0XE0;
            CCPR1L=0X7F;
        }
        if(RB2==0)
        {
            LATD=0XFE;
            CCPR1L=0X40;  
        }
        if(RB3==0)
        {
            LATD=0XFF;
            RC0=0;
            RC1=0;
        }
    }
    
        
}

