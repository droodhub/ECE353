/*
 * ps2.c
 *
 *  Created on: Oct 5, 2020
 *      Author: Andrew Sabee
 */

#include "msp.h"
#include "ps2.h"


//assume the joystick starts in the center
volatile uint32_t PS2_X_DIR = 1000;
volatile uint32_t PS2_Y_DIR = 1000;

void ece353_ADC14_PS2_XY(void){
    // Configure the X direction as an analog input pin.
        P6->SEL0 |= BIT1; //BIT1:x, 4.0:Y, 4.2:Z
        P6->SEL1 |= BIT1;
        // Configure the Y direction as an analog input pin.
        P4->SEL0 |= BIT0; //BIT6
        P4->SEL1 |= BIT0;
        // Configure CTL0 to sample 16-times in pulsed sample mode.
        // Indicate that this is a sequence of channels.
        ADC14->CTL0 = ADC14_CTL0_SHT02 | ADC14_CTL0_CONSEQ_1 | ADC14_CTL0_SHP;
        // Configure CTL1 to return 12-bit values
        ADC14->CTL1 = ADC14_CTL1_RES__12BIT;
        // Associate the X direction analog signal with MEM[0]
        ADC14->MCTL[0] = ADC14_MCTLN_INCH_14; //inch 14, 13, 11: X, Y, Z
        // Associate the Y direction analog signal with MEM[1]
        ADC14->MCTL[1] = ADC14_MCTLN_INCH_13;
        // Indicate the end of sequence
        ADC14->MCTL[1] |= ADC14_MCTLN_EOS;
        // Enable interrupts in the ADC AFTER a value is written into MEM[1].
        ADC14->IER0 =  ADC14_IER0_IE1;
        // Enable ADC Interrupt
        NVIC_EnableIRQ(ADC14_IRQn);
        // Turn ADC ON
        ADC14->CTL0 |= ADC14_CTL0_ON;
}

void ADC14_IRQHandler(void){
    // Read the X value
    PS2_X_DIR = ADC14->MEM[0];
    // Read the Y value
    PS2_Y_DIR = ADC14->MEM[1];
}
