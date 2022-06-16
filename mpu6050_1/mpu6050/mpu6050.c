#include "i2c.h"
#define	PWR_MGMT_1		0x6B	//电源管理，典型值：0x00(正常启用)

#define	SMPLRT_DIV		0x19	//陀螺仪采样率，典型值：0x07(125Hz)

#define	CONFIG			0x1A	//低通滤波频率，典型值：0x06(5Hz)

#define	GYRO_CONFIG		0x1B
//陀螺仪自检及测量范围，典型值：0x18(不自检，2000deg/s)
/*
0bxx<<3:
00 ~ +-250°
01 ~ +-500°
10 ~ +-1000°
11 ~ +-2000°
*/


#define	ACCEL_CONFIG	0x1C
//加速计自检、测量范围及高通滤波频率，典型值：0x01(不自检，2G，5Hz)
/*
0bxx<<3:
00 ~ +-2g
01 ~ +-4g
10 ~ +-18g
11 ~ +-16g
*/

#define	ACCEL_XOUT_H	0x3B//加速度计测量值寄存器地址
#define	ACCEL_XOUT_L	0x3C

#define	ACCEL_YOUT_H	0x3D //2 3
#define	ACCEL_YOUT_L	0x3E

#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
/********************/
#define	TEMP_OUT_H		0x41//温度测量值寄存器地址
#define	TEMP_OUT_L		0x42
/*********************/
#define	GYRO_XOUT_H		0x43// 8 9 陀螺仪测量值寄存器地址
#define	GYRO_XOUT_L		0x44

#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46

#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48

#define MPU6050_ADDR  	0xD0

#define MPU6050_WHO_AM_I         0x75

unsigned char IIC_buf[14];

signed short ax;
signed short ay;
signed short az;

signed short gx;
signed short gy;
signed short gz;

signed short ax_cl = 0;
signed short ay_cl = 0;
signed short az_cl = 0;

signed short gx_cl = 0;
signed short gy_cl = 0;
signed short gz_cl = 0;





void IIC_Write(unsigned char dev_addr,unsigned char mem_addr,unsigned char data)
{
	HAL_I2C_Mem_Write(&hi2c1,dev_addr,mem_addr,I2C_MEMADD_SIZE_8BIT,&data,1,2);
}

void IIC_Read(unsigned char dev_addr,unsigned char mem_addr,unsigned char *buf,unsigned char len)
{
	HAL_I2C_Mem_Read(&hi2c1,dev_addr,mem_addr,I2C_MEMADD_SIZE_8BIT,buf,len,2);
}

void MPU6050_Init(void)
{
	unsigned char temp = 0;
reset_MPU6050:
	IIC_Write(MPU6050_ADDR,PWR_MGMT_1,0x80);	//复位MPU6050
	HAL_Delay(50);
	IIC_Write(MPU6050_ADDR,PWR_MGMT_1,0x01);	//唤醒MPU6050，使用x轴PLL为时钟
	IIC_Read(MPU6050_ADDR, MPU6050_WHO_AM_I, &temp, 1);	//读ID
	temp &= 0x7e;
	//printf("%d\r\n",temp);
	if(temp != 0x68)
		goto reset_MPU6050;

	IIC_Write(MPU6050_ADDR,SMPLRT_DIV,0X00);
	IIC_Write(MPU6050_ADDR,CONFIG,0X00);

	IIC_Write(MPU6050_ADDR,GYRO_CONFIG,(0X00<<3));
	IIC_Write(MPU6050_ADDR,ACCEL_CONFIG,(0X00<<3));
}

void MPU6050_Get(void)
{
	IIC_Read(MPU6050_ADDR,ACCEL_XOUT_H,IIC_buf,14);

	ax = (IIC_buf[0]<<8) + IIC_buf[1];//X轴加速度
	ay = (IIC_buf[2]<<8) + IIC_buf[3];//Y轴加速度
	az = (IIC_buf[4]<<8) + IIC_buf[5];//Z轴加速度

	gx = (IIC_buf[8]<<8) + IIC_buf[9];//X轴角速度
	gy = (IIC_buf[10]<<8) + IIC_buf[11];//Y轴角速度
	gz = (IIC_buf[12]<<8) + IIC_buf[13];//Z轴角速度
}
