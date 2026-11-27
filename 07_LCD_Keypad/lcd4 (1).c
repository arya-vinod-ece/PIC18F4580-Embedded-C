#include<pic18.h>
void delay(int a);
void command(int a);
void data(char a);
void LCD_init();
void print(char *a);
void main(void)
{
    TRISC=0X00;
    TRISD=0X00;
    LCD_init();
    print("ARYA");
    command(0XC0);
    print("VINOD");
    while(1);
   return; 
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
    RC6=0;      //RS=0
    RC7=1;      //ENABLE=1
    delay(30);
    RC7=0;     //ENABLE=0
}
void data(char a)
{
    LATD=a;
    RC6=1;
    RC7=1;
    delay(30);
    RC7=0;
}
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++);
}
