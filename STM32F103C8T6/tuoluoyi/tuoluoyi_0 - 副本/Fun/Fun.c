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
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,500);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,500);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,500);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,500);
			break;
			
			case 2 ://hou tui
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,500);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,500);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,500);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,500);
			break;
			
			case 3 ://you zhuan
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,500);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,500);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,500);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,500);
			break;
			
			case 4 ://zuo zhuan
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,500);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,500);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,500);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,500);
			break;
			
			case 5 ://zuo xuan zhuan
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,500);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,500);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,500);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,500);
			break;
			
			case 6 ://you xuan zhuan
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,500);
			
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,500);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,500);
			
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,500);
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
			HAL_Delay(10);
		}
		if(compare>=1800){
			compare = 1800;
			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,1800);
		}
	}	
	if (rxbuff[0]==8)
	{
		if (compare > 1200)
		{
		compare -= 10;
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,compare);
			HAL_Delay(10);
		}
		if(compare<=1200){
			compare = 1200;
			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,1200);
		}
		
	}
}
