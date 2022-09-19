#include "exti.h"
#include "delay.h" 
#include "led.h" 
#include "key.h"
#include "ADS1292.h"
#include "usart.h"


//V1.1 20150118
//1,Ôö¼ÓEXTI8_Initº¯Êý¡£
//2,Ôö¼ÓEXTI9_5_IRQHandlerº¯Êý											  
//////////////////////////////////////////////////////////////////////////////////  

//Íâ²¿ÖÐ¶Ï0·þÎñ³ÌÐò
/*void EXTI0_IRQHandler(void)
{
	delay_ms(10);	//Ïû¶¶
	if(WK_UP==1)	//WK_UP°´¼ü
	{				 
		BEEP=!BEEP;	
	}		 
	EXTI_ClearITPendingBit(EXTI_Line0); //Çå³ýLINE0ÉÏµÄÖÐ¶Ï±êÖ¾Î»  
}*/
//Íâ²¿ÖÐ¶Ï2·þÎñ³ÌÐò
//void EXTI2_IRQHandler(void)
//{
//	delay_ms(10);	//Ïû¶¶
//	if(KEY2==0)	 	//°´¼üKEY2
//	{
//		LED0=!LED0;
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line2); //Çå³ýLINE2ÉÏµÄÖÐ¶Ï±êÖ¾Î»  
//}

//Íâ²¿ÖÐ¶Ï3·þÎñ³ÌÐò
//void EXTI3_IRQHandler(void)
//{
//	delay_ms(10);	//Ïû¶¶
//	if(KEY1==0)	 	//°´¼üKEY1
//	{				 
//		LED1=!LED1;
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line3); //Çå³ýLINE3ÉÏµÄÖÐ¶Ï±êÖ¾Î»  
//}


////Íâ²¿ÖÐ¶Ï4·þÎñ³ÌÐò
//void EXTI4_IRQHandler(void)
//{
//	delay_ms(10);	//Ïû¶¶
//	if(KEY0==0)	 	//°´¼üKEY0
//	{
//		LED0=!LED0;
//		LED1=!LED1;
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line4); //Çå³ýLINE4ÉÏµÄÖÐ¶Ï±êÖ¾Î»  
//}

//Íâ²¿ÖÐ¶Ï³õÊ¼»¯³ÌÐò
//³õÊ¼»¯PA0/PE2/PE3/PE4ÎªÖÐ¶ÏÊäÈë.
//void EXTIX_Init(void)
//{
// 	EXTI_InitTypeDef EXTI_InitStructure;
// 	NVIC_InitTypeDef NVIC_InitStructure;
// 
//	
//    KEY_Init();	 //	°´¼ü¶Ë¿Ú³õÊ¼»¯

//  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//Ê¹ÄÜ¸´ÓÃ¹¦ÄÜÊ±ÖÓ

//    //GPIOE.2 ÖÐ¶ÏÏßÒÔ¼°ÖÐ¶Ï³õÊ¼»¯ÅäÖÃ   ÏÂ½µÑØ´¥·¢
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);

//  	EXTI_InitStructure.EXTI_Line=EXTI_Line2;	//KEY2
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  	EXTI_Init(&EXTI_InitStructure);	 	//¸ù¾ÝEXTI_InitStructÖÐÖ¸¶¨µÄ²ÎÊý³õÊ¼»¯ÍâÉèEXTI¼Ä´æÆ÷

//   //GPIOE.3	  ÖÐ¶ÏÏßÒÔ¼°ÖÐ¶Ï³õÊ¼»¯ÅäÖÃ ÏÂ½µÑØ´¥·¢ //KEY1
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;
//  	EXTI_Init(&EXTI_InitStructure);	  	//¸ù¾ÝEXTI_InitStructÖÐÖ¸¶¨µÄ²ÎÊý³õÊ¼»¯ÍâÉèEXTI¼Ä´æÆ÷

