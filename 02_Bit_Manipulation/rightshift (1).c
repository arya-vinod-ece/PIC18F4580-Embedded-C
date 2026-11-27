#include<pic18.h>
void delay(int a);
void main(void)
{
    int i;
    TRISC=0X00;
    LATC=0X80;
    delay(300);
    for(i=0;i<7;i++)
    {
        LATC=PORTC>>1;
        delay(300);
    }
}
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++);
}