#ifndef __MPU6050_I2C_H
#define __MPU6050_I2C_H
#include "sys.h"
#include "delay.h"

//�����ֲ����ʱֻҪ��һ�µط�������
#define MPU6050_IIC_GPIO                   GPIOG
#define MPU6050_IIC_SCL_Pin                GPIO_PIN_11	         //PB11
#define MPU6050_IIC_SDA_Pin                GPIO_PIN_13	         //PB13

#define	MPU6050_IIC_SCL                    PGout(11)
#define	MPU6050_IIC_SDA                    PGout(13)
#define	MPU6050_IIC_SDA_IN                 PGin(11)              //�����ݶ˿�
#define MPU6050_IIC_delay_4us()            delay_us(4)


//MPU6050_IIC���в�������
void MPU6050_IIC_IO_Init(void);               //��ʼ��MPU6050_IIC��IO��	
void MPU6050_IIC_SDA_IO_OUT(void);    
void MPU6050_IIC_SDA_IO_IN(void);
void MPU6050_IIC_Start(void);				          //����MPU6050_IIC��ʼ�ź�
void MPU6050_IIC_Stop(void);	  			        //����MPU6050_IICֹͣ�ź�
void MPU6050_IIC_Send_Byte(uint8_t txd);			      //MPU6050_IIC����һ���ֽ�
uint8_t   MPU6050_IIC_Read_Byte(uint8_t ack);           //MPU6050_IIC��ȡһ���ֽ�
uint8_t   MPU6050_IIC_Read_Ack(void); 				      //MPU6050_IIC�ȴ�ACK�ź�
void MPU6050_IIC_Send_Ack(uint8_t ack);					  //MPU6050_IIC����ACK�ź�

#endif
