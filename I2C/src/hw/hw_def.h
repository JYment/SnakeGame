﻿/*
 * hw_def.h
 *
 * Created: 2023-11-17 오후 8:33:12
 *  Author: jymen
 */ 


#ifndef HW_DEF_H_
#define HW_DEF_H_


#include "def.h"
#include "bsp.h"


#define _USE_HW_LED
#define     HW_LED_MAX_CH						1

#define _USE_HW_UART
#define			HW_UART_MAX_CH					1

#define _USE_HW_CLI
#define     HW_CLI_CMD_LIST_MAX			16
#define     HW_CLI_CMD_NAME_MAX			14
#define     HW_CLI_LINE_HIS_MAX			4
#define     HW_CLI_LINE_BUF_MAX			48

#define _USE_HW_INFO

#define _USE_HW_RESET

#define _USE_HW_I2C
#define			HW_I2C_MAX_CH						1

#endif /* HW_DEF_H_ */