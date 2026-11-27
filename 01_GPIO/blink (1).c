/*
 * File:   blink.c
 * Author: ADMIN
 *
 * Created on 1 September, 2026, 9:49 AM
 */


#include <pic18.h>

void main(void) {
    int i;
    TRISA=0XFF;
    TRISB=0XFF;
    TRISC=0X00;
    TRISD=0X00;
    LATC=0XFF;
    for(i=0;i<2000;i++);
    LATD=0XFF;
    LATC=0X00;
    for(i=0;i<2000;i++);
    return;
}
