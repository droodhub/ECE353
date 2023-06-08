/*
 * task_player.c
 *
 *  Created on: May 3, 2023
 *      Author: cschlueter
 */

#include "task_player.h"

uint16_t player_color = LCD_COLOR_MAGENTA;
uint16_t background_color = LCD_COLOR_WHITE;
TaskHandle_t Task_Player_Handle;
QueueHandle_t Queue_Player;
int player_x = 64;

void Task_Move_Player(void *pvParameters) {

    ACCEL_DIR_t dir;

    while(1) {

        xQueueReceive(Queue_Player, &dir, portMAX_DELAY);
        if (dir == ACCEL_CENTER) {
            lcd_draw_image(
               player_x,
               117,
               personWidthPixels,
               personHeightPixels,
               personBitmaps,
               player_color,
               background_color);
        } else if (dir == ACCEL_LEFT) {
            if (player_x > personWidthPixels / 2)
                   player_x--;
            lcd_draw_image(
                player_x,
                117,
                personWidthPixels,
                personHeightPixels,
                personBitmaps,
                player_color,
                background_color);

        } else {
            if (player_x < LCD_HORIZONTAL_MAX - (personWidthPixels / 2) - 2)
                   player_x++;
            lcd_draw_image(
               player_x,
               117,
               personWidthPixels,
               personHeightPixels,
               personBitmaps,
               player_color,
               background_color);
        }



    }

}


