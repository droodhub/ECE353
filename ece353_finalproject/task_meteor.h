/*
 * task_meteor.h
 *
 *  Created on: May 4, 2023
 *      Author: cschlueter
 */

#ifndef TASK_METEOR_H_
#define TASK_METEOR_H_

#include <main.h>

extern TaskHandle_t Task_Meteor_Handle;
extern TaskHandle_t Task_Meteor2_Handle;
void  Task_Move_Meteors(void *pvParameters);
void Task_Move_Meteor2(void *pvParameters);






#endif /* TASK_METEOR_H_ */
