#include<pic18.h>
void main(void)
{
    int i;
    TRISC=0X00;
    LATC=0X01;
    for(i=0;i<2000;i++);
    LATC=0X02;
    for(i=0;i<2000;i++);
    LATC=0X04;
    for(i=0;i<2000;i++);
    LATC=0X08;
    for(i=0;i<2000;i++);
    LATC=0X10;
    for(i=0;i<2000;i++);
    LATC=0X20;
    for(i=0;i<2000;i++);
    LATC=0X40;
    for(i=0;i<2000;i++);
    LATC=0X80;
    for(i=0;i<2000;i++);
    return;
}