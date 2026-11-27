#include<pic18.h>
#include<stdio.h>
void main(void)
{
  
  float v;
  TRISA=0XFF;
  TRISC=0X00;
  ADCON0=0X03;
  ADCON1=0X00;
  ADCON2=0X88;
  T2CON=0X07;
  TMR2=0;
  PR2=0XFF;
  CCP1CON=0X0C;
  RC0=1;
  RC1=0;
  while(1)
    {
        GODONE=1;
        while(GODONE==1);
        int a=ADRESL|(ADRESH<<8);
        v=(float)(a/1023.0)*5.0;
        if(0<v && v<=1) 
        {
            CCP1CON=0X0C;
            CCPR1L=0XC0;
            
        }
        if(v>1.5 && v<=2.5)
        {
            CCP1CON=0X3C;
            CCPR1L=0X80;
          
        }
        if(v>2.5 && v<=5)     
        {
            CCP1CON=0X0C;
            CCPR1L=0X40;
              
        }
    }
        
}
