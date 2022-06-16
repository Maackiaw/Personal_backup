#include "chassis_task.h"
#include "pid.h"
#include "bsp_uart.h"
#include "CAN_receive.h"

chassis_move_t chassis_move;

void chassis_task(void const *pvParameters)
{
//	chassis_move.rc = get_remote_control_point();
	CAN_cmd_chassis(10, 10, 10, 10);
	HAL_GPIO_WritePin(GPIOF, LED_GREEN_Pin,GPIO_PIN_RESET);
}
