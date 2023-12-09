/*
 * bsp.h
 *
 * Created: 2023-11-17 오후 8:32:08
 *  Author: jymen
 */ 


#ifndef BSP_H_
#define BSP_H_


#include "def.h"

#define F_CPU   20000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <avr/power.h>
#include <util/delay.h>




void bspInit(void);


void	 delay(uint32_t ms);
uint32_t millis(void);
long	 map(long x, long in_min, long in_max, long out_min, long out_max);


#endif /* BSP_H_ */