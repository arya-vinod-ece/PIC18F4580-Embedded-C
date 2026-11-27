
/*
 * Project: Alternate LED Pattern Generation
 * Microcontroller: PIC18F4580
 * Language: Embedded C
 * IDE: MPLAB X IDE
 * Compiler: XC8
 *
 * Description:
 * Configures PORTC as an output port.
 * Writes two alternating bit patterns,
 * 0x55 and 0xAA, to the PORTC output latch.
 * Software delays are used between patterns.
 */

#include <pic18.h>

void main(void)
{
    int i;

    // Configure PORTC as output
    TRISC = 0x00;

    // First pattern: 01010101
    LATC = 0x55;

    // Software delay
    for(i = 0; i < 2000; i++);

    // Second pattern: 10101010
    LATC = 0xAA;

    // Software delay
    for(i = 0; i < 2000; i++);

    return;
}
