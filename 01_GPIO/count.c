#include<pic18.h>
void delay(int a);
void main (void)
{
    TRISB=0XFF;
    TRISC=0X00;
    ADCON1=0X0F;
    int count=0;
    while(1)
    {
    if(RB0==0)
        {
            count++;
            if(count==1)
        {
            LATC=0X01;
            delay(300);
        }
    if(count==2)
        {
            LATC=0X03;
            delay(300);
        }
    if(count==3)
        {
            LATC=0X07;
            delay(300);
        }
    if(count==4)
        {
            LATC=0X0F;
            delay(300);
        }
    if(count==5)
        {
            LATC=0X1F;
            delay(300);
        }
    if(count==6)
        {
            LATC=0X3F;
            delay(300);
        }
    if(count==7)
        {
            LATC=0X7F;
            delay(300);
        }
    if(count==8)
        {
            LATC=0XFF;
            delay(300);
        }
    if(count>=9)
        {
            count=0;
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
