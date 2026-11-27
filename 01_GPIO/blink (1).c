
/*
 * Project: LED Output Control
 * Microcontroller: PIC18F4580
 * Language: Embedded C
 * IDE: MPLAB X IDE
 * Compiler: XC8
 *
 * Description:
 * Configures PORTA and PORTB as inputs
 * and PORTC and PORTD as outputs.
 * Changes the output states of PORTC and PORTD
 * with software delays.
 */

#include <pic18.h>

void main(void)
{
    int i;

    // Configure PORTA and PORTB as input ports
    TRISA = 0xFF;
    TRISB = 0xFF;

    // Configure PORTC and PORTD as output ports
    TRISC = 0x00;
    TRISD = 0x00;

    // Set all PORTC output pins HIGH
    LATC = 0xFF;

    // Generate a software delay
    for(i = 0; i < 2000; i++);

    // Set all PORTD output pins HIGH
    LATD = 0xFF;

    // Set all PORTC output pins LOW
    LATC = 0x00;

    // Generate another software delay
    for(i = 0; i < 2000; i++);

    return;
}
