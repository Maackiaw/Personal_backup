#include "struct_typedef.h"
#include "CAN_receive.h"
#include "pid.h"
#include "bsp_uart.h"

typedef struct
{
  const motor_measure_t *chassis_motor_measure;
  fp32 accel;
  fp32 speed;
  fp32 speed_set;
  int16_t give_current;
} chassis_motor_t;

typedef struct
{
  const rc_info_t *rc;
  chassis_motor_t motor_chassis[4];
  pid_type_def motor_speed_pid[4];
} chassis_move_t;

extern void chassis_task(void const *pvParameters);