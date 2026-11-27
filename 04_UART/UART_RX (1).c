#include<pic18.h>
void LCD_init();
char receiver();
void data(char a);
void delay(int a);
void command(int a);
void main(void)
{
    TRISC=0X80;
    TRISD=0X00;
    LCD_init();
    TXSTA=0X24;
    RCSTA=0X90;
    BAUDCON=0X00;
    SPBRG=129;
    while(1)
    {
        char a=receiver();
        data(a);
        
    }

}
char receiver()
{
  while(RCIF==0);
  return RCREG;
 
    
}
void command(int a)
{
    LATD=a;
    RC0=0;      //RS=0
    RC1=1;      //ENABLE=1
    delay(300);
    RC1=0;     //ENABLE=0
}
void LCD_init()
{
    command(0X0F);
    command(0X01);
    command(0X80);
    command(0X38);
    command(0X06); 
}
void data(char a)
{
    LATD=a;
    RC0=1;
    RC1=1;
    delay(300);
    RC1=0;
}
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++);
}