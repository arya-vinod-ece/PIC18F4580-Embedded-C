
/*
 * Project: LED Pattern Generation
 * Microcontroller: PIC18F4580
 * Language: Embedded C
 * IDE: MPLAB X IDE
 * Compiler: XC8
 *
 * Description:
 * Configures PORTC as an output port.
 * Generates two different output patterns
 * using hexadecimal values 0xCC and 0x33.
 * Software delays are used between the patterns.
 */

#include <pic18.h>

void main(void)
{
    int i;

    // Configure all PORTC pins as outputs
    TRISC = 0x00;

    // Apply the first output pattern: 11001100
    LATC = 0xCC;

    // Software delay
    for(i = 0; i < 2000; i++);

    // Apply the second output pattern: 00110011
    LATC = 0x33;

    // Software delay
    for(i = 0; i < 2000; i++);

    return;
}
