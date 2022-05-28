#include "PSD_adc.h"


#define param_g 12.15
#define param_l 9.18
#define constant_g 0.1
#define constant_l 0.65

float calc_voltage(uint32_t adc_value){
	return ((float)3.3*adc_value)/4095;
}

/*
	V=param/(l+0.42)+constant

*/

float calc_distance(float voltage){
	fp32 distance=0;
	if(voltage<2.35)
		distance= param_g/(voltage-constant_g)-0.42;
	else
		distance = param_l/(voltage-constant_l)-0.42;
	if(distance>15||distance<=5)
	{
		return 100;
	}
	else
	{
		return distance;
	}
		
		
}


