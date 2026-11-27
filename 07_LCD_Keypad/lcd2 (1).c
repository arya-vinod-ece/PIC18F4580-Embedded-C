#include<pic18.h>
void delay(int a);
void command(int a);
void data(char a);
void main(void)
{
    TRISC=0X00;
    TRISD=0X00;
    command(0X0F);
    command(0X01);
    command(0X80);
    command(0X38);
    command(0X06);
    data('A');
    data('R');
    data('y');
    data('A');
    while(1);
   return; 
}
void command(int a)
{
    LATD=a;
    RC6=0;      //RS=0
    RC7=1;      //ENABLE=1
    delay(300);
    RC7=0;     //ENABLE=0
}
void data(char a)
{
    LATD=a;
    RC6=1;
    RC7=1;
    delay(300);
    RC7=0;
}
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++);
}