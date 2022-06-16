#include "Fun.h"
#include "main.h"
#include <stdio.h>
#include <string.h>
#include "tim.h"

extern uint8_t rxbuff[1];
void movef (void)
{
		switch(rxbuff[0])
		{
			case 1 ://qian jin
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,700);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,700);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,700);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,700);
			break;
			
			case 2 ://hou tui
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,700);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,700);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,700);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,700);
			break;
			
			case 3 ://you zhuan
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,800);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,800);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,800);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,800);
			break;
			
			case 4 ://zuo zhuan
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,800);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,800);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,800);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,800);
			break;
			
			case 5 ://zuo xuan zhuan
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,700);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,700);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,700);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,700);
			break;
			
			case 6 ://you xuan zhuan
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,700);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,700);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,700);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,700);
			break;
			
			default:
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
			break;
		}
}

void pitch1 (void)
{
	static int16_t compare=1500;
  if(rxbuff[0]==9)
	{
		compare = 1500;
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,1500);
	}
	if (rxbuff[0]==7)
	{
		if (compare < 1800)
		{
		compare += 10;
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,compare);
			HAL_Delay(30);
		}
		if(compare>=1800){
			compare = 1800;
			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,1800);
		}
	}	
	if (rxbuff[0]==8)
	{
		if (compare > 1000)
		{
		compare -= 10;
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,compare);
			HAL_Delay(30);
		}
		if(compare<=1000){
			compare = 1000;
			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,1000);
		}
		
	}
}

void dianji (void)
{
	
	if (rxbuff[0]==0x10)
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,500);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
	}else
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,0);
	}
	
	if (rxbuff[0]==0x15)
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_RESET);
	}
	
}
void yow1 (void)
{
	static int16_t compare1=1500;
  if(rxbuff[0]==0x11)
	{
		compare1 = 1500;
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,1500);
	}
	if (rxbuff[0]==0x12)
	{
		if (compare1 < 1800)
		{
		compare1 += 10;
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,compare1);
			HAL_Delay(30);
		}
		if(compare1>=1800){
			compare1 = 1800;
			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,1800);
		}
	}	
	if (rxbuff[0]==0x13)
	{
		if (compare1 > 1200)
		{
		compare1 -= 10;
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,compare1);
			HAL_Delay(30);
		}
		if(compare1<=1200){
			compare1 = 1200;
			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,1200);
		}
		
	}
}
void fei (void)
{
	if (rxbuff[0]==0x14)
	{
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1000);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,1000);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,1000);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,1000);
	}
	
}
