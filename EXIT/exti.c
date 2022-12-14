#include "exti.h"
#include "delay.h" 
#include "led.h" 
#include "key.h"
#include "ADS1292.h"
#include "usart.h"


//V1.1 20150118
//1,增加EXTI8_Init函数。
//2,增加EXTI9_5_IRQHandler函数											  
//////////////////////////////////////////////////////////////////////////////////  

//外部中断0服务程序
/*void EXTI0_IRQHandler(void)
{
	delay_ms(10);	//消抖
	if(WK_UP==1)	//WK_UP按键
	{				 
		BEEP=!BEEP;	
	}		 
	EXTI_ClearITPendingBit(EXTI_Line0); //清除LINE0上的中断标志位  
}*/
//外部中断2服务程序
//void EXTI2_IRQHandler(void)
//{
//	delay_ms(10);	//消抖
//	if(KEY2==0)	 	//按键KEY2
//	{
//		LED0=!LED0;
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line2); //清除LINE2上的中断标志位  
//}

//外部中断3服务程序
//void EXTI3_IRQHandler(void)
//{
//	delay_ms(10);	//消抖
//	if(KEY1==0)	 	//按键KEY1
//	{				 
//		LED1=!LED1;
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line3); //清除LINE3上的中断标志位  
//}


////外部中断4服务程序
//void EXTI4_IRQHandler(void)
//{
//	delay_ms(10);	//消抖
//	if(KEY0==0)	 	//按键KEY0
//	{
//		LED0=!LED0;
//		LED1=!LED1;
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line4); //清除LINE4上的中断标志位  
//}

//外部中断初始化程序
//初始化PA0/PE2/PE3/PE4为中断输入.
//void EXTIX_Init(void)
//{
// 	EXTI_InitTypeDef EXTI_InitStructure;
// 	NVIC_InitTypeDef NVIC_InitStructure;
// 
//	
//    KEY_Init();	 //	按键端口初始化

//  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//使能复用功能时钟

//    //GPIOE.2 中断线以及中断初始化配置   下降沿触发
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);

//  	EXTI_InitStructure.EXTI_Line=EXTI_Line2;	//KEY2
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  	EXTI_Init(&EXTI_InitStructure);	 	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

//   //GPIOE.3	  中断线以及中断初始化配置 下降沿触发 //KEY1
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;
//  	EXTI_Init(&EXTI_InitStructure);	  	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

////   //GPIOE.4	  中断线以及中断初始化配置  下降沿触发	//KEY0
////  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
////  	EXTI_InitStructure.EXTI_Line=EXTI_Line4;
////  	EXTI_Init(&EXTI_InitStructure);	  	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器


//   //GPIOA.0	  中断线以及中断初始化配置 上升沿触发 PA0  WK_UP
// 	 GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0); 

//  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
//  	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器


//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//使能按键WK_UP所在的外部中断通道
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2， 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//子优先级3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
//  	NVIC_Init(&NVIC_InitStructure); 

//    NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			//使能按键KEY2所在的外部中断通道
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2， 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//子优先级2
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
//  	NVIC_Init(&NVIC_InitStructure);


//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			//使能按键KEY1所在的外部中断通道
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//子优先级1 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
//  	NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

//	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			//使能按键KEY0所在的外部中断通道
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//子优先级0 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
//  	NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器	
//	

//}
u8 ov_sta;			//帧中断标记 
 //外部中断5~9服务程?
#define data_size    2000 //size of the data to be store in the flash
//volatile u8  ECG_DATA[data_size];//DATA TO STORE IN THE FLASH
u16 count_=0,ecg_delay=0;
volatile u8  start_to_store=0;//flag to store data

//void EXTI9_5_IRQHandler(void)
//{		
//OS_CPU_SR cpu_sr=0;
//	//OSIntEnter();  
//OS_ENTER_CRITICAL();	
//	if(EXTI->PR&(1<<0))			//是0线的中断
//	{      
//		EXTI_ClearITPendingBit(EXTI_Line8); //清除LINE8上的中断标志位  
//		
//		
////		if(ADS_DRDY==0)//数据接收中断				
////		{			
////			   
////	     
////			   ads1292_recive_flag=1;
////				ADS1292_Read_Data(ads1292_Cache);//数据存到9字节缓冲区
////				
////			//delay_ms(2);
////			// printf("Bonjour"); 
////		}	
////		//else OV7725_WREN=0;	//禁止写入FIFO 	 
//	} 
//	OSIntExit();  						  
//} 


void EXTI0_IRQHandler(void)
{		
	

	
	     
		EXTI_ClearITPendingBit(EXTI_Line0); //清除LINE8上的中断标志位  
		if(ADS_DRDY==0)//数据接收中断				
		{			
			   

			   ads1292_recive_flag=1;
				ADS1292_Read_Data(ads1292_Cache);//数据存到9字节缓冲区
			
			//printf("Good!\r\n");
    }


} 

//////外部中断8初始化
//void EXTI8_Init(void)
//{												  
// 	EXTI_InitTypeDef EXTI_InitStructure;
// 	NVIC_InitTypeDef NVIC_InitStructure;
// 	EXTI_InitStructure.EXTI_Line=EXTI_Line8;	 
// 	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
// 	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//升沿
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
// 	EXTI_Init(&EXTI_InitStructure);	 							//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键KEY0所在的外部中断通道
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//子优先级0 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//使能外部中断通道
//  	NVIC_Init(&NVIC_InitStructure);  	 						//根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器			
//}




//void EXTI0_Init(void)
//{
//	
//	  EXTI_InitTypeDef EXTI_InitStructure;
//	 	NVIC_InitTypeDef NVIC_InitStructure;
//    EXTI_ClearITPendingBit(EXTI_Line0);//清除中断标志
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource0);//选择管脚
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;						 //选择中断线路
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	 //设置为中断请求，非事件请求
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿触发
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;						 //外部中断使能
//  	EXTI_Init(&EXTI_InitStructure);	 
//		
//		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;					//选择中断通道
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级 2
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;				//子优先级   1
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;						//使能外部中断通道
//  	NVIC_Init(&NVIC_InitStructure); 
//}








