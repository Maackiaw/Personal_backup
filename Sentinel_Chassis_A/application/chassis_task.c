#include "chassis_task.h"
#include "pid.h"
#include "bsp_uart.h"
#include "CAN_receive.h"
#include "PSD_adc.h"
#include "main.h"
#include "adc.h"
#include "cmsis_os.h"
chassis_move_t chassis_move;
extern uint16_t ADC_Value1[2];
fp32 left_distance;
fp32 right_distance;
 uint8_t flag=1;
void chassis_task()
{
		chassis_move.rc = get_remote_control_point();
		chassis_move.motor_chassis[0].chassis_motor_measure = get_chassis_motor_measure_point(0);
	  const static fp32 motor_speed_pid[3] = {M3505_MOTOR_SPEED_PID_KP, M3505_MOTOR_SPEED_PID_KI, M3505_MOTOR_SPEED_PID_KD};
		static int i = 0;
		static int set_speed = 0;
    PID_init(&chassis_move.motor_speed_pid[0], PID_POSITION, motor_speed_pid, M3505_MOTOR_SPEED_PID_MAX_OUT, M3505_MOTOR_SPEED_PID_MAX_IOUT);
		chassis_move.motor_speed_pid[0].out=0;
		

	while(1)
	{

		left_distance = calc_distance(calc_voltage(ADC_Value1[0]));
	  right_distance = calc_distance(calc_voltage(ADC_Value1[1]));
		
		if (chassis_move.rc->sw1 == 1)
		{
			if(set_speed == 0)
			{
				set_speed =6000;
			}
			if (set_speed >= 0 && left_distance < 15)
			{
				set_speed = -6000;
			}
			if (set_speed < 0 && right_distance < 15)
			{
			set_speed = 6000;
				
		  }
		}
	if (chassis_move.rc->sw1 == 3)
	{
		set_speed = chassis_move.rc->ch1*10;
	}
	if (chassis_move.rc->sw1 == 2)
	{
		set_speed = 0;
	}
		//set_speed = chassis_move.rc->ch1*10;
		PID_calc(&chassis_move.motor_speed_pid[0],chassis_move.motor_chassis[0].chassis_motor_measure->speed_rpm,set_speed);	
		CAN_cmd_chassis(chassis_move.motor_speed_pid[0].out,0,0,0);
		vTaskDelay(1);
		//HAL_Delay(1);
		//CAN_cmd_chassis(0,0,0,0);
	flag=chassis_move.rc->sw1;
	}
}
