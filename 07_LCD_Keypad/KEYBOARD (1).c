#include<pic18.h>
void delay(int a);
void command(int a);
void data(char a);
void LCD_init();
void print(char *a);
void main(void)
{
 TRISB=0XF0;
 TRISC=0X00;
 TRISD=0X00;
 ADCON1=0X0F;
 LCD_init();
 while(1)
 {
     LATB=0X0E;
 if(RB7==0)
 {
     data('1');
 }
 if(RB6==0)
 {
     data('2');
 }
 if(RB5==0)
 {
     data('3');
 }
 if(RB4==0)
 {
     data('4');
 }
 LATB=0X0D;
  if(RB7==0)
 {
     data('5');
 }
 if(RB6==0)
 {
     data('6');
 }
 if(RB5==0)
 {
     data('7');
 }
 if(RB4==0)
 {
     data('8');
 }
 LATB=0X0B;
 if(RB7==0)
 {
     data('9');
 }
 if(RB6==0)
 {
     data('0');
 }
 if(RB5==0)
 {
     data('*');
 }
 if(RB4==0)
 {
     data('#');
 }
 LATB=0X07;
 if(RB7==0)
 {
     data('A');
 }
 if(RB6==0)
 {
     data('B');
 }
 if(RB5==0)
 {
     data('C');
 }
 if(RB4==0)
 {
     data('D');
 }
 }
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