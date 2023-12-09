/*
 * ap.c
 *
 * Created: 2023-11-17 오후 8:31:56
 *  Author: jymen
 */ 

#include "ap.h"



void apInit(void)
{
	cliOpen(_DEF_UART1, 115200);
	i2cBegin(_DEF_I2C1, 100000);
}

void apMain(void)
{
  uint32_t pre_time;


  pre_time = millis();
  while(1)
  {
    if(millis() - pre_time >= 200)
    {
      pre_time = millis();
  	  ledToggle(_DEF_LED1);
    }
		
		cliMain();
  }
}