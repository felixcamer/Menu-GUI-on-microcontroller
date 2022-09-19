#include "exti.h"
#include "delay.h" 
#include "led.h" 
#include "key.h"
#include "ADS1292.h"
#include "usart.h"


//V1.1 20150118
//1,����EXTI8_Init������
//2,����EXTI9_5_IRQHandler����											  
//////////////////////////////////////////////////////////////////////////////////  

//�ⲿ�ж�0�������
/*void EXTI0_IRQHandler(void)
{
	delay_ms(10);	//����
	if(WK_UP==1)	//WK_UP����
	{				 
		BEEP=!BEEP;	
	}		 
	EXTI_ClearITPendingBit(EXTI_Line0); //���LINE0�ϵ��жϱ�־λ  
}*/
//�ⲿ�ж�2�������
//void EXTI2_IRQHandler(void)
//{
//	delay_ms(10);	//����
//	if(KEY2==0)	 	//����KEY2
//	{
//		LED0=!LED0;
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line2); //���LINE2�ϵ��жϱ�־λ  
//}

//�ⲿ�ж�3�������
//void EXTI3_IRQHandler(void)
//{
//	delay_ms(10);	//����
//	if(KEY1==0)	 	//����KEY1
//	{				 
//		LED1=!LED1;
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line3); //���LINE3�ϵ��жϱ�־λ  
//}


////�ⲿ�ж�4�������
//void EXTI4_IRQHandler(void)
//{
//	delay_ms(10);	//����
//	if(KEY0==0)	 	//����KEY0
//	{
//		LED0=!LED0;
//		LED1=!LED1;
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line4); //���LINE4�ϵ��жϱ�־λ  
//}

//�ⲿ�жϳ�ʼ������
//��ʼ��PA0/PE2/PE3/PE4Ϊ�ж�����.
//void EXTIX_Init(void)
//{
// 	EXTI_InitTypeDef EXTI_InitStructure;
// 	NVIC_InitTypeDef NVIC_InitStructure;
// 
//	
//    KEY_Init();	 //	�����˿ڳ�ʼ��

//  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��

//    //GPIOE.2 �ж����Լ��жϳ�ʼ������   �½��ش���
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);

//  	EXTI_InitStructure.EXTI_Line=EXTI_Line2;	//KEY2
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

//   //GPIOE.3	  �ж����Լ��жϳ�ʼ������ �½��ش��� //KEY1
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;
//  	EXTI_Init(&EXTI_InitStructure);	  	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

////   //GPIOE.4	  �ж����Լ��жϳ�ʼ������  �½��ش���	//KEY0
////  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
////  	EXTI_InitStructure.EXTI_Line=EXTI_Line4;
////  	EXTI_Init(&EXTI_InitStructure);	  	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���


//   //GPIOA.0	  �ж����Լ��жϳ�ʼ������ �����ش��� PA0  WK_UP
// 	 GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0); 

//  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
//  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���


//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//ʹ�ܰ���WK_UP���ڵ��ⲿ�ж�ͨ��
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//�����ȼ�3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
//  	NVIC_Init(&NVIC_InitStructure); 

//    NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			//ʹ�ܰ���KEY2���ڵ��ⲿ�ж�ͨ��
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//�����ȼ�2
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
//  	NVIC_Init(&NVIC_InitStructure);


//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			//ʹ�ܰ���KEY1���ڵ��ⲿ�ж�ͨ��
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//�����ȼ�1 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
//  	NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

//	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			//ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//�����ȼ�0 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
//  	NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���	
//	

//}
u8 ov_sta;			//֡�жϱ�� 
 //�ⲿ�ж�5~9������
#define data_size    2000 //size of the data to be store in the flash
//volatile u8  ECG_DATA[data_size];//DATA TO STORE IN THE FLASH
u16 count_=0,ecg_delay=0;
volatile u8  start_to_store=0;//flag to store data

//void EXTI9_5_IRQHandler(void)
//{		
//OS_CPU_SR cpu_sr=0;
//	//OSIntEnter();  
//OS_ENTER_CRITICAL();	
//	if(EXTI->PR&(1<<0))			//��0�ߵ��ж�
//	{      
//		EXTI_ClearITPendingBit(EXTI_Line8); //���LINE8�ϵ��жϱ�־λ  
//		
//		
////		if(ADS_DRDY==0)//���ݽ����ж�				
////		{			
////			   
////	     
////			   ads1292_recive_flag=1;
////				ADS1292_Read_Data(ads1292_Cache);//���ݴ浽9�ֽڻ�����
////				
////			//delay_ms(2);
////			// printf("Bonjour"); 
////		}	
////		//else OV7725_WREN=0;	//��ֹд��FIFO 	 
//	} 
//	OSIntExit();  						  
//} 


void EXTI0_IRQHandler(void)
{		
	

	
	     
		EXTI_ClearITPendingBit(EXTI_Line0); //���LINE8�ϵ��жϱ�־λ  
		if(ADS_DRDY==0)//���ݽ����ж�				
		{			
			   

			   ads1292_recive_flag=1;
				ADS1292_Read_Data(ads1292_Cache);//���ݴ浽9�ֽڻ�����
			
			//printf("Good!\r\n");
    }


} 

//////�ⲿ�ж�8��ʼ��
//void EXTI8_Init(void)
//{												  
// 	EXTI_InitTypeDef EXTI_InitStructure;
// 	NVIC_InitTypeDef NVIC_InitStructure;
// 	EXTI_InitStructure.EXTI_Line=EXTI_Line8;	 
// 	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
// 	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//����
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
// 	EXTI_Init(&EXTI_InitStructure);	 							//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ�2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//�����ȼ�0 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ʹ���ⲿ�ж�ͨ��
//  	NVIC_Init(&NVIC_InitStructure);  	 						//����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���			
//}




//void EXTI0_Init(void)
//{
//	
//	  EXTI_InitTypeDef EXTI_InitStructure;
//	 	NVIC_InitTypeDef NVIC_InitStructure;
//    EXTI_ClearITPendingBit(EXTI_Line0);//����жϱ�־
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource0);//ѡ��ܽ�
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;						 //ѡ���ж���·
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	 //����Ϊ�ж����󣬷��¼�����
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½��ش���
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;						 //�ⲿ�ж�ʹ��
//  	EXTI_Init(&EXTI_InitStructure);	 
//		
//		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;					//ѡ���ж�ͨ��
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ� 2
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;				//�����ȼ�   1
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;						//ʹ���ⲿ�ж�ͨ��
//  	NVIC_Init(&NVIC_InitStructure); 
//}








