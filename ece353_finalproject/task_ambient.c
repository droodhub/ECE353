/*
 * task_ambient.c
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "task_ambient.h"
#include "math.h"
TaskHandle_t Task_LightSensor_Handle;
volatile float lightValue = 0;
static bool lightsOn = true;
extern uint16_t player_color;
extern uint16_t background_color;
extern uint16_t meteor_color;
uint16_t prev_player_color = LCD_COLOR_MAGENTA;

void Task_LightSensor(void *pvParameters){
    uint32_t eventOccurred;
    while(1){
        eventOccurred = ulTaskNotifyTake(true, portMAX_DELAY);
        lightValue = opt3001_read_lux(); //store the value of the ambient light sensor in lux
        //need to use our lux reading to 1)change the color of the screen and 2) maybe the speed of the meteors?
        //task notification if lux reading has changed enough to change the screen color?

        if (lightValue < 50) {
            player_color = LCD_COLOR_GREEN;
           // background_color = LCD_COLOR_BLACK;
            meteor_color = LCD_COLOR_BLACK;
        } else {
            player_color = LCD_COLOR_MAGENTA;
           // background_color = LCD_COLOR_WHITE;
            meteor_color = LCD_COLOR_RED;

        }


    }
}

void clearBackground(uint16_t background_color) {
    lcd_draw_rectangle(
                                64,
                                64,
                                132,
                                132,
                                background_color);
}


float opt3001_read_lux(void)
{
    uint16_t lux;
    // Read the Result register of OPT3001 and convert into Lux, then return.
   uint16_t data = i2c_read_16(OPT3001_SLAVE_ADDRESS, RESULT_REG);
   uint16_t exponent = (data >> 12) & 0x000F;
   uint16_t fractional = data & 0x0FFF;
   lux = 0.01 * pow(2, exponent) * fractional;

    return lux;
}
