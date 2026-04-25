#ifndef _MPU6050_H_
#define _MPU6050_H_
#include "sys.h"

#define MPU_SAMPLE_RATE_REG		0X19	//����Ƶ�ʷ�Ƶ��
#define MPU_CFG_REG				0X1A	//���üĴ���
#define	GYRO_CONFIG		0x1B	//�������Լ켰������Χ������ֵ��0x18(���Լ죬2000deg/s)
#define	ACCEL_CONFIG	0x1C	//���ټ��Լ졢������Χ����ͨ�˲�Ƶ�ʣ�����ֵ��0x01(���Լ죬2G��5Hz)
#define	ACCEL_XOUT_H	0x3B
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F

#define MPU_FIFO_EN_REG			0X23	//FIFOʹ�ܼĴ���
#define MPU_I2CMST_STA_REG		0X36	//IIC����״̬�Ĵ���
#define MPU_INTBP_CFG_REG		0X37	//�ж�/��·���üĴ���
#define MPU_INT_EN_REG			0X38	//�ж�ʹ�ܼĴ���
#define MPU_INT_STA_REG			0X3A	//�ж�״̬�Ĵ���
#define MPU_USER_CTRL_REG		0X6A	//�û����ƼĴ���

#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define	PWR_MGMT_1		0x6B
#define	PWR_MGMT_2		0x6C
#define	MPU_DEVICE_ID_REG	  	0x75
#define	MPU_ADDR	0x68 //IIC��ַ�Ĵ���0x68

uint8_t   mpu6050_write(uint8_t addr, uint8_t reg, uint8_t len, uint8_t* buf);//����ֵ 0�����ɹ�  -1����ʧ��
uint8_t   mpu6050_read (uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf);//����ֵ 0�����ɹ�  -1����ʧ��
void mpu6050_write_reg(uint8_t reg, uint8_t dat);
uint8_t   mpu6050_read_reg (uint8_t reg);
void DMP_MPU6050_Init(void);
short MPU_Get_Temperature(void);
uint8_t MPU_Get_Gyroscope(short *gx,short *gy,short *gz);
uint8_t MPU_Get_Accelerometer(short *ax,short *ay,short *az);

#endif