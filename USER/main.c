#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "24cxx.h"
#include "touch.h"
#include "timer.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "dma.h"
#include "my_gui.h"
#include "ADS1292.h"

/*Key variable*/
vu8 key=0;	
void get_key_val();

int main(void)
{			
  
  delay_init(72);	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
  TIM3_Int_Init(999, 71);     // 1ms进入一次中断，为lvgl提供心跳
	LCD_Init();
  //ADS1292_Init();      //Initialize the ads1292r
  KEY_Init();         	//Initialization
	
	//LVGL initializations parts
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	//End of initializations 
	
	//Run ur examples here 
		my_gui();
	 

	while(1)
	{
		
		
    /*key**/
		get_key_val();
		/**********For lvgl library****************/
		lv_task_handler();
	}
	
}


void get_key_val(){
		/*key buttons here*/
		key=KEY_Scan(0);	//得到键值
	   	if(key)
		{						   
			switch(key)
			{				 
				case WKUP_PRES:	//控制蜂鸣器
					//
				printf("WKUP_PRES\r\n");
					break; 
				case KEY1_PRES:	//控制LED1翻转	 
					//printf("KEY1_PRES\r\n");
				my_gui_back_home();
					break;
				case KEY0_PRES:	//同时控制LED0,LED1翻转 
				printf("KEY0_PRES\r\n");
					break;
			}
	}


}