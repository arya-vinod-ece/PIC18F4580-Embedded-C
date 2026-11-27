 #include<pic18.h>
void delay(int a);
void command(int a);
void data(char a);
void LCD_init();
void main(void)
{
    TRISC=0X00;
    TRISD=0X00;
    int i;
    char n[]="ARYA VINOD";
    char a[]="UTHRADAM(H)";
    LCD_init();
    for(i=0;i<10;i++)
    {
        data(n[i]);
    }
    command(0XC0);
    for(i=0;i<11;i++)
    {
        data(a[i]);
    }
  
    while(1);
   return; 
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