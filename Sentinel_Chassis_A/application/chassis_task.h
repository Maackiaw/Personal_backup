#include "struct_typedef.h"
#include "CAN_receive.h"
#include "pid.h"
#include "bsp_uart.h"

#define M3505_MOTOR_SPEED_PID_KP 20
#define M3505_MOTOR_SPEED_PID_KI 0
#define M3505_MOTOR_SPEED_PID_KD 0
#define M3505_MOTOR_SPEED_PID_MAX_OUT MAX_MOTOR_CAN_CURRENT
#define M3505_MOTOR_SPEED_PID_MAX_IOUT 2000.0f

#define MAX_MOTOR_CAN_CURRENT 16000.0f

typedef struct
{
  const motor_measure_t *chassis_motor_measure;
} chassis_motor_t;

typedef struct
{
  const rc_info_t *rc;
  chassis_motor_t motor_chassis[4];
  pid_type_def motor_speed_pid[4];
} chassis_move_t;

extern void chassis_task();