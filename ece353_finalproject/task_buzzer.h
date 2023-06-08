/*
 * task_buzzer.h
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "msp432p401r.h"
#include "msp.h"
#include "main.h"
#include <stdint.h>
#include <stdbool.h>
#include "ECE353.h"

#ifndef TASK_BUZZER_H_
#define TASK_BUZZER_H_

extern TaskHandle_t Task_Buzzer_Handle;
void Task_Buzzer(void *pvParameters);
void initBuzzer(void);
/*
#define NOTE_B
#define NOTE_F
#define NOTE_E_HIGH
#define NOTE_D
#define NOTE_C_HIGH
#define NOTE_E_LOW 311
#define NOTE_G
#define NOTE_C_LOW 256
*/


#endif /* TASK_BUZZER_H_ */
