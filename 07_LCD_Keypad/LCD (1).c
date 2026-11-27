#include<pic18.h>
void delay(int a);
void main(void)
{
    TRISC=0X00;
    TRISD=0X00;
    LATD=0X0F;
    RC6=0;        //RS=0
    RC7=1;       // ENABLE HIGH
    delay(300);    //DELAY
    RC7=0;        //ENABLE LOW
    LATD='A';
    RC6=1;     //RS=1
    RC7=1;
    delay(300);
    RC7=0;
    LATD='R';
    RC6=1;
    RC7=1;
    delay(300);
    RC7=0;
    LATD='Y';
    RC6=1;     //RS=1
    RC7=1;
    delay(300);
    RC7=0;
    LATD='A';
    RC6=1;     //RS=1
    RC7=1;
    delay(300);
    RC7=0;
    while(1);
   return; 
}
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++);
}