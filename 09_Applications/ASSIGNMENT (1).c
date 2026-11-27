#include<pic18.h>
char key();
void LCD_init();
void command(int a);
void data(int a);
void print(char *a);
void delay(int a);
void main(void)
{
    char n[]={'1','2','3','4'};
    char a[16];
    int count,i;
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
            data('*');
        }
        for(i=0;i<4;i++)
        {
            if(a[i]==n[i])
            {
                count++;
            }
        }
        command(0XC0);
        if(count==4)
        {
            print("ACCESS GRANTED");
            RC0=1;
            RC1=0;
            RC2=1;
            RC3=0;
            RC4=1;
            RC5=0;
        }
        else
        {
            print("ACCESS DENIED");
            RC0=0;
            RC1=0;
            RC2=0;
            RC3=0;
            RC4=0;
            RC5=0;
        }
        
    }
    
}
char key()
{
    while(1)
    {
        LATB=0X0E;
        if(RB7==0)
        {
            return'1';
        }
        if(RB6==0)
        {
            return'2';
        }
        if(RB5==0)
        {
            return'3';
        }
        if(RB4==0)
        {
            return'4';
        }
        LATB=0X0D;
        if(RB7==0)
        {
            return'5';
        }
        if(RB6==0)
        {
            return'6';
        }
        if(RB5==0)
        {
            return'7';
        }
        if(RB4==0)
        {
            return'8';
        }
        LATB=0X0B;
        if(RB7==0)
        {
            return'9';
        }
        if(RB6==0)
        {
            return'0';
        }
        if(RB5==0)
        {
            return'*';
        }
        if(RB4==0)
        {
            return'#';
        }
        LATB=0X07;
        if(RB7==0)
        {
            return'A';
        }
        if(RB6==0)
        {
            return'B';
        }
        if(RB5==0)
        {
            return'C';
        }
        if(RB4==0)
        {
            command(0X01);
            RC0=0;
            RC1=0;
            RC2=0;
            RC3=0;
            RC4=0;
            RC5=0;
        }   
    }
}
void LCD_init()
{
    command(0X0F); 
    command(0X38);
    command(0X0E);
    command(0X06);
    command(0X38);
}
void command(int a)
{
    LATD=a;
    RC6=0;
    RC7=1;
    delay(300);
    RC7=0;
}
void data(int a)
{
    LATD=a;
    RC6=1;
    RC7=1;
    delay(300);
    RC7=0;
}
void print(char *a)
{
    while(*a!=0)
    {
        data(*a);
        a++;
    }
}
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++);
}