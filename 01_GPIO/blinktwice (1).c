#include<pic18.h>
void main(void)
{
    int i;
    TRISC=0X00;
    LATC=0XCC;
    for(i=0;i<2000;i++);
    LATC=0X33;
    for(i=0;i<2000;i++);
    return;
}