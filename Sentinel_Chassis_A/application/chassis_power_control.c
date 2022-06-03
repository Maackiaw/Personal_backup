/**
  ****************************(C) COPYRIGHT 2019 DJI****************************
  * @file       chassis_power_control.c/h
  * @brief      chassis power control.���̹��ʿ���
  * @note       this is only controling 80 w power, mainly limit motor current set.
  *             if power limit is 40w, reduce the value JUDGE_TOTAL_CURRENT_LIMIT 
  *             and POWER_CURRENT_LIMIT, and chassis max speed (include max_vx_speed, min_vx_speed)
  *             ֻ����80w���ʣ���Ҫͨ�����Ƶ�������趨ֵ,������ƹ�����40w������
  *             JUDGE_TOTAL_CURRENT_LIMIT��POWER_CURRENT_LIMIT��ֵ�����е�������ٶ�
  *             (����max_vx_speed, min_vx_speed)
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     Nov-11-2019     RM              1. add chassis power control
  *
  @verbatim
  ==============================================================================

  ==============================================================================
  @endverbatim
  ****************************(C) COPYRIGHT 2019 DJI****************************
  */
#include "chassis_power_control.h"
#include "referee.h"
#include "arm_math.h"
//#include "detect_task.h"
//#include "remote_control.h"
#define POWER_LIMIT 30.0f
#define WARNING_POWER 15.0f
#define WARNING_POWER_BUFF 100.0f

#define NO_JUDGE_TOTAL_CURRENT_LIMIT 64000.0f //16000 * 4,
//extern cap_measure_t cap_measure;
//extern RC_ctrl_t rc_ctrl;
/**
  * @brief          limit the power, mainly limit motor current
  * @param[in]      chassis_power_control: chassis data 
  * @retval         none
  */
/**
  * @brief          ���ƹ��ʣ���Ҫ���Ƶ������
  * @param[in]      chassis_power_control: ��������
  * @retval         none
  */
    fp32 max_power_limit = 30.0f;
		uint8_t cap_state=0;
void chassis_power_control(chassis_move_t *chassis_power_control)
{
    fp32 chassis_power = 0.0f;
    fp32 chassis_power_buffer = 0.0f;
    fp32 total_current_limit = 0.0f;
    fp32 total_current = 0.0f;
    fp32 buffer_total_current_limit = 0.0f;
    fp32 power_total_current_limit = 0.0f;
		fp32 cap_total_current_limit = 0.0f;
    uint8_t robot_id = get_robot_id();
//		if(rc_ctrl.key.v & KEY_PRESSED_OFFSET_E)
//		{
//			cap_state = 0;
//		}
//		if(rc_ctrl.key.v & KEY_PRESSED_OFFSET_Q)
//		{
//			cap_state = 1;
//		}
    #ifdef TEST 
//    if (toe_is_error(REFEREE_TOE))
//    {
//        total_current_limit = NO_JUDGE_TOTAL_CURRENT_LIMIT;
//    }
//    else if (!toe_is_error(REFEREE_TOE))
    //{
        get_chassis_power_and_buffer(&chassis_power, &chassis_power_buffer);
        //get_chassis_max_power(&max_power_limit);
				max_power_limit = 30;
        buffer_total_current_limit = max_power_limit * 200.00;
        power_total_current_limit = max_power_limit * 250.00;
//				if(!toe_is_error(CAP_TOE)&&cap_state)
//				{
//						cap_total_current_limit = max_power_limit * 100.00 * ( cap_measure.CapVot-18/cap_measure.InputVot);
//				}
//				else
//				{
//						cap_total_current_limit = 0;
//				}
				
        // power > 80w and buffer < 60j, because buffer < 60 means power has been more than 80w
        //���ʳ���80w �ͻ�������С��60j,��Ϊ��������С��60��ζ�Ź��ʳ���80w
        if (chassis_power_buffer < WARNING_POWER_BUFF)
        {
            fp32 power_scale;
            if (chassis_power_buffer > 20.0f)
            {
                //scale down WARNING_POWER_BUFF
                //��СWARNING_POWER_BUFF
                power_scale = chassis_power_buffer / WARNING_POWER_BUFF;
            }
            else
            {
                //only left 10% of WARNING_POWER_BUFF
                power_scale = 20.0f / WARNING_POWER_BUFF;
            }
            //scale down
            //��С
            total_current_limit = buffer_total_current_limit * power_scale;
        }
        else
        {
            //power > WARNING_POWER
            //���ʴ���WARNING_POWER
            if (chassis_power > max_power_limit / 2)
            {
                fp32 power_scale;
                //power < 80w
                //����С��80w
                if (chassis_power < max_power_limit)
                {
                    //scale down
                    //��С
                    power_scale = (max_power_limit - chassis_power) / (max_power_limit / 2);
                }
                //power > 80w
                //���ʴ���80w
                else
                {
                    power_scale = 0.0f;
                }

                total_current_limit = buffer_total_current_limit + power_total_current_limit * power_scale + cap_total_current_limit;
            }
            //power < WARNING_POWER
            //����С��WARNING_POWER
            else
            {
                total_current_limit = buffer_total_current_limit + power_total_current_limit + cap_total_current_limit;
            }
        }
    //}
    #endif
    #ifndef TEST
    if (toe_is_error(REFEREE_TOE))
    {
        total_current_limit = 8000.0f;
    }
    else if (!toe_is_error(REFEREE_TOE))
    {
        get_chassis_power_and_buffer(&chassis_power, &chassis_power_buffer);
        get_chassis_max_power(&max_power_limit);
    
        buffer_total_current_limit = max_power_limit * 200.00;
        power_total_current_limit = max_power_limit * 250.00;
        // power > 80w and buffer < 60j, because buffer < 60 means power has been more than 80w
        //���ʳ���80w �ͻ�������С��60j,��Ϊ��������С��60��ζ�Ź��ʳ���80w
        if (chassis_power_buffer < WARNING_POWER_BUFF)
        {
            fp32 power_scale;
            if (chassis_power_buffer > 5.0f)
            {
                //scale down WARNING_POWER_BUFF
                //��СWARNING_POWER_BUFF
                power_scale = chassis_power_buffer / WARNING_POWER_BUFF;
            }
            else
            {
                //only left 10% of WARNING_POWER_BUFF
                power_scale = 5.0f / WARNING_POWER_BUFF;
            }
            //scale down
            //��С
            total_current_limit = buffer_total_current_limit * power_scale;
        }
        else
        {
            //power > WARNING_POWER
            //���ʴ���WARNING_POWER
            if (chassis_power > max_power_limit / 2)
            {
                fp32 power_scale;
                //power < 80w
                //����С��80w
                if (chassis_power < max_power_limit)
                {
                    //scale down
                    //��С
                    power_scale = (max_power_limit - chassis_power) / (max_power_limit / 2);
                }
                //power > 80w
                //���ʴ���80w
                else
                {
                    power_scale = 0.0f;
                }

                total_current_limit = buffer_total_current_limit + power_total_current_limit * power_scale;
            }
            //power < WARNING_POWER
            //����С��WARNING_POWER
            else
            {
                total_current_limit = buffer_total_current_limit + power_total_current_limit;
            }
        }
    }
    #endif
    total_current = 0.0f;
    //calculate the original motor current set
    //����ԭ����������趨
    for (uint8_t i = 0; i < 4; i++)
    {
        total_current += fabs(chassis_power_control->motor_chassis[0].motor_speed_pid[0].out);
    }

    if (total_current > total_current_limit)
    {
        fp32 current_scale = total_current_limit / total_current;
        chassis_power_control->motor_chassis[0].motor_speed_pid[0].out *= current_scale;
//        chassis_power_control->motor_speed_pid[1].out *= current_scale;
//        chassis_power_control->motor_speed_pid[2].out *= current_scale;
//        chassis_power_control->motor_speed_pid[3].out *= current_scale;
    }
//	if(!toe_is_error(CAP_TOE))
//	{
//		static uint16_t time_cap = 20 ;
//		if(time_cap)
//		{
//			time_cap--;
//		}
//		if(!time_cap)
//		{
//		get_chassis_power_and_buffer(&chassis_power, &chassis_power_buffer);
//    get_chassis_max_power(&max_power_limit);
//		CAN_CMD_CAP(max_power_limit,chassis_power_buffer);
//		time_cap = 10;
//		}
//	}
}


