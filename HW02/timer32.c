/*
 * timer32.c
 *
 *  Created on: Oct 5, 2020
 *      Author: Andrew Sabee
 */

#include "timer32.h"
volatile bool BUTTON_PRESSED;
volatile bool SCREEN_READY;

void T32_1_init(void){
    uint32_t ticks = ((SystemCoreClock * 10)/1000) -1;

    TIMER32_1->CONTROL = 0;

    TIMER32_1->LOAD = ticks;

    __enable_irq();
    NVIC_EnableIRQ(T32_INT1_IRQn);
    NVIC_SetPriority(T32_INT1_IRQn, 0);

    TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE | TIMER32_CONTROL_MODE
                       | TIMER32_CONTROL_SIZE | TIMER32_CONTROL_IE;
}
void T32_2_init(void){

    uint32_t ticks = ((SystemCoreClock * 100)/1000) -1;

    TIMER32_2->CONTROL = 0;

    TIMER32_2->LOAD = ticks;

    __enable_irq();
    NVIC_EnableIRQ(T32_INT2_IRQn);
    NVIC_SetPriority(T32_INT2_IRQn, 0);

    TIMER32_2->CONTROL |= TIMER32_CONTROL_ENABLE | TIMER32_CONTROL_MODE
                       | TIMER32_CONTROL_SIZE | TIMER32_CONTROL_IE;
}

void ece353_MKII_S2_Init(void){
    //set our button's pin to be an input, enable pull up resistors
    P3->DIR &= ~BIT5;
    P3->REN |= BIT5;
    P3->OUT |= BIT5;

}

bool ece353_MKII_S2(void){
    //returns true if S2 is currently being pressed
    if((P3->IN & BIT5) == 0)
        return true;
    else
        return false;
}

void T32_INT1_IRQHandler(void){
    static uint8_t buttonPressed = 0;
    buttonPressed = buttonPressed << 1; //left shift 1, indicates a passage of 10ms

    if(ece353_MKII_S2()){
        buttonPressed |= 0x01;
    }

    if(buttonPressed == 0x7F){
         BUTTON_PRESSED = true;
    }

    // Start the ADC conversion
    ADC14->CTL0 |= ADC14_CTL0_SC | ADC14_CTL0_ENC;

    // Clear the timer interrupt
    TIMER32_1->INTCLR = BIT0;
}

void T32_INT2_IRQHandler(void){

    SCREEN_READY = true;
    // Clear the timer interrupt
    TIMER32_2->INTCLR = BIT0;
}