////   //GPIOE.4	  ÖÐ¶ÏÏßÒÔ¼°ÖÐ¶Ï³õÊ¼»¯ÅäÖÃ  ÏÂ½µÑØ´¥·¢	//KEY0
////  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
////  	EXTI_InitStructure.EXTI_Line=EXTI_Line4;
////  	EXTI_Init(&EXTI_InitStructure);	  	//¸ù¾ÝEXTI_InitStructÖÐÖ¸¶¨µÄ²ÎÊý³õÊ¼»¯ÍâÉèEXTI¼Ä´æÆ÷


//   //GPIOA.0	  ÖÐ¶ÏÏßÒÔ¼°ÖÐ¶Ï³õÊ¼»¯ÅäÖÃ ÉÏÉýÑØ´¥·¢ PA0  WK_UP
// 	 GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0); 

//  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
//  	EXTI_Init(&EXTI_InitStructure);		//¸ù¾ÝEXTI_InitStructÖÐÖ¸¶¨µÄ²ÎÊý³õÊ¼»¯ÍâÉèEXTI¼Ä´æÆ÷


//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//Ê¹ÄÜ°´¼üWK_UPËùÔÚµÄÍâ²¿ÖÐ¶ÏÍ¨µÀ
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//ÇÀÕ¼ÓÅÏÈ¼¶2£¬ 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//×ÓÓÅÏÈ¼¶3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//Ê¹ÄÜÍâ²¿ÖÐ¶ÏÍ¨µÀ
//  	NVIC_Init(&NVIC_InitStructure); 

//    NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			//Ê¹ÄÜ°´¼üKEY2ËùÔÚµÄÍâ²¿ÖÐ¶ÏÍ¨µÀ
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//ÇÀÕ¼ÓÅÏÈ¼¶2£¬ 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//×ÓÓÅÏÈ¼¶2
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//Ê¹ÄÜÍâ²¿ÖÐ¶ÏÍ¨µÀ
//  	NVIC_Init(&NVIC_InitStructure);


//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			//Ê¹ÄÜ°´¼üKEY1ËùÔÚµÄÍâ²¿ÖÐ¶ÏÍ¨µÀ
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//ÇÀÕ¼ÓÅÏÈ¼¶2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//×ÓÓÅÏÈ¼¶1 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//Ê¹ÄÜÍâ²¿ÖÐ¶ÏÍ¨µÀ
//  	NVIC_Init(&NVIC_InitStructure);  	  //¸ù¾ÝNVIC_InitStructÖÐÖ¸¶¨µÄ²ÎÊý³õÊ¼»¯ÍâÉèNVIC¼Ä´æÆ÷

//	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			//Ê¹ÄÜ°´¼üKEY0ËùÔÚµÄÍâ²¿ÖÐ¶ÏÍ¨µÀ
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//ÇÀÕ¼ÓÅÏÈ¼¶2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//×ÓÓÅÏÈ¼¶0 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//Ê¹ÄÜÍâ²¿ÖÐ¶ÏÍ¨µÀ
//  	NVIC_Init(&NVIC_InitStructure);  	  //¸ù¾ÝNVIC_InitStructÖÐÖ¸¶¨µÄ²ÎÊý³õÊ¼»¯ÍâÉèNVIC¼Ä´æÆ÷	
//	

//}
u8 ov_sta;			//Ö¡ÖÐ¶Ï±ê¼Ç 
 //Íâ²¿ÖÐ¶Ï5~9·þÎñ³ÌÐ
#define data_size    2000 //size of the data to be store in the flash
//volatile u8  ECG_DATA[data_size];//DATA TO STORE IN THE FLASH
u16 count_=0,ecg_delay=0;
volatile u8  start_to_store=0;//flag to store data

//void EXTI9_5_IRQHandler(void)
//{		
//OS_CPU_SR cpu_sr=0;
//	//OSIntEnter();  
//OS_ENTER_CRITICAL();	
//	if(EXTI->PR&(1<<0))			//ÊÇ0ÏßµÄÖÐ¶Ï
//	{      
//		EXTI_ClearITPendingBit(EXTI_Line8); //Çå³ýLINE8ÉÏµÄÖÐ¶Ï±êÖ¾Î»  
//		
//		
////		if(ADS_DRDY==0)//Êý¾Ý½ÓÊÕÖÐ¶Ï				
////		{			
////			   
////	     
////			   ads1292_recive_flag=1;
////				ADS1292_Read_Data(ads1292_Cache);//Êý¾Ý´æµ½9×Ö½Ú»º³åÇø
////				
////			//delay_ms(2);
////			// printf("Bonjour"); 
////		}	
////		//else OV7725_WREN=0;	//½ûÖ¹Ð´ÈëFIFO 	 
//	} 
//	OSIntExit();  						  
//} 


void EXTI0_IRQHandler(void)
{		
	

	
	     
		EXTI_ClearITPendingBit(EXTI_Line0); //Çå³ýLINE8ÉÏµÄÖÐ¶Ï±êÖ¾Î»  
		if(ADS_DRDY==0)//Êý¾Ý½ÓÊÕÖÐ¶Ï				
		{			
			   

			   ads1292_recive_flag=1;
				ADS1292_Read_Data(ads1292_Cache);//Êý¾Ý´æµ½9×Ö½Ú»º³åÇø
			
			//printf("Good!\r\n");
    }


} 

//////Íâ²¿ÖÐ¶Ï8³õÊ¼»¯
//void EXTI8_Init(void)
//{												  
// 	EXTI_InitTypeDef EXTI_InitStructure;
// 	NVIC_InitTypeDef NVIC_InitStructure;
// 	EXTI_InitStructure.EXTI_Line=EXTI_Line8;	 
// 	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
// 	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//ÉýÑØ
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
// 	EXTI_Init(&EXTI_InitStructure);	 							//¸ù¾ÝEXTI_InitStructÖÐÖ¸¶¨µÄ²ÎÊý³õÊ¼»¯ÍâÉèEXTI¼Ä´æÆ÷
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//Ê¹ÄÜ°´¼üKEY0ËùÔÚµÄÍâ²¿ÖÐ¶ÏÍ¨µÀ
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//ÇÀÕ¼ÓÅÏÈ¼¶2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//×ÓÓÅÏÈ¼¶0 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//Ê¹ÄÜÍâ²¿ÖÐ¶ÏÍ¨µÀ
//  	NVIC_Init(&NVIC_InitStructure);  	 						//¸ù¾ÝNVIC_InitStructÖÐÖ¸¶¨µÄ²ÎÊý³õÊ¼»¯ÍâÉèNVIC¼Ä´æÆ÷			
//}




//void EXTI0_Init(void)
//{
//	
//	  EXTI_InitTypeDef EXTI_InitStructure;
//	 	NVIC_InitTypeDef NVIC_InitStructure;
//    EXTI_ClearITPendingBit(EXTI_Line0);//Çå³ýÖÐ¶Ï±êÖ¾
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource0);//Ñ¡Ôñ¹Ü½Å
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;						 //Ñ¡ÔñÖÐ¶ÏÏßÂ·
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	 //ÉèÖÃÎªÖÐ¶ÏÇëÇó£¬·ÇÊÂ¼þÇëÇó
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //ÏÂ½µÑØ´¥·¢
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;						 //Íâ²¿ÖÐ¶ÏÊ¹ÄÜ
//  	EXTI_Init(&EXTI_InitStructure);	 
//		
//		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;					//Ñ¡ÔñÖÐ¶ÏÍ¨µÀ
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//ÇÀÕ¼ÓÅÏÈ¼¶ 2
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;				//×ÓÓÅÏÈ¼¶   1
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;						//Ê¹ÄÜÍâ²¿ÖÐ¶ÏÍ¨µÀ
//  	NVIC_Init(&NVIC_InitStructure); 
//}








