//Author: Andrew Sabee
#ifndef __ECE353_H__
#define __ECE353_H__

#include <stdint.h>
#include <stdbool.h>
#include "msp.h"


void ece353_led1_init(void);

void ece353_button1_init(void);

void ece353_led1(bool on);

bool ece353_button1(void);

void ece353_rgb_init(void);

void ece353_rgb(bool red_on, bool green_on, bool blue_on);

void ece353_button2_init(void);

bool ece353_button2(void);

void ece353_T32_1_wait_100mS(void);

void ece353_T32_1_wait(uint32_t time);

void ece353_T32_1_Interrupt_Ms(uint16_t ticks);

void ece353_button1_wait_for_press(void);


void ece353_MKII_RGB_IO_Init(bool en_primary_function);

void ece353_MKII_RGB_PWM(
        uint16_t ticks_period,
        uint16_t ticks_red_on,
        uint16_t ticks_green_on,
        uint16_t ticks_blue_on
);
void ece353_ADC14_PS2_XY(void);
void ece353_MKII_RGB_LED(bool red, bool green, bool blue);
void ece353_ADC14_PS2_XY_COMP(void);
void ece353_MKII_S1_Init(void);
void ece353_MKII_S2_Init(void);
bool ece353_MKII_S1(void);
bool ece353_MKII_S2(void);
void ece353_MKII_Buzzer_Init(uint16_t ticks_period);
void ece353_MKII_Buzzer_On(void);
void ece353_MKII_Buzzer_Off(void);
bool ece353_MKII_Buzzer_Run_Status(void);
void ece353_MKII_Buzzer_Off(void);

#endif
