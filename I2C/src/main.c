/*
 * LED.c
 *
 * Created: 2023-11-17 오후 8:30:07
 * Author : jymen
 */ 

#include "main.h"


int main(void)
{
	hwInit();
	apInit();
	
	apMain();
	
	return 0;
}

