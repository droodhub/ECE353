//Author: Andrew Sabee
#include "interrupts.h"

// Create a global variable that will
// be used to alert the main application
// that 10 IO interrupts have been
// received.
volatile uint32_t PS2_X_DIR = 0;
volatile uint32_t PS2_Y_DIR = 0;
volatile bool BUTTON_PRESSED = false;

//*****************************************************************************
// Function used to initialize the IO pin
// connected to the S1 button on the MKII
//*****************************************************************************
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



//*****************************************************************************
// Interrupt Handler for the IO Port connected to S1
//
// Be sure to change the name of the handler to the correct handler
// name
//*****************************************************************************
/*
void PORT5_IRQHandler()
{
    // Variables needed for ISR
    // Do NOT add additional variables
    static int irq_count = 0;
    uint32_t reg_val;

    // increment the count.
    irq_count++;
    //If the count is > 10, alert the main application
    if(irq_count > 10){
        ALERT_BUTTON_PRESSES = true;
    }
    // Clear the interrupt.  Be sure to read the section of the
    // MSP432 TRM related to IO Interrupts to determine how to clear
    // an interrupt.
    reg_val = P5->IV;

}
*/
void PORT5_IRQHandler(){
    uint32_t reg_val;
    //alert system the button has been pressed
    BUTTON_PRESSED = true;
    //clear the interrupt
    reg_val = P5->IV;
}

void T32_INT1_IRQHandler(void)
{
    // Start the ADC conversion
    ADC14->CTL0 |= ADC14_CTL0_SC | ADC14_CTL0_ENC;

    // Clear the timer interrupt
    TIMER32_1->INTCLR = BIT0;
}

void ADC14_IRQHandler(void)
{
    // Read the X value
    PS2_X_DIR = ADC14->MEM[0];
    // Read the Y value
    PS2_Y_DIR = ADC14->MEM[1];
}

