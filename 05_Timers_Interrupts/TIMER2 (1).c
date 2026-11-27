#include<pic18.h>
void timer();
void main(void)
{
    TRISC=0X00;
    T2CON=0X07;
    TMR2=0;
    while(1)
    {
        LATC=0XFF;
        timer();
        LATC=0X00;
        timer();
    }
    
}
void timer()
{
    while(TMR2IF==0);
    TMR2IF=0;
    TMR2=0;
}