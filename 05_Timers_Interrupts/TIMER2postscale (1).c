#include<pic18.h>
void timer();
void main(void)
{
    TRISC=0X00;
    T2CON=0X7F;
    TMR2=0;
    PR2=0XFF;
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
    PR2=0XFF;
}