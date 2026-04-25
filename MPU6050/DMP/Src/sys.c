#include "sys.h"

//////////////////////////////////////////////////////////////////////////////////	 
//ϵͳ�жϷ������û�		   
//********************************************************************************  
//THUMBָ�֧�ֻ������
//�������·���ʵ��ִ�л��ָ��WFI  
void WFI_SET(void)
{
	__ASM volatile("wfi");		  
}
//�ر������ж�
void INTX_DISABLE(void)
{		  
	__ASM volatile("cpsid i");
}
//���������ж�
void INTX_ENABLE(void)
{
	__ASM volatile("cpsie i");		  
}
//����ջ����ַ
//addr:ջ����ַ



//stm32 ͨ�������ʼ�����������㲻ͬоƬ��ֲ
void My_GPIO_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,GPIO_My_TypeDef mode,GPIO_My_TypeDef up_down,GPIO_My_TypeDef speed)
{
	// GPIO_InitTypeDef  GPIO_InitStructure;
 //
	// RCC_APB2PeriphClockCmd(power(2,((uint32_t)GPIOx-(uint32_t)GPIOA)/0x0400+2), ENABLE);
 //
 //  GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
 //
	// if(mode==GPIO_AD_IN)
	// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	// if(mode==GPIO_FK_IN && up_down==GPIO_P_NO)
	// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	// if(mode==GPIO_FK_IN && up_down==GPIO_P_DOWN)
	// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	// if(mode==GPIO_FK_IN && up_down==GPIO_P_UP)
	// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	// if(mode==GPIO_KL_OUT)
	// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	// if(mode==GPIO_TW_OUT)
	// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	// if(mode==GPIO_KL_AF_OUT)
	// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	// if(mode==GPIO_TW_AF_OUT)
	// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
 //
 // 	if(speed==GPIO_2MHz)
	// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	// if(speed==GPIO_25MHz)
	// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	// if(speed==GPIO_50MHz)
	// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 //
 //  GPIO_Init(GPIOx, &GPIO_InitStructure);
}

uint32_t power(uint32_t x,uint32_t y)
{
		uint32_t mul = 1;

		uint32_t i;
		for( i = 0;i<y;i++)
		{
				mul = mul * x;
		}
		return mul;
}

uint32_t log_2(uint32_t x)
{
		uint8_t i=0;
		while(1)
		{
				if(power(2,i)==x)
					return i;
				else
					i++;
		}
}
