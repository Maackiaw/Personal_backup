#include "chassis_task.h"
#include "pid.h"
#include "bsp_uart.h"
#include "CAN_receive.h"
#include "PSD_adc.h"
#include "main.h"
#include "adc.h"
#include "cmsis_os.h"
#include "bsp_rng.h"
#include "referee.h"
#include "bsp_imu.h"

chassis_move_t chassis_move;
extern uint16_t ADC_Value1[2];
fp32 left_distance;
fp32 right_distance;
uint8_t flag=1;
fp32 output = 0;

//��������
void chassis_task()
{
		static fp32 set_power = 0.0f;
		static int time = 0;
		static int rng = 0;
		static int count = 0;
		static int count2 = 100;
	  //static fp32 chassis_power = 0.0f;
    //static fp32 chassis_power_buffer = 0.0f;
		//��ʼ�� ��ȡң���������̵�����ݡ�����ϵͳ����
		chassis_move.rc = get_remote_control_point();
		chassis_move.motor_chassis[0].chassis_motor_measure = get_chassis_motor_measure_point(0);
    //get_chassis_power_and_buffer(&chassis_power, &chassis_power_buffer);
	  //get_chassis_power_and_buffer(&chassis_move.chassis_power, &chassis_move.chassis_power_buffer);
		chassis_move.power_heat_data_t = get_chassis_power_point();
		chassis_move.mpu_data = get_mpu_point();
		//��ʼ������״̬
		chassis_move.chassis_state = chassis_move.chassis_last_state = CHASSIS_RC;
	
		//PID��ʼ��
	  const static fp32 motor_power_pid[3] = {M3505_MOTOR_POWER_PID_KP, M3505_MOTOR_POWER_PID_KI, M3505_MOTOR_POWER_PID_KD};//���ʱջ�PID
		const static fp32 motor_power_buffer_pid[3] = {M3505_MOTOR_POWER_BUFFER_PID_KP, M3505_MOTOR_POWER_BUFFER_PID_KI, M3505_MOTOR_POWER_BUFFER_PID_KD};//���������ջ�PID
		const static fp32 motor_speed_pid[3] = {M3505_MOTOR_SPEED_PID_KP, M3505_MOTOR_SPEED_PID_KI, M3505_MOTOR_SPEED_PID_KD};//�ٶȱջ�PID
		
    PID_init(&chassis_move.motor_chassis[0].motor_speed_pid[0], PID_POSITION, motor_speed_pid, M3505_MOTOR_SPEED_PID_MAX_OUT, M3505_MOTOR_SPEED_PID_MAX_IOUT);
		PID_init(&chassis_move.motor_chassis[0].motor_power_pid[0], PID_POSITION, motor_power_pid, M3505_MOTOR_SPEED_PID_MAX_OUT, M3505_MOTOR_SPEED_PID_MAX_IOUT);
		PID_init(&chassis_move.motor_chassis[0].motor_power_buffer_pid[0], PID_POSITION, motor_power_buffer_pid, M3505_MOTOR_SPEED_PID_MAX_OUT, M3505_MOTOR_SPEED_PID_MAX_IOUT);

		
		chassis_move.motor_chassis[0].motor_speed_pid[0].out=0;
		chassis_move.motor_chassis[0].motor_power_pid[0].out=0;
		chassis_move.motor_chassis[0].motor_power_buffer_pid[0].out=0;


	while(1)
	{
		//ADC��������ת��Ϊ����ֵ
		left_distance = calc_distance(calc_voltage(ADC_Value1[0]));
	  right_distance = calc_distance(calc_voltage(ADC_Value1[1]));
		
		
		//ң�������Ƶ���ģʽ
		if (chassis_move.rc->sw1 == 1 && chassis_move.rc->sw2 == 2)//ң����sw1��sw2�� Ѳ�� ���ʱջ�
		{
			//��ײ��� ���⴫�����ж�
			if(chassis_move.chassis_state == CHASSIS_RC)
			{
				chassis_move.chassis_state = CHASSIS_SPEED_POSITIVE;
			}
			if (chassis_move.chassis_state == CHASSIS_SPEED_POSITIVE && right_distance < 50)
			{
				chassis_move.chassis_state = CHASSIS_SPEED_NEGATIVE;
				time = 0;
			}
			if (chassis_move.chassis_state == CHASSIS_SPEED_NEGATIVE && left_distance < 50)
			{
				chassis_move.chassis_state = CHASSIS_SPEED_POSITIVE;
				time = 0;
		  }
			time ++;
			
			//�ж�ʱ�� �Ƿ�ס
			if (time > 5000)
			{
				if (chassis_move.chassis_state == CHASSIS_SPEED_POSITIVE)
				{
					chassis_move.chassis_state = CHASSIS_SPEED_NEGATIVE;
				}
				else if (chassis_move.chassis_state == CHASSIS_SPEED_POSITIVE)
				{
					chassis_move.chassis_state = CHASSIS_SPEED_POSITIVE;
				}
			
			}
			
			
			
			
			
			//��ײ��� �����Ǽ��ٶ��ж�
//			switch(step)
//			{
//				case 1:
//					if (set_power >= 0 && abs(chassis_move.mpu_data->ay) >= 800)
//					{
//							set_power = -30;
//							step = 2;
//					}
//					else
//					{
//							set_power = 30;
//					}
//					break;
//				case 2:
//					if (set_power < 0 && abs(chassis_move.mpu_data->ay) >= 800)
//					{
//						set_power = 30;
//						step = 1;
//					}
//					else
//					{
//							set_power = -30;
//					}
//					break;
////			}

//count2 ++;
//if (count2 >= 100)
//{
//			if (set_power >= 0 && abs(chassis_move.mpu_data->ay) >= 800)
//			{
//				set_power = -30;
//				time = 0;
//				count2 = 0;
//			}
//			else if (set_power < 0 && abs(chassis_move.mpu_data->ay >= 800))
//			{
//				set_power = 30;
//				time = 0;
//				count2 = 0;
//			}
//}
		}
		
	if (chassis_move.rc->sw1 == 3 && chassis_move.rc->sw2 == 2)//ң����sw1��sw2�� ң�������� �ٶȱջ�
	{
		chassis_move.chassis_state = CHASSIS_RC;
	}
	
	if (chassis_move.rc->sw1 == 2 && chassis_move.rc->sw2 == 2)//ң����sw1 sw2�� ���� �ٶȱջ�
	{
		chassis_move.chassis_state = CHASSIS_UNABLE;
	}
	
	if (chassis_move.rc->sw1 == 2 && chassis_move.rc->sw2 == 3)//ң����sw1�� sw2�� ������� ���ʱջ�
	{
		//�������
		if (count == 0)//count = 0
		{
			if (chassis_move.chassis_last_state == CHASSIS_SPEED_NEGATIVE)
			{
				chassis_move.chassis_state = CHASSIS_SPEED_POSITIVE;
			}
			if (chassis_move.chassis_last_state == CHASSIS_SPEED_POSITIVE)
			{
				chassis_move.chassis_state = CHASSIS_SPEED_NEGATIVE;
			}
		}
		if (count > 0 && count <= 4000)
		{
			count--;
		}
		if (count <= 0)
		{
			rng = RNG_get_random_rangle(1800,3000);
			count = rng;
		}
		
		//��ײ���
			if (chassis_move.chassis_state == CHASSIS_SPEED_POSITIVE && right_distance < 50)
			{
				chassis_move.chassis_state = CHASSIS_SPEED_NEGATIVE;
			}
			if (chassis_move.chassis_state == CHASSIS_SPEED_NEGATIVE && left_distance < 50)
			{
				chassis_move.chassis_state = CHASSIS_SPEED_POSITIVE;
		  }
	}
		
	
	
	
	
	
	
	//�ж�״̬��
		if (chassis_move.chassis_state == CHASSIS_SPEED_POSITIVE)
		{
			set_power =30;
		}	
		else if (chassis_move.chassis_state == CHASSIS_SPEED_NEGATIVE)
		{
			set_power = -30;
		}
		else if (chassis_move.chassis_state == CHASSIS_RC)
		{
			set_power = chassis_move.rc->ch1*15;
		}
		else if (chassis_move.chassis_state == CHASSIS_UNABLE)
		{
			output = 0;
		}
		
		chassis_move.chassis_last_state = chassis_move.chassis_state;

		
		//ң�������� �ٶȱջ�
		if (chassis_move.chassis_state ==CHASSIS_RC)
		{
			PID_calc(&chassis_move.motor_chassis[0].motor_speed_pid[0],chassis_move.motor_chassis[0].chassis_motor_measure[0].speed_rpm,set_power);	
			output = chassis_move.motor_chassis[0].motor_speed_pid[0].out;
		}
		
		
		//Ѳ�� ������� ����+���������ջ�
		if (chassis_move.chassis_state == CHASSIS_SPEED_POSITIVE || chassis_move.chassis_state == CHASSIS_SPEED_NEGATIVE)
		{
		
		if (chassis_move.power_heat_data_t->chassis_power_buffer <= 100)
			{
				PID_calc(&chassis_move.motor_chassis[0].motor_power_buffer_pid[0],chassis_move.power_heat_data_t->chassis_power_buffer,130);
			}
  	PID_calc(&chassis_move.motor_chassis[0].motor_power_pid[0],chassis_move.power_heat_data_t->chassis_power,set_power);
		output = chassis_move.motor_chassis[0].motor_power_pid[0].out + chassis_move.motor_chassis[0].motor_power_buffer_pid[0].out;
			
		}
		
		CAN_cmd_chassis(output,0,0,0);
		
		vTaskDelay(1);
		//CAN_cmd_chassis(0,0,0,0);
		//flag=chassis_move.rc->sw1;
	}
}
