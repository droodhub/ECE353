/*
 * task_player.h
 *
 *  Created on: May 3, 2023
 *      Author: cschlueter
 */

#ifndef TASK_PLAYER_H_
#define TASK_PLAYER_H_

#include <main.h>

extern TaskHandle_t Task_Player_Handle;
extern QueueHandle_t Queue_Player;

void Task_Move_Player(void *pvParameters);




#endif /* TASK_PLAYER_H_ */
