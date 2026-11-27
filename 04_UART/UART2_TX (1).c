#include<pic18.h>
void transmit(char a);
void main(void)
{
    char n[]="ARYA";
    int i;
    TRISC6=0;
    TXSTA=0X24;
    RCSTA=0X90;
    BAUDCON=0X00;
    SPBRG=129;//TRISC=0;  
    for(i=0;i<4;i++)
    {
      transmit(n[i]);  
    }
    
    while(1);
}
void transmit(char a)
{
  TXREG=a;    //Data
  while(TXIF==0);   //flag checking
  TXIF=0;     //flag clr
    
}