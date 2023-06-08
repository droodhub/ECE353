#include "msp.h"
#include <stdint.h>

#include "ece353.h"

int main(void) {
    WDT_A->CTL = WDT_A_CTL_PW |             // Stop WDT
            WDT_A_CTL_HOLD;

    ece353_MKII_RGB_PWM(
            1000,
            32,
            0,
            32
    );

    while(1)
    {
        __no_operation();
    }
}
