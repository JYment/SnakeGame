/*
 * hw.c
 *
 * Created: 2023-11-17 오후 8:33:06
 *  Author: jymen
 */ 

#include "hw.h"


bool hwInit(void)
{
	bspInit();

	cliInit();
	infoInit();
  ledInit();
	uartInit();
	resetInit();
	i2cInit();


  return true;
}