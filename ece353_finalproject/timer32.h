/*
 * timer32.h
 *
 *  Created on: Oct 5, 2020
 *      Author: YOUR NAME
 */

#ifndef TIMER32_H_
#define TIMER32_H_

#include "msp.h"
//#include "ece353_staff.h"
#include "ece353.h"
#include <stdbool.h>
#include <stdint.h>
#include <main.h>

void  initializeTimer32(void);
void T32_INT1_IRQHandler(void);
void T32_INT2_IRQHandler(void);


#endif /* TIMER32_H_ */
