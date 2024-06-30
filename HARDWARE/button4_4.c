#include "button4_4.h"
#include <delay.h>
#include "usart.h"
/*********************************************************************
//�ӿڣ�PF0-PF7
1	-->PF7
2	-->PF6
3	-->PF5
4	-->PF4
5	-->PF0
6	-->PF1
7	-->PF2
8	-->PF3
*********************************************************************/
void Button4_4_Init(void)//
{
 GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��PORTBʱ��
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//ʹ��PORTBʱ��

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE); 
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_0;
 	GPIO_Init(KEY4_4PORT, &GPIO_InitStructure);//��ʼ��GPIOE2,3,4

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //���ó���������
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_4;	
	GPIO_Init(KEY4_4PORT, &GPIO_InitStructure);//��ʼ��GPIOA.0

//  //GPIOF9,F10��ʼ������
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_0;	 
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//����
//  GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��
//	GPIO_ResetBits(GPIOF,GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4);//GPIOF9,F10���õ�
//	
////	RCC_AHB1PeriphResetCmd(RCC_AHB1Periph_GPIOE, ENABLE);	 //
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_4;	
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
//  GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��

}

/*********************************************************************

**********************************************************************/
int Button4_4_Scan(void)
{
	int keyValue=0;//
	
	GPIO_Write(KEY4_4PORT,((KEY4_4PORT->ODR & 0xff00 )| 0x000f));//0123����
    
	if((KEY4_4PORT->IDR & 0x00f0)==0x0000)
		return -1;
	else
	{
		delay_ms(20);
		
		if((KEY4_4PORT->IDR & 0x00f0)==0x0000)//
		return -1;	
	
	}
	GPIO_Write(KEY4_4PORT,(KEY4_4PORT->ODR & 0xfff0 )| 0x0001);//?PA8-11??0001,?????
	printf("0x%x\r\n",KEY4_4PORT->IDR & 0x00f0);
	  switch(KEY4_4PORT->IDR & 0x00f0)
		{
			case 0x0010 : keyValue=13;break;
			case 0x0020 : keyValue=14;break;
			case 0x0040 : keyValue=15;break;
			case 0x0080 : keyValue=16;break;	
		}while((KEY4_4PORT->IDR & 0x00f0)!=0x0000);

	GPIO_Write(KEY4_4PORT,(KEY4_4PORT->ODR & 0xfff0 )| 0x0002);//?PA8-11??0010,?????
	printf("0x%x\r\n",KEY4_4PORT->IDR & 0x00f0);
	  switch(KEY4_4PORT->IDR & 0x00f0)
		{
			case 0x0010 : keyValue=9;break;
			case 0x0020 : keyValue=10;break;
			case 0x0040 : keyValue=11;break;
			case 0x0080 : keyValue=12;break;	
		}while((KEY4_4PORT->IDR & 0x00f0)!=0x0000);

	GPIO_Write(KEY4_4PORT,(KEY4_4PORT->ODR & 0xfff0 )| 0x0004);//?PA8-11??0100,?????
	printf("0x%x\r\n",KEY4_4PORT->IDR & 0x00f0);
	  switch(KEY4_4PORT->IDR & 0x00f0)
		{
			case 0x0010 : keyValue=5;break;
			case 0x0020 : keyValue=6;break;
			case 0x0040 : keyValue=7;break;
			case 0x0080 : keyValue=8;break;	
		}while((KEY4_4PORT->IDR & 0x00f0)!=0x0000);

	
	GPIO_Write(KEY4_4PORT,(KEY4_4PORT->ODR & 0xfff0 )| 0x0008);//?PA8-11??1000,?????
	printf("0x%x\r\n",KEY4_4PORT->IDR & 0x00f0);
	  switch(KEY4_4PORT->IDR & 0x00f0)
		{
			case 0x0010 : keyValue=1;break;
			case 0x0020 : keyValue=2;break;
			case 0x0040 : keyValue=3;break;
			case 0x0080 : keyValue=4;break;	
		}while((KEY4_4PORT->IDR & 0x00f0)!=0x0000);

	return keyValue;
}


