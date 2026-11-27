#include<pic18.h>
void main(void)
{
    TRISC=0X00;
    T2CON=0X07;
    TMR2=0;
    PR2=0XFF;
    CCP1CON=0X0C;
    CCPR1L=0XC0;
    while(1);
}