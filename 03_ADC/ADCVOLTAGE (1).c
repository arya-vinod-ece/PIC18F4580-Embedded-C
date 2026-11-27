#include<pic18.h>
#include<stdio.h>

void command(int a);
void LCD_init();
void delay(int a);
void data(int a);
void print(char *a);
void main(void)
{
    int i,c,b[4];
    float v;
    char buffer[100];
    TRISA=0XFF;
    TRISC=0X00;
    TRISD=0X00;
    LCD_init();
    ADCON0=0X03;
    ADCON1=0X00;
    ADCON2=0X88;
    while(1)
    {
        GODONE=1;
        while(GODONE==1);
        int a=ADRESL|(ADRESH<<8);
        c=a;
        for(i=3;i>=0;i--)
        {
            b[i]=(a%10)+48;
            a=a/10;
        }
        for(i=0;i<4;i++)
        {
            data(b[i]);
        }
        command(0XC0);
        
        v=(float)(c/1023.0)*5.0;
        sprintf(buffer,"Voltage=%0.2f V",v);
        print(buffer);
        command(0X0C);
        if(c!=a)
        {
            command(0X01);
        }
    }
    
}
void print(char *a)
{
    while(*a)
    {
        data(*a);
        a++;
    }
}
void LCD_init()
{
    command(0X0F); 
    command(0X01);
    command(0X80);
    command(0X38);
    command(0X06);
}
void command(int a)
{
    LATD=a;
    RC0=0;
    RC1=1;
    delay(100);
    RC1=0;
}
void data(int a)
{
    LATD=a;
    RC0=1;
    RC1=1;
    delay(100);
    RC1=0;
}
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++);
}   