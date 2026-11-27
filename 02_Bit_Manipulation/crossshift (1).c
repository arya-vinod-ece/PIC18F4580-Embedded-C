#include<pic18.h>
void delay(int a);
void main(void)
{
    int n[]={0X81,0X42,0X24,0X18,0X24,0X42,0X81};
    int i;
    TRISC=0X00;
    for(i=0;i<7;i++)
    {
        LATC=n[i];
        delay(300);
    }
    
    
}
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++);
}