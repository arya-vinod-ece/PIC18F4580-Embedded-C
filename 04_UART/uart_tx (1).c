#include<pic18.h>
void main(void)
{
    TRISC6=0;       //TRISC=0;  
    TXSTA=0X24;
    RCSTA=0X90;
    BAUDCON=0X00;
    SPBRG=129;
    TXREG='A';    //Data
    while(TXIF==0);   //flag checking
    TXIF=0;     //flag clr
    while(1);
}