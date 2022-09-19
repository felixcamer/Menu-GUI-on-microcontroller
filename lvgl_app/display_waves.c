#include "display_waves.h"
#include "my_gui_theme.h"
#include "ADS1292.h"
#include "my_gui.h"
#include "ecg_resp_pross.h"


typedef struct
{
	lv_obj_t *heart_rate;             //display the heart rate 
	lv_obj_t *time_recoder;           //display the time of recording

}My_labels;                         //Label structure of objects such as voltage

typedef struct
{
	lv_style_t chart_style;           //Set the background style variable of the chart
	lv_style_t chart_serie_style;     //Set the variables of chart serie
	lv_style_t style_bar_bg;          //styl for the bar back ground
	lv_style_t style_bar_indic;       //styl for the bar indicator
	lv_style_t style_heart_rate;      //styl for heart rate indicator
	lv_style_t style_heart_rate_bg;   //styl for heart rate indicator
	lv_style_t style_time_recorder;   //styl for time recorder indicator
	lv_style_t style_time_bar_bg;     //styl for time recorder bar

}My_styles;                     //Style variable structure

typedef struct
{
	lv_obj_t *scr;                //Load the object of the currently active screen
	lv_obj_t *Chart;              //The handle of the chart
	lv_chart_series_t *serie;     //The handle of the data line waveform
	lv_obj_t *heart;              //RED HEART ON THE BOTTOM OF THE CHAR
	lv_obj_t *bar0;                //Bar0 for bg
	lv_obj_t *bar1;                //Bar1
	lv_obj_t *pop;                 //please set the electrodes pop up
	lv_obj_t *ecg_disp_res;            //display result
	lv_obj_t *win_1;
}My_obj;                        //Object set


typedef struct
{
	lv_task_t *info_dsp_task;       //A task to refresh the waveform
	lv_task_t *ecg_dsp_task;
	
}My_task;                       //Task set

typedef struct
{
	u16 point[2];    
  u16 point_old[2];        
  s32	p_Temp[2];	        //p_Temp[0]  for ecg
  double data[4];       //data[0],data[1] for ecg and data[2],data[3] for ppg
  u32 channle[2];       // number of channel
	u32 lead;             //lead off data contener
	u16 x_time;		        //display  time
	uint32_t LeadStatus;
}My_display_data;                         //Structure ton hold all the displaying data

	/****************************/
/************
 Object variable definition area
*************/

My_labels my_labels;             //Define the first tab page variable
My_styles my_styles;             //Define the first style collection
My_obj    my_objs;               //Define a set of objects related to the chart
My_task   my_tasks;              //Define a task set that contains the task of refreshing the waveform
My_display_data my_ecg_ppg_dat_dsp;

static uint16_t  bar_controler = 0;
volatile u8  start_wave = 0;
u16 second=0;
u8 stat_bar = 0;
u8 step=0;
u16 aveg_heartRate = 0;
u16 recording_time = 30;  //recording time of the ecg or ppg

/*********************************************
           EVENT DECLARATION
***********************************************/

LV_EVENT_CB_DECLARE(back_icon_cb);
LV_EVENT_CB_DECLARE(play_icon_cb);
LV_EVENT_CB_DECLARE(detail_icon_cb);

/************
 Function definition area
*************/
void wave_record_bar(int16_t time_ms);            //Display the wave record bar
void heart_rate_disp(int16_t heart_rate);            //Display the heart rate 
void time_bar_disp(int16_t time_s);                  //Display the label of the bar
u8 LeadChecker();                                    //check thelead 
static void start_ecg();
static void wait_stil();
float w0_[3]={0},w1_[3]={0},w2_[3]={0}; //filters registers


/************
 Write out labels such as the maximum value of voltage
************/

/************
 Create my window and put all the child in to the window
************/
void Creat_MyWave(void)
{
	
	/*Create a chart*/
    my_objs.win_1 = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_set_size(my_objs.win_1, 320, 240);
	  lv_obj_set_style_local_bg_color( my_objs.win_1, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	  lv_obj_set_style_local_border_side(my_objs.win_1,LV_STATE_DEFAULT,0,0);
	  lv_obj_align(my_objs.win_1, NULL, LV_ALIGN_CENTER, 0, 0);
	/* display the heart rate */
	  my_labels.heart_rate= lv_label_create(my_objs.win_1, NULL);
    lv_obj_set_style_local_text_color(my_labels.heart_rate, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_ORANGE);
    lv_obj_set_style_local_text_font(my_labels.heart_rate, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_20);
	
	/*display the time bar*/
	  my_labels.time_recoder= lv_label_create(my_objs.win_1, NULL);
    lv_obj_set_style_local_text_color(my_labels.time_recoder, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_obj_set_style_local_text_font(my_labels.time_recoder, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);
	 

	  heart_rate_disp(QRS_Heart_Rate1);                   //set the heart rate 
	  time_bar_disp(0);                                   //initialize the progress of recording
	
	/*Fill the array data */
		/*******************************************************************/
	  /* Set the red heart on the chart windows*/ 
    my_objs.heart = lv_img_create(my_objs.win_1, NULL);
	  LV_IMG_DECLARE(red_heart);
    lv_img_set_src(my_objs.heart , &red_heart);
    lv_obj_align(my_objs.heart, NULL, LV_ALIGN_IN_TOP_RIGHT, -60, 1);
	
   //**************************************************************************
    start_ads1292();  //start the ads1292
		start_ecg();      //start with the pop up message 
	
	/*start the displaying of the ecg*/
		ecg_realtime_disp_task_etr();
	
}

/*********************************
Add a text to an object
*********************************/
void addText(const char * txt, lv_obj_t * src,lv_align_t aline,lv_coord_t x,lv_coord_t y,lv_color_t color,const lv_font_t *font){

    lv_obj_t * text = lv_label_create(src, NULL);
	  lv_obj_set_style_local_text_color(text, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, color);
	  lv_obj_set_style_local_text_font(text, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, font );
    lv_label_set_text(text, txt);
    lv_obj_align(text, NULL, aline, x,y);
}


/********************************************************
This function display the message of "Set Electrodes...."
********************************************************/
static void start_ecg(){
    my_objs.pop = lv_obj_create(my_objs.win_1, NULL);
	 //lv_obj_align(my_objs.pop, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_local_bg_color(my_objs.pop, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_obj_set_size(my_objs.pop, 200, 70);
	  addText("Please Check Electrodes....", my_objs.pop,LV_ALIGN_CENTER ,0,4,LV_COLOR_BLACK, &lv_font_montserrat_12);
    lv_obj_align(my_objs.pop, NULL, LV_ALIGN_CENTER, 0, 0);
	  lv_obj_set_hidden( my_objs.heart,true);        //hid the red heart
	  lv_obj_set_hidden( my_labels.heart_rate,true); //hid the heart rate displaying
	  lv_obj_set_hidden( my_labels.time_recoder,true);  //hid the time recorder
	  start_wave =0;  //wait for the lead
		stat_bar = 1;
		bar_controler=0;	
}

/********************************************************
Wait still function for the white window
********************************************************/

void lv_ex_arc_1(void) 
{
  /*Create an Arc*/
  lv_obj_t * arc = lv_spinner_create(lv_scr_act(), NULL);
	lv_obj_set_style_local_bg_color(arc, LV_SPINNER_PART_INDIC, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	lv_obj_set_style_local_border_side(arc,LV_STATE_DEFAULT,0,0);
  lv_arc_set_end_angle(arc, 200);
  lv_obj_set_size(arc, 100, 100);
  lv_obj_align(arc, NULL, LV_ALIGN_CENTER, 0, 0);
}

static void wait_stil(){

    my_objs.pop= lv_obj_create(my_objs.win_1, NULL);
    lv_obj_set_style_local_bg_color(my_objs.pop, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	  lv_obj_set_style_local_text_color(my_objs.pop,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_WHITE);
	  lv_obj_set_style_local_border_side(my_objs.pop,LV_STATE_DEFAULT,0,0);
    lv_obj_set_size(my_objs.pop, 200, 200);
	  addText("Wait Still", my_objs.pop,LV_ALIGN_IN_TOP_MID,0,6,LV_COLOR_WHITE, &lv_font_montserrat_12);
    lv_obj_align(my_objs.pop, NULL, LV_ALIGN_CENTER, 0, 0);

    /*Create a Preloader object*/
  lv_obj_t * arc = lv_spinner_create(my_objs.pop, NULL);
	lv_obj_set_style_local_bg_color(arc, LV_SPINNER_PART_INDIC, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_arc_set_end_angle(arc, 100);
  lv_obj_set_size(arc, 100, 100);
  lv_obj_align(arc, NULL, LV_ALIGN_CENTER, 0, 0);
	 
}

/********************************************************
Finich the ecg recording and pop up the new window function
********************************************************/
 void finich_ecg_recor(){
	 //lv_obj_clean(my_objs.Chart);
	 /*declare the images*/
	 LV_IMG_DECLARE(play_icon);
	 LV_IMG_DECLARE(back_icon);
	 LV_IMG_DECLARE(exclamation_icon);
	  char buf[1];
	 
	 /*stop collecting the data samples*/
	  start_wave=0;
	  stat_bar =0;
	 
	 
	 /* declare a pop up window after displaying*/
	  //lv_obj_del( my_objs.Chart);
	  my_objs.ecg_disp_res = lv_obj_create(my_objs.win_1, NULL);
    lv_obj_set_style_local_bg_color( my_objs.ecg_disp_res, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_obj_set_size( my_objs.ecg_disp_res, 320, 240);
	  //addTitle("Regular heart beat", my_objs.pop,LV_ALIGN_IN_TOP_MID,0,5);
    lv_obj_align( my_objs.ecg_disp_res, NULL, LV_ALIGN_CENTER, 0, 0);
	  lv_obj_set_hidden( my_objs.heart,true);        //hid the red heart
	  lv_obj_set_hidden( my_labels.heart_rate,true); //hid the heart rate displaying
	  lv_obj_set_hidden( my_labels.time_recoder,true);  //hid the time recorder
		
		 /*add the theme */
	  lv_obj_t *child_ = lv_obj_create( my_objs.ecg_disp_res, NULL);
    lv_obj_set_style_local_bg_color(child_, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, MY_GUI_GREEN );
	  lv_obj_set_style_local_text_color(child_, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE );
		lv_obj_set_size(child_, 320, 40);
		addText("Regular heart beat", child_,LV_ALIGN_IN_TOP_MID,0,6,LV_COLOR_WHITE, &lv_font_montserrat_20);
    
		 
		/*Show the analysis of the wave(including the heart rate )*/
		sprintf(buf, " %d ", aveg_heartRate);
		addText("Heart Rate",my_objs.ecg_disp_res,LV_ALIGN_IN_LEFT_MID,20,0,LV_COLOR_BLACK, &lv_font_montserrat_20);
		addText(buf,my_objs.ecg_disp_res,LV_ALIGN_IN_LEFT_MID,20*8,0,LV_COLOR_BLUE, &lv_font_montserrat_20);
		addText("/min",my_objs.ecg_disp_res,LV_ALIGN_IN_LEFT_MID,20*10,0,LV_COLOR_BLACK, &lv_font_montserrat_20);
		
		
	 /* back image on the windows*/
	  lv_obj_t * back_icon_ = lv_img_create( my_objs.ecg_disp_res, NULL);
		lv_img_set_src(back_icon_, &back_icon);
    lv_obj_align(back_icon_, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 35, -5);
    lv_obj_set_click(back_icon_, true);
	  lv_obj_set_event_cb(back_icon_, back_icon_cb);  //event for back
		
	 	 /* play image on the windows*/
	  lv_obj_t * play_icon_ = lv_img_create( my_objs.ecg_disp_res, NULL);
		lv_img_set_src(play_icon_, &play_icon);
    lv_obj_align(play_icon_, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -5);
    lv_obj_set_click(play_icon_, true);
		lv_obj_set_event_cb(play_icon_, play_icon_cb);  //event for play
		
		
		/* detail image on the windows*/
	  lv_obj_t * detail_icon_ = lv_img_create( my_objs.ecg_disp_res, NULL);
		lv_img_set_src(detail_icon_, &exclamation_icon);
    lv_obj_align(detail_icon_, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -35, -5);
    lv_obj_set_click(detail_icon_, true);
		lv_obj_set_event_cb(detail_icon_, detail_icon_cb);  //event for back
	}
 
/********************************************************
show the progress of the recording in a bar object
********************************************************/
void wave_record_bar(int16_t time_ms)
{
	  /* Style of the indicator*/
    lv_style_init(&my_styles.style_bar_indic);
    lv_style_set_bg_color(&my_styles.style_bar_indic, LV_STATE_DEFAULT, MY_GUI_LIGHT_ORANGE);
    lv_style_set_bg_opa(&my_styles.style_bar_indic, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_radius(&my_styles.style_bar_indic, LV_STATE_DEFAULT, 10);
	
	  /*Bar settings*/
     my_objs.bar0 = lv_bar_create(my_objs.win_1, NULL);
    lv_obj_set_size(my_objs.bar0, 180, 15);
	  lv_obj_align(my_objs.bar0, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 1);
    lv_obj_set_style_local_bg_color(my_objs.bar0, LV_BAR_PART_INDIC, LV_STATE_DEFAULT, MY_GUI_LIGHT_GRAY);
    lv_bar_set_value(my_objs.bar0, 100, LV_ANIM_OFF);

    my_objs.bar1 = lv_bar_create(my_objs.win_1, NULL);
    lv_obj_set_size(my_objs.bar1, 180, 15);
	  lv_bar_set_range(my_objs.bar1, 0, 30);                       //you can change the range here
    lv_obj_align(my_objs.bar1, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 1);
		lv_obj_add_style(my_objs.bar1,LV_BAR_PART_INDIC ,&my_styles.style_bar_indic);
    lv_bar_set_anim_time(my_objs.bar1, time_ms);         //controll the time here
    lv_bar_set_value(my_objs.bar1, 100, LV_ANIM_ON);
		
}

/****************************
 Heart rate label displaying 
****************************/
void heart_rate_disp(int16_t heart_rate){

    /*display the heart rate label*/
	  lv_obj_clean( my_labels.heart_rate);
	
	  /*update the new heart rate*/
	  if(lv_obj_get_screen(my_labels.heart_rate) == lv_scr_act()) {
            char buf[1];
            sprintf(buf, " %d ", heart_rate);
            lv_label_set_text(my_labels.heart_rate, buf);
       }
		 
    lv_obj_align(my_labels.heart_rate, NULL, LV_ALIGN_IN_TOP_RIGHT,-10, 1);
}


/****************************
 Time bar label displaying 
****************************/
void time_bar_disp(int16_t time){

   lv_obj_clean( my_labels.time_recoder);
	  /*update the new heart rate*/
	  if(lv_obj_get_screen(my_labels.time_recoder) == lv_scr_act()) {
            char buf[1];
            sprintf(buf, " %d ", time);
            lv_label_set_text(my_labels.time_recoder, buf);
       }
    lv_obj_align(my_labels.time_recoder, NULL, LV_ALIGN_IN_TOP_RIGHT,-95, 1);		 
}



/*************************************
 Create a task to refresh the waveform
**************************************/
//Callback function to refresh the waveform

void ReWave_cb(lv_task_t* task)
{				
     //printf("bar_controler = %d\r\n",bar_controler);	
	  
	  /*Count number of second*/
	      second++;
			 if( second==5 && start_wave ==0 ){
       
			    wave_record_bar(recording_time*1000);
			 }

           
	    if(bar_controler>=recording_time)//changer le temps ici
			{ 
				
				aveg_heartRate = aveg_heartRate/bar_controler;  //calculate the average heart rate 
				bar_controler=0;
				start_wave = 0;
		    stat_bar = 0;
				
				/*Stop the ads1292*/
		    stop_ads1292();
				
        lv_task_once(my_tasks.info_dsp_task);
				lv_task_once(my_tasks.ecg_dsp_task);
				finich_ecg_recor();
				
			}
			  if(stat_bar==0 && start_wave==1)
	 	    {
					bar_controler++;
					time_bar_disp(bar_controler);
					heart_rate_disp(QRS_Heart_Rate1);
	        aveg_heartRate += QRS_Heart_Rate1;
					second = 0;
				
				}
}


/*****************************************
 display in realtime the ecg 
call this function periodically
*****************************************/
void ecg_realtime_cb(lv_task_t*task){
	
	
	 //printf("inside ecg task\r\n");
	if(LeadChecker()==1 && stat_bar==1){
	
		
		//Hid the pop up
		//lv_obj_set_hidden( my_objs.pop,true);
		lv_obj_del(my_objs.pop);
	  
		start_wave = 0;
		stat_bar = 0;
		bar_controler=0;
		
		wait_stil();
	  ReWave_task_etr();
	
	
}
	
		if(second==5){   //wait 5 second and then start the displaying
			
			
			lv_obj_set_hidden(my_objs.pop,true);
			lv_obj_set_hidden( my_objs.heart,false);        //show the red heart
	    lv_obj_set_hidden( my_labels.heart_rate,false); //show the heart rate displaying
	    lv_obj_set_hidden( my_labels.time_recoder,false);  //show the time recorder
			start_wave = 1;
		}
		
		
	//we should give the disply his own task
 if(ads1292_recive_flag && start_wave == 1)
						{			
							  ads1292_recive_flag=0;	
								my_ecg_ppg_dat_dsp.point_old[0] = my_ecg_ppg_dat_dsp.point[0];//保留上次坐标		
								my_ecg_ppg_dat_dsp.channle[0]=ads1292_Cache[6]<<16 | ads1292_Cache[7]<<8 | ads1292_Cache[8];//获取数据																
								my_ecg_ppg_dat_dsp.p_Temp[0] = get_volt(my_ecg_ppg_dat_dsp.channle[0]);	//无符号转成有符号
                my_ecg_ppg_dat_dsp.data[0] = my_ecg_ppg_dat_dsp.p_Temp[0] * 0.2885;		//参考为2.42时的电压值 单位uV
							/*ECG*/
	               //ECG_ProcessCurrSample_(&my_ecg_ppg_dat_dsp.data[0], &my_ecg_ppg_dat_dsp.data[1]);
						  	my_ecg_ppg_dat_dsp.data[1] = ecg_filters_(my_ecg_ppg_dat_dsp.data[0],w0_,w1_,w2_);
							//dcRemoval(Curr,0.9,CurrAqsSample);
							   QRS_Algorithm_Interface(my_ecg_ppg_dat_dsp.data[1],&QRS_Heart_Rate1);
							/*RESPIRATION*/
							  //data[2] = Resp_ProcessCurrSample(data[1]);
              //RESP_Algorithm_Interface(data[1],Heart_rate);
						 /*
							Zoom image (need to adjust these two parameters according 
							to the sample value displayed on the screen to make it
							displayed in the middle of the screen)						
							//p_Temp[1] = (p_Temp[1]-x)/y;*/
											
								my_ecg_ppg_dat_dsp.p_Temp[0]=my_ecg_ppg_dat_dsp.data[1];//just added
								//p_Temp[1]=data[2];
								my_ecg_ppg_dat_dsp.p_Temp[0] = (my_ecg_ppg_dat_dsp.p_Temp[0]-1000)/100;	//100 
							
							/*ECG*/
							if(my_ecg_ppg_dat_dsp.p_Temp[0] <=-150)		//Limit the coordinate between the screens
											my_ecg_ppg_dat_dsp.p_Temp[0] = -150;
								else if(my_ecg_ppg_dat_dsp.p_Temp[0] > 120)
											my_ecg_ppg_dat_dsp.p_Temp[0] = 130;	//130
            
								my_ecg_ppg_dat_dsp.point[0] = 160 - my_ecg_ppg_dat_dsp.p_Temp[0];//2 1 160
							
								 //printf("$%d;",my_ecg_ppg_dat_dsp.point[0]);
								printf("%d\r\n",my_ecg_ppg_dat_dsp.point[0]);
								
								//delay_ms(5);	
								LCD_Fill(my_ecg_ppg_dat_dsp.x_time,25,my_ecg_ppg_dat_dsp.x_time+1,lcddev.height,BLACK);		//time		
								POINT_COLOR=GREEN;
								LCD_DrawLine(my_ecg_ppg_dat_dsp.x_time,my_ecg_ppg_dat_dsp.point_old[0],my_ecg_ppg_dat_dsp.x_time+1,my_ecg_ppg_dat_dsp.point[0]);//line
								
							  my_ecg_ppg_dat_dsp.x_time++;																												
								if(my_ecg_ppg_dat_dsp.x_time>=326)	my_ecg_ppg_dat_dsp.x_time=0;	//239		
							}		
					
}

/*****************************************
 check the electrod if it is connected, return 1 if true and 0 if not 
*****************************************/
u8 LeadChecker(){

  if(((ads1292_Cache[0] & 0x0E) == 0 )){
	   return 1;
	}
		else{ return 0;}
}


/*****************************************
1 s task , this function is called every one second
*****************************************/
void ReWave_task_etr(void)
{
	//Set the time to 0, it should be able to execute immediately
	
	my_tasks.info_dsp_task=lv_task_create(ReWave_cb,1000,LV_TASK_PRIO_LOW,NULL);

}


/*****************************************
task function
*****************************************/
void ecg_realtime_disp_task_etr(void){

//Set the time to 0, it should be able to execute immediately
my_tasks.ecg_dsp_task=lv_task_create(ecg_realtime_cb,5,LV_TASK_PRIO_MID,NULL);
}



/*****************************************
event to return back to the main menu
*****************************************/
LV_EVENT_CB_DECLARE(back_icon_cb){
     if (e == LV_EVENT_CLICKED) {
 
			 /*start bar*/
			 lv_obj_del( my_objs.ecg_disp_res );
			 lv_obj_del(my_objs.win_1);
			 stat_bar=1;
			 my_gui_back_home();
			
    }
 
}

/*****************************************
 replay the recorded ecg function
*****************************************/
LV_EVENT_CB_DECLARE(play_icon_cb){
     if (e == LV_EVENT_CLICKED) {
       // paly_ecg();
			  printf("Play ecg \r\n");
    }
 
}

/*****************************************
Show detail function event
*****************************************/
LV_EVENT_CB_DECLARE(detail_icon_cb){
     if (e == LV_EVENT_CLICKED) {
       // detail_ecg();
			  printf("Detail ecg \r\n");
    }
 
}



