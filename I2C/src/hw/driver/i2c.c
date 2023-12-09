/*
 * i2c.c
 *
 * Created: 2023-11-18 오후 1:29:45
 *  Author: jymen
 */ 

#include "i2c.h"
#include "cli.h"

#ifdef _USE_HW_I2C

#define TWI0_BAUD(F_SCL, T_RISE)        (uint8_t)((((((float)F_CPU / (float)(F_SCL)) - 10 - (((float)(F_CPU) * (T_RISE))/1000000.0))) / 2))


typedef enum
{
	I2C_ACKED  = 0,
	I2C_NACKED = 1,
	I2C_READY  = 2,
	I2C_ERROR  = 3
} i2c_state_t;



#ifdef _USE_HW_CLI
static void cliI2c(cli_args_t *args);
#endif


bool i2cInit(void)
{
	cliAdd("i2c", cliI2c);

	return true;
}

bool i2cBegin(uint8_t ch, uint32_t freq_khz)
{
	bool ret = false;

	switch(ch)
	{
		case _DEF_I2C1:
		
		PORTB.PIN0CTRL = PORT_PULLUPEN_bm;
		PORTB.PIN1CTRL = PORT_PULLUPEN_bm;
		PORTB.DIRSET = (1<<0) | (1<<1);

		TWI0.MBAUD   = TWI0_BAUD((freq_khz), 0.3);
		TWI0.MADDR   = 0x00;
		TWI0.MDATA   = 0x00;
		TWI0.MSTATUS = TWI_RIF_bm | TWI_WIF_bm | TWI_CLKHOLD_bm | TWI_RXACK_bm | TWI_ARBLOST_bm | TWI_BUSERR_bm | TWI_BUSSTATE_IDLE_gc;
		TWI0.MCTRLA  = TWI_ENABLE_bm;

		break;
	}

	return ret;
}

void i2cReset(uint8_t ch);

bool i2cIsDeviceReady(uint8_t ch, uint8_t dev_addr)
{
	bool ret = false;
	
	switch(ch)
	{
		case _DEF_I2C1:
		break;
	}

	return ret;
}

bool i2cRecovery(uint8_t ch);

bool i2cReadByte (uint8_t ch, uint16_t dev_addr, uint16_t reg_addr, uint8_t *p_data, uint32_t timeout);
bool i2cReadBytes(uint8_t ch, uint16_t dev_addr, uint16_t reg_addr, uint8_t *p_data, uint32_t length, uint32_t timeout);

bool i2cWriteByte (uint8_t ch, uint16_t dev_addr, uint16_t reg_addr, uint8_t data, uint32_t timeout)
{

}

bool i2cWriteBytes(uint8_t ch, uint16_t dev_addr, uint16_t reg_addr, uint8_t *p_data, uint32_t length, uint32_t timeout);

bool i2cReadData(uint8_t ch, uint16_t dev_addr, uint8_t *p_data, uint32_t length, uint32_t timeout)
{
	bool ret = false;

	switch(ch)
	{
		case _DEF_I2C1:
		break;
	}

	return ret;
}

bool i2cWriteData(uint8_t ch, uint16_t dev_addr, uint8_t *p_data, uint32_t length, uint32_t timeout)
{
	bool ret = false;
	uint32_t pre_time;
	
	switch(ch)
	{
		case _DEF_I2C1:

		pre_time = millis();
		while(length--)
		{
			TWI0.MDATA = *p_data;
			while(!((TWI0.MSTATUS & TWI_CLKHOLD_bm) || (TWI0.MSTATUS & TWI_BUSERR_bm) || (TWI0.MSTATUS & TWI_ARBLOST_bm) || (TWI0.MSTATUS & TWI_BUSSTATE_BUSY_gc) == TWI_BUSSTATE_BUSY_gc));
			if(TWI0.MSTATUS & TWI_RXACK_bm)
			{
				ret = false;
				break;
			}

			if(millis() - pre_time > timeout)
			{
				ret = false;
				break;
			}

			p_data++;
			ret = true;
		}
		break;
	}

	return ret;
}

void i2cEnd(uint8_t ch)
{
	switch(ch)
	{
		case _DEF_I2C1:
		TWI0.MCTRLB = TWI_MCMD_STOP_gc;
		break;
	}
}

void i2cSetTimeout(uint8_t ch, uint32_t timeout);
uint32_t i2cGetTimeout(uint8_t ch);

void i2cClearErrCount(uint8_t ch);
uint32_t i2cGetErrCount(uint8_t ch);


#ifdef _USE_HW_CLI
static void cliI2c(cli_args_t *args)
{
	bool ret = false;

	if (args->argc == 1 && args->isStr(0, "scan") == true)
	{
		for(uint8_t i=0x00; i<0x7F; i++)
		{
			if(i2cIsDeviceReady(_DEF_I2C1, i) == true)
			{
				cliPrintf("I2C CH%d Addr 0x%02X : OK\n", i+1);
			}
		}
		ret = true;
	}

	if (ret != true)
	{
		cliPrintf_P(PSTR("i2c scan\n"));
//		cliPrintf_P(PSTR("i2c write 0x00~0xFF\n"));
//		cliPrintf_P(PSTR("i2c write 0x00~0xFF\n"));
	}


}


#endif



#endif
