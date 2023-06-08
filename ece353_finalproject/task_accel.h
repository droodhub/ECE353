/*
 * task_accel.h
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "msp432p401r.h"
#include "msp.h"
#include <main.h>
#include <stdbool.h>

#ifndef TASK_ACCEL_H_
#define TASK_ACCEL_H_

extern TaskHandle_t Task_Accel_Handle;
extern TaskHandle_t Task_Accel_Timer_Handle;
extern QueueHandle_t Queue_Player;

typedef enum {
    ACCEL_CENTER,
    ACCEL_LEFT,
    ACCEL_RIGHT,
} ACCEL_DIR_t;

void Task_Accelerometer_Timer(void *pvParameters);
void Task_Accelerometer_Bottom_Half(void *pvParmaters);

#endif /* TASK_ACCEL_H_ */
