/*
 * reset.h
 *
 * Created: 2023-11-18 오후 12:04:27
 *  Author: jymen
 */ 


#ifndef RESET_H_
#define RESET_H_


#include "hw_def.h"


#ifdef _USE_HW_RESET



enum ResetMode
{
	RESET_MODE_RUN_BOOT = (1<<0)
};

enum ResetSrc
{
	RESET_FROM_POWER = (1<<0),
	RESET_FROM_BOD   = (1<<1),
	RESET_FROM_PIN   = (1<<2),
	RESET_FROM_WDG   = (1<<3),
	RESET_FROM_SOFT  = (1<<4),
	RESET_FROM_ETC   = (1<<5),
};


bool    resetInit(void);
void    resetLog(void);
void    resetToBoot(uint8_t mode);
uint8_t resetGetBits(void);
void    resetSetBits(uint8_t data);
void    resetSetMode(uint8_t mode);
uint8_t resetGetMode(void);

#endif


#endif /* RESET_H_ */