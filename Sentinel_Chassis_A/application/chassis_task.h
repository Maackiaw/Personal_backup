#include "struct_typedef.h"
#include "CAN_receive.h"
#include "pid.h"
#include "bsp_uart.h"
#include "referee.h"
#include "bsp_imu.h"

#define M3505_MOTOR_POWER_PID_KP 130
#define M3505_MOTOR_POWER_PID_KI 1
#define M3505_MOTOR_POWER_PID_KD 0
#define M3505_MOTOR_SPEED_PID_KP 20
#define M3505_MOTOR_SPEED_PID_KI 0
#define M3505_MOTOR_SPEED_PID_KD 0
#define M3505_MOTOR_POWER_BUFFER_PID_KP -0.5
#define M3505_MOTOR_POWER_BUFFER_PID_KI 0
#define M3505_MOTOR_POWER_BUFFER_PID_KD 200

#define M3505_MOTOR_SPEED_PID_MAX_OUT MAX_MOTOR_CAN_CURRENT
#define M3505_MOTOR_SPEED_PID_MAX_IOUT 2000.0f

#define MAX_MOTOR_CAN_CURRENT 16000.0f



typedef enum
{
	CHASSIS_SPEED_NEGATIVE = 0,
	CHASSIS_SPEED_POSITIVE,
	CHASSIS_RC,
	CHASSIS_UNABLE,
}chassis_state_e;


typedef struct
{
  const motor_measure_t *chassis_motor_measure;
  pid_type_def motor_speed_pid[4];
	pid_type_def motor_power_pid[4];
	pid_type_def motor_power_buffer_pid[4];
} chassis_motor_t;

typedef struct
{
  const rc_info_t *rc;
	const ext_power_heat_data_t *power_heat_data_t;
	const mpu_data_t *mpu_data;
  chassis_motor_t motor_chassis[4];
	chassis_state_e chassis_state;
	chassis_state_e chassis_last_state;
} chassis_move_t;

extern void chassis_task();