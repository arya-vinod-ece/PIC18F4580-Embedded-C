#include<pic18.h>
void delay(int a);
void command(int a);
void data(char a);
void LCD_init();
void print(char *a);
char key();
void main(void)
{
    char n[]={'1','2','3','4'};
     char a[4];
    int count,i=0;
 TRISB=0XF0;
 TRISC=0X00;
 TRISD=0X00;
 ADCON1=0X0F;
 LCD_init();
 while(1)
 {
     count=0;
 for(i=0;i<4;i++)
 {
    
    a[i]=key();
     data(a[i]);    
 }
 command(0XC0);
 for(i=0;i<4;i++)
 {
 
 if(a[i]==n[i])
 {
    count=count+1;  
 }
 }
 if(count==4)
 {
     print("ACCESS GRANTED");
 }
 else
 {
     print("ACCESS DENIED");
 }
 }
 return;    
}
char key()
{
    while(1)
    {
 LATB=0X0E;
 if(RB7==0)
 {
     return '1';
 }
 if(RB6==0)
 {
    return '2';
 }
 if(RB5==0)
 {
     return '3';
 }
 if(RB4==0)
 {
    return '4';
 }
 LATB=0X0D;
  if(RB7==0)
 {
     return '5';
 }
 if(RB6==0)
 {
     return '6';
 }
 if(RB5==0)
 {
     return '7';
 }
 if(RB4==0)
 {
     return '8';
 }
 LATB=0X0B;
 if(RB7==0)
 {
     return '9';
 }
 if(RB6==0)
 {
     return '0';
 }
 if(RB5==0)
 {
     return '*';
 }
 if(RB4==0)
 {
     return '#';
 }
 LATB=0X07;
 if(RB7==0)
 {
     return 'A';
 }
 if(RB6==0)
 {
     command(0X10);
 }
 if(RB5==0)
 {
     command(0X14);
 }
 if(RB4==0)
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