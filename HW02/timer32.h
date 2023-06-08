/*
 * timer32.h
 *
 *  Created on: Oct 5, 2020
 *      Author: Andrew Sabee
 */

#ifndef TIMER32_H_
#define TIMER32_H_

#include "msp.h"
#include <stdbool.h>
#include <stdint.h>

extern volatile bool SCREEN_READY;
extern volatile bool BUTTON_PRESSED;

void T32_1_init(void);
void T32_2_init(void);
void T32_INT1_IRQHANDLER(void);
void T32_INT2_IRQHANDLER(void);

void ece353_MKII_S2_Init(void);
bool ece353_MKII_S2(void);

#endif /* TIMER32_H_ */
