#include "MPU6050_I2C.h"
#include "MyI2C.h"
void MPU6050_IIC_IO_Init(void)
{
  My_GPIO_Init(MPU6050_IIC_GPIO,MPU6050_IIC_SCL_Pin|MPU6050_IIC_SDA_Pin,GPIO_TW_OUT,GPIO_P_NO,GPIO_50MHz);//������� ���� 50m

	MPU6050_IIC_SCL=1;
	MPU6050_IIC_SDA=1;
}

void MPU6050_IIC_SDA_IO_OUT(void)
{
	My_GPIO_Init(MPU6050_IIC_GPIO,MPU6050_IIC_SDA_Pin,GPIO_TW_OUT,GPIO_P_NO,GPIO_50MHz);//������� ���� 50m
}

void MPU6050_IIC_SDA_IO_IN(void)
{
	My_GPIO_Init(MPU6050_IIC_GPIO,MPU6050_IIC_SDA_Pin,GPIO_FK_IN,GPIO_P_UP,GPIO_50MHz);//�������� ���� 50m
}
//����MPU6050_IIC��ʼ�ź�
void MPU6050_IIC_Start(void)
{
	 MyI2C_Start();
}
//����MPU6050_IICֹͣ�ź�
void MPU6050_IIC_Stop(void)
{
	MyI2C_Stop();
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
uint8_t MPU6050_IIC_Read_Ack(void)
{
		return MyI2C_ReceiveAck();
}
//����ACKӦ��
void MPU6050_IIC_Send_Ack(uint8_t ack)
{
	MyI2C_SendAck(ack);
}
//MPU6050_IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��
void MPU6050_IIC_Send_Byte(uint8_t txd)
{
	MyI2C_SendByte(txd);
}
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK
uint8_t MPU6050_IIC_Read_Byte(uint8_t ack)
{
		unsigned char receive=MyI2C_ReceiveByte();
		MPU6050_IIC_delay_4us();
		MPU6050_IIC_Send_Ack(ack);
		return receive;
}


