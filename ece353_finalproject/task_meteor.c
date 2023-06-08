/*
 * task_meteor.c
 *
 *  Created on: May 4, 2023
 *      Author: cschlueter
 */

#include "task_meteor.h"

TaskHandle_t Task_Meteor_Handle;
TaskHandle_t Task_Meteor2_Handle;

extern uint16_t background_color;
uint16_t meteor_color = LCD_COLOR_RED;
int meteor1_x;
extern int player_x;
int meteor2_y = 17;
int meteor1_y = 17;

void Task_Move_Meteors(void *pvParameters) {
    int meteor1_bottom;
    time_t t;
    srand( (unsigned) time(&t) );

    while (1) {
       meteor1_y = 17;
       meteor1_x = rand() % (LCD_HORIZONTAL_MAX - meteorWidthPixels);
       meteor1_x += meteorWidthPixels / 2;
        while(1) {
            lcd_draw_image(
            meteor1_x,
            meteor1_y++,
            meteorWidthPixels,
            meteorHeightPixels,
            meteorBitmaps,
            meteor_color,
            background_color);
            vTaskDelay(pdMS_TO_TICKS(50));
            meteor1_bottom = meteor1_y + (meteorHeightPixels / 2);
            if (meteor1_bottom > (LCD_VERTICAL_MAX - personHeightPixels) ) { //collision detection
                if ( abs(meteor1_x - player_x) < meteorWidthPixels/2 ) {
                    xTaskNotifyGive(Task_Buzzer_Handle);
                    meteor1_y = 17;
                    meteor2_y = 17;
                }
            }

            if (meteor1_y > LCD_VERTICAL_MAX - (meteorHeightPixels / 2)) {

                lcd_draw_rectangle(
                            meteor1_x,
                            meteor1_y,
                            meteorWidthPixels,
                            meteorHeightPixels + 10,
                            background_color);
                vTaskDelay(pdMS_TO_TICKS(1));
                break;
            }
        }


    }

}

void Task_Move_Meteor2(void *pvParameters) {

    int meteor2_x;
    int meteor2_bottom;
    time_t t;
    srand( (unsigned) time(&t) );

    while (1) {
       meteor2_y = 17;
       do {
       meteor2_x = rand() % (LCD_HORIZONTAL_MAX - meteorWidthPixels);
       meteor2_x += meteorWidthPixels / 2;
       } while (abs(meteor2_x - meteor1_x) < meteorWidthPixels);
       vTaskDelay(pdMS_TO_TICKS(2000));
       while(1) {
          lcd_draw_image(
             meteor2_x,
             meteor2_y++,
             meteorWidthPixels,
             meteorHeightPixels,
             meteorBitmaps,
             meteor_color,
             background_color);
          vTaskDelay(pdMS_TO_TICKS(50));
          meteor2_bottom = meteor2_y + (meteorHeightPixels / 2);
          if (meteor2_bottom > (LCD_VERTICAL_MAX - personHeightPixels) ) { //collision detection
             if ( abs(meteor2_x - player_x) < meteorWidthPixels/2 ) {
                 xTaskNotifyGive(Task_Buzzer_Handle);
                 meteor1_y = 17;
                 meteor2_y = 17;
              }
           }

               if (meteor2_y > LCD_VERTICAL_MAX - (meteorHeightPixels / 2)) {

                   lcd_draw_rectangle(
                               meteor2_x,
                               meteor2_y,
                               meteorWidthPixels,
                               meteorHeightPixels + 10,
                               background_color);
                   vTaskDelay(pdMS_TO_TICKS(1));
                   break;
               }
           }


       }
}


/*
void clearPlayerSpace() {
    uint32_t eventOccurred;
        while(1){
            eventOccurred = ulTaskNotifyTake(true, portMAX_DELAY);
            lcd_draw_rectangle(
                            64,
                            117,
                            132,
                            personHeightPixels,
                            LCD_COLOR_WHITE);
        }
}
*/


