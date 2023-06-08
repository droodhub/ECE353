/*
 * main.h
 *
 *  Created on: May 1, 2023
 *      Author: apmcavoy
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "msp.h"
#include "msp432p401r.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "ECE353.h"
#include "timer32.h"
#include <stdlib.h>
#include <time.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>
/* task header files */
#include <task_accel.h>
#include <task_ambient.h>
#include <task_buzzer.h>
#include <task_meteor.h>
#include <init.h>
#include <i2c.h>
#include <lcd.h>
#include <ECE353.h>
#include <meteor.h>
#include <person.h>
#include "music.h"
#include <task_player.h>

#endif /* MAIN_H_ */
