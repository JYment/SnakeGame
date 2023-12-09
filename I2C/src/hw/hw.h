/*
 * hw.h
 *
 * Created: 2023-11-17 오후 8:32:59
 *  Author: jymen
 */ 


#ifndef HW_H_
#define HW_H_


#include "hw_def.h"

#include "led.h"
#include "uart.h"
#include "cli.h"
#include "info.h"
#include "reset.h"
#include "i2c.h"


bool hwInit(void);


#endif /* HW_H_ */