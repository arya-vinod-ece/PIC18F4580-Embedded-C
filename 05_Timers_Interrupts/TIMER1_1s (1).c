#include<pic18.h>
void timer();
void main (void)
{
    TRISC=0X00;
    T1CON=0XB1;
    TMR1=0;
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
    int i;
    for(i=0;i<10;i++)
    {
        while(TMR1IF==0);
        TMR1IF=0;
        TMR1=3036;  
    }   
}