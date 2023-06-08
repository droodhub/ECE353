/*
 * timer32.c
 *
 *  Created on: Oct 5, 2020
 *      Author: YOUR NAME
 */

#include "timer32.h"

bool ALERT_S2_PRESSED = false;
bool UPDATE_LCD_SCREEN = false;

void initializeTimer32() {

    ece353_T32_1_Interrupt_Ms(10);

    TIMER32_2->CONTROL = 0;
    TIMER32_2->CONTROL = 0x62; //second timer uses prescale 256
    TIMER32_2->LOAD = 24000000;

    NVIC_EnableIRQ(T32_INT2_IRQn);
    NVIC_SetPriority(T32_INT2_IRQn, 2);

    //turn the timers on
    TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE;
    TIMER32_2->CONTROL |= TIMER32_CONTROL_ENABLE;
    //when an interrupt is generated it can be read from the masked interrupt
    //status register which is under T32 registers in tech ref manual

}

void T32_INT1_IRQHandler() {

   //start an adc14 conversion
   ADC14->CTL0 |= ADC14_CTL0_SC | ADC14_CTL0_ENC;

   //clear interrupt
   TIMER32_1->INTCLR = 0;
}

void T32_INT2_IRQHandler() {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE; //same as pdFalse
   //tell opt to calculate new light value
    vTaskNotifyGiveFromISR(Task_LightSensor_Handle, &xHigherPriorityTaskWoken);

    lcd_draw_rectangle(
               64,
               132 - (meteorWidthPixels / 2),
               132,
               meteorHeightPixels,
               LCD_COLOR_WHITE);

   //clear interrupt
   TIMER32_2->INTCLR = 0;
}

