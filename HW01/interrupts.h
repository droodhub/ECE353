//Author: Andrew Sabee
//thought that pressing the button would cause an interrupt
//and we would use that to set a volatile bool var in main.c,
//but ece353_MKII_S1() does essentially the same thing more efficiently.

#include <stdint.h>
#include <stdbool.h>
#include "msp.h"

extern volatile bool ALERT_PS2_UPDATE;
extern volatile uint32_t PS2_X_DIR;
extern volatile bool BUTTON_PRESSED;

void T32_INT1_IRQHandler(void);
void ADC14_IRQHandler(void);
void ice05_init_s1(void);
