/*
 * ps2.h
 *
 *  Created on: Oct 5, 2020
 *      Author: YOUR NAME
 */

#ifndef PS2_H_
#define PS2_H_

extern volatile uint32_t PS2_X_DIR;
extern volatile uint32_t PS2_Y_DIR;

void ece353_ADC14_PS2_XY(void);
void ADC14_IRQHandler(void);

#endif /* PS2_H_ */
