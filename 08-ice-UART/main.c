#include "msp.h"
#include "serial_debug.h"
#include <stdbool.h>

/**
 * main.c
 */
extern volatile char message[80];
extern volatile bool stringReady;
extern volatile int charsReceived;

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

    serial_debug_init();

    __enable_irq();

    serial_debug_put_string("\n\r\n\r");
    serial_debug_put_string("**************************************************\n\r");
    serial_debug_put_string("ECE353 ICE 08 UART\n\r");
    serial_debug_put_string("**************************************************\n\r");
    while(1)
    {
        // check for when a new string has been received and print it to the
        // terminal.
        if(stringReady){
            serial_debug_put_string("Data Rxed : ");
            serial_debug_put_string(message);
            serial_debug_put_string("\n\r");
            memset(message, 0x00, 80);
            stringReady = false;
            charsReceived = 0;
        }
    }
}
