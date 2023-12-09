/*
 * led.h
 *
 * Created: 2023-11-17 오후 11:16:16
 *  Author: jymen
 */ 


#ifndef LED_H_
#define LED_H_


#include "hw_def.h"


#ifdef _USE_HW_LED


#define LED_MAX_CH        HW_LED_MAX_CH



bool ledInit(void);
bool ledDeInit(void);
void ledOn(uint8_t ch);
void ledOff(uint8_t ch);
void ledToggle(uint8_t ch);


#endif


#endif /* LED_H_ */