/*
 * task_accel.c
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "task_accel.h"
TaskHandle_t Task_Accel_Handle;
TaskHandle_t Task_Accel_Timer_Handle;

extern QueueHandle_t Queue_Player;

volatile uint32_t Accel_X_Direction = 0;
volatile uint32_t Accel_Y_Direction = 0;

void Task_Accelerometer_Timer(void *pvParameters){

    while(1){
        //Start ADC Conversion
        ADC14->CTL0 |= ADC14_CTL0_SC | ADC14_CTL0_ENC;

        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

void Task_Accelerometer_Bottom_Half(void *pvParameters){
    uint32_t eventOccurred;
    ACCEL_DIR_t dir;
    //ACCEL_DIR_t prevDir = ACCEL_CENTER;
    while(1){
        //wait for new measurements from accelerometer
        eventOccurred = ulTaskNotifyTake(true, portMAX_DELAY);

        if (Accel_X_Direction < 1500) {
            dir = ACCEL_LEFT;
        } else if (Accel_X_Direction > 2500) {
            dir = ACCEL_RIGHT;
        } else {
            dir = ACCEL_CENTER;
        }

        //now send the delay to the player

         xQueueSend(Queue_Player, &dir, portMAX_DELAY);
        // xTaskNotifyGive(Task_LightSensor_Handle);   //TODO: enabling this line made all movement stop

        //prevDir = dir;


    }
}

void ADC14_IRQHandler(){

    BaseType_t xHigherPriorityTaskWoken = pdFALSE; //same as pdFalse

    Accel_X_Direction = ADC14->MEM[0];
    Accel_Y_Direction = ADC14->MEM[1];

    vTaskNotifyGiveFromISR(Task_Accel_Handle, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}


