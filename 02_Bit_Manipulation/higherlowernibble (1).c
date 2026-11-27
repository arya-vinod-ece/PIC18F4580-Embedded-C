/*
 * File:   higherlowernibble.c
 * Author: ADMIN
 *
 * Created on 2 September, 2026, 9:04 AM
 */


#include <pic18.h>

void main(void) {
    int i;
    TRISC=0X00;
    LATC=0XF0;
    for(i=0;i<2000;i++);
    LATC=0X0F;
    for(i=0;i<2000;i++);
    return;
}
