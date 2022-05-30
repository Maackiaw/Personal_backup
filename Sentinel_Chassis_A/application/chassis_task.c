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
fp32 output = 0;

//��������
void chassis_task()
{
		static int set_power = 0;
		//��ʼ�� ��ȡң���������̵�����ݡ�����ϵͳ����
		chassis_move.rc = get_remote_control_point();
		chassis_move.motor_chassis[0].chassis_motor_measure = get_chassis_motor_measure_point(0);
		get_chassis_power_and_buffer(&chassis_move.motor_chassis[0].chassis_power, &chassis_move.motor_chassis[0].chassis_power_buffer);
	
		//PID��ʼ��
	  const static fp32 motor_power_pid[3] = {M3505_MOTOR_POWER_PID_KP, M3505_MOTOR_POWER_PID_KI, M3505_MOTOR_POWER_PID_KD};//���ʱջ�PID
		const static fp32 motor_speed_pid[3] = {M3505_MOTOR_SPEED_PID_KP, M3505_MOTOR_SPEED_PID_KI, M3505_MOTOR_SPEED_PID_KD};//�ٶȱջ�PID
		
    PID_init(&chassis_move.motor_chassis[0].motor_speed_pid[0], PID_POSITION, motor_speed_pid, M3505_MOTOR_SPEED_PID_MAX_OUT, M3505_MOTOR_SPEED_PID_MAX_IOUT);
		PID_init(&chassis_move.motor_chassis[0].motor_power_pid[0], PID_POSITION, motor_power_pid, M3505_MOTOR_SPEED_PID_MAX_OUT, M3505_MOTOR_SPEED_PID_MAX_IOUT);
		
		chassis_move.motor_chassis[0].motor_speed_pid[0].out=0;
		chassis_move.motor_chassis[0].motor_power_pid[0].out=0;

	while(1)
	{
		//ADC��������ת��Ϊ����ֵ
		left_distance = calc_distance(calc_voltage(ADC_Value1[0]));
	  right_distance = calc_distance(calc_voltage(ADC_Value1[1]));
		
		//ң�������Ƶ���ģʽ
		if (chassis_move.rc->sw1 == 1)//ң����sw1�� Ѳ�� ���ʱջ�
		{
			if(set_power == 0)  
			{
				set_power =30;
			}
			if (set_power >= 0 && left_distance < 35)
			{
				set_power = -30;
			}
			if (set_power < 0 && right_distance < 35)
			{
			set_power = 30;
		  }
			
		PID_calc(&chassis_move.motor_chassis[0].motor_power_pid[0],chassis_move.motor_chassis[0].chassis_power,set_power);	
		output = chassis_move.motor_chassis[0].motor_power_pid[0].out;
		}
	if (chassis_move.rc->sw1 == 3)//ң����sw1�� ң�������� �ٶȱջ�
	{
		set_power = chassis_move.rc->ch1*15;
		
		PID_calc(&chassis_move.motor_chassis[0].motor_speed_pid[0],chassis_move.motor_chassis[0].chassis_motor_measure[0].speed_rpm,set_power);	
		output = chassis_move.motor_chassis[0].motor_speed_pid[0].out;
	}
	if (chassis_move.rc->sw1 == 2)//ң����sw1�� ���� �ٶȱջ�
	{
		set_power = 0;
		
		PID_calc(&chassis_move.motor_chassis[0].motor_speed_pid[0],chassis_move.motor_chassis[0].chassis_motor_measure[0].speed_rpm,set_power);
		output = chassis_move.motor_chassis[0].motor_speed_pid[0].out;
	}
	
		CAN_cmd_chassis(output,0,0,0);
	
		vTaskDelay(1);
		//CAN_cmd_chassis(0,0,0,0);
		flag=chassis_move.rc->sw1;
	}
}
