/*
 * File:   alternate.c
 * Author: ADMIN
 *
 * Created on 1 September, 2026, 10:46 AM
 */


#include <pic18.h>

void main(void) {
    int i;
    TRISC=0X00;
    LATC=0X55;
    for(i=0;i<2000;i++);
    LATC=0XAA;
    for(i=0;i<2000;i++);
    return;
}
