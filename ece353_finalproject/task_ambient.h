/*
 * task_ambient.h
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "msp432p401r.h"
#include "msp.h"
#include <main.h>

#ifndef TASK_AMBIENT_H_
#define TASK_AMBIENT_H_

extern TaskHandle_t Task_LightSensor_Handle;
extern volatile float lightValue;
void Task_LightSensor(void *pvParameters);
float opt3001_read_lux(void);
void clearBackground(uint16_t background_color);

#endif /* TASK_AMBIENT_H_ */
