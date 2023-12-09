/*
 * bsp.c
 *
 * Created: 2023-11-17 오후 8:32:02
 *  Author: jymen
 */ 


#include "bsp.h"



static volatile uint32_t ms_cnt = 0;


ISR(TCB0_INT_vect, ISR_NOBLOCK)
{
  ms_cnt++;
  TCB0.INTFLAGS = (1 << TCB_CAPT_bp);
}



void bspInit(void)
{
	CCP = CCP_IOREG_gc;
	CLKCTRL.MCLKCTRLA = (0 << CLKCTRL_CLKSEL_gp);

  CCP = CCP_IOREG_gc;
  CLKCTRL.MCLKCTRLB = (0 << CLKCTRL_PEN_bp);

  TCB0.CTRLA   = (0x00 << TCB_CLKSEL_gp);
  TCB0.CTRLB   = (0x00 << TCB_CNTMODE_gp);
  TCB0.INTCTRL = (1 << TCB_CAPT_bp);
  TCB0.CCMP    = (1000 * (F_CPU/1000000)) - 1;
  TCB0.CTRLA  |= (1 << TCB_ENABLE_bp);

  sei();
}


void delay(uint32_t ms)
{
	uint32_t pre_time = millis();
	while(millis() - pre_time < ms)
	{

	}
}

uint32_t millis(void)
{
	uint32_t ret;
  uint8_t old_sreg = SREG;
 

  cli();
  ret = ms_cnt;
  SREG = old_sreg;
	
	return ret;
}

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	
	return 0;
}
