/*
 * init.h
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */

#include "msp.h"
#include "msp432p401r.h"
#include <main.h>

#ifndef INIT_H_
#define INIT_H_

//LCD Pins
#define LCD_SCK_PORT    P1
#define LCD_SCK_PIN     BIT5

#define LCD_MOSI_PORT   P1
#define LCD_MOSI_PIN    BIT6

#define LCD_CS_PORT     P5
#define LCD_CS_PIN      BIT0

#define LCD_RST_PORT    P5
#define LCD_RST_PIN     BIT7

#define LCD_DC_PORT     P3
#define LCD_DC_PIN      BIT7

//ALS Pins
#define OPT3001_SLAVE_ADDRESS 0x44

#define OPT_INTERRUPT_PIN 11
#define RESULT_REG 0x00
#define CONFIG_REG 0x01
#define LOWLIMIT_REG 0x02
#define HIGHLIMIT_REG 0x03
#define MANUFACTUREID_REG 0x7E
#define DEVICEID_REG 0x7F

void init_board(void);

#endif /* INIT_H_ */
