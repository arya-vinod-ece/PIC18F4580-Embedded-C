#include<pic18.h>
void timer();
void main(void)
{
    TRISC=0X00;
    T0CON=0X87;
    TMR0=0;
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
    while(TMR0IF==0);
    TMR0IF=0;
    TMR0=46005;
}