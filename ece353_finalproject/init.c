/*
 * init.c
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "init.h"
/*
 * Initializes the peripherals used in this project
 * Need the LCD, Ambient Light Sensor, Accelerometer,
 * and maybe the MKII buttons and Timers
 * ALS and Accelerometer will both be done through the ADC I believe
 * Buzzer Init will be left for the task
 */
void init_board(){
//initialize LCD
    Crystalfontz128x128_Init();

    lcd_draw_rectangle(
            64,
            64,
            132,
            132,
            LCD_COLOR_WHITE);
    lcd_draw_image(
            64,
            117,
            personWidthPixels,
            personHeightPixels,
            personBitmaps,
            LCD_COLOR_MAGENTA,
            LCD_COLOR_WHITE);
    /*
    lcd_draw_image(
            64,
            17,
            meteorWidthPixels,
            meteorHeightPixels,
            meteorBitmaps,
            LCD_COLOR_RED,
            LCD_COLOR_WHITE);
            */
/*Initialize Ambient Light Sensor*/
    // Initialize OPT3001
    i2c_init();
    i2c_write_16(OPT3001_SLAVE_ADDRESS, CONFIG_REG, 0xC610);


//Initialize Accelerometer - replacing with joystick for now
    ece353_ADC14_Accel_Init();
    initBuzzer();
    ece353_MKII_S2_Init();
}
