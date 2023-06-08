/*
 * interrupts.c
 *
 *  Created on: Aug 20, 2020
 *      Author: Joe Krachey
 */

#include "interrupts.h"

// Add a global variable that holds the most recent value of the X direction
volatile bool ALERT_PS2_UPDATE = false;
volatile uint32_t PS2_X_DIR = 0;
// Add a global variable that informs the application that the Window Camparator
// had detected a change


void T32_INT1_IRQHandler(void)
{
    // Start the ADC conversion
    ADC14->CTL0 |= ADC14_CTL0_SC | ADC14_CTL0_ENC;

    // Clear the timer interrupt
    TIMER32_1->INTCLR = BIT0;

}

void ADC14_IRQHandler(void)
{
    // set the global variable that informs the application that the Window Camparator
    // had detected a change
    ALERT_PS2_UPDATE = true;

    // Determine if the HIIFG interrupt is active
    if (ADC14->IFGR1 & ADC14_IFGR1_HIIFG)
    {
        // Clear interrupt flag
        ADC14->CLRIFGR1 |= ADC14_CLRIFGR1_CLRHIIFG;
        // Turn off the HI interrupt
        ADC14->IER1 &= ~ADC14_IER1_HIIE;
        // Turn on LOW and IN interrupts
        ADC14->IER1 |= ADC14_IER1_LOIE | ADC14_IER1_INIE;
    }

    // Determine if the LOIFG interrupt is active
    if (ADC14->IFGR1 & ADC14_IFGR1_LOIFG)
    {
        // Clear interrupt flag
        ADC14->CLRIFGR1 |= ADC14_CLRIFGR1_CLRLOIFG;
        // Turn off the LOW interrupt
        ADC14->IER1 &= ~ADC14_IER1_LOIE;
        // Turn on HI and IN interrupts
        ADC14->IER1 |= ADC14_IER1_HIIE | ADC14_IER1_INIE;
    }

    // Determine if the INIFG interrupt is active
    if (ADC14->IFGR1 & ADC14_IFGR1_INIFG)
    {
        // Clear interrupt flag
        ADC14->CLRIFGR1 |= ADC14_CLRIFGR1_CLRINIFG;
        // Turn off the IN interrupt
        ADC14->IER1 &= ~ADC14_IER1_INIE;
        // Turn on LOW and HI interrupts
        ADC14->IER1 |= ADC14_IER1_LOIE | ADC14_IER1_HIIE;
    }

    // Read the X channel
    PS2_X_DIR = ADC14->MEM[0];
}

void ice05_init_s1(void)
{
    // Configure the pin as an input
    P5->DIR &= ~BIT1;
    // Set the interrupt event to be a High to Low transition
    P5->IES |= BIT1;
    // Enable interrupts in the peripheral
    P5->IE |= BIT1;
    // Enable interrupts in the NVIC
    __enable_irq();
    NVIC_EnableIRQ(PORT5_IRQn);
    NVIC_SetPriority(PORT5_IRQn, 0);
    // Enable the IO Port interrupts in the NVIC

    // Set the priority of the IO Port interrupt to 0

}
