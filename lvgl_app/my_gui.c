/**
 * @file reflow_oven_ui.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
 
#include "my_gui.h"
#include "lvgl.h"
#include "my_gui_settings.h"
#include "lv_settings.h"
#include "display_waves.h"
#include "my_gui_theme.h"


/*********************
 *      DEFINES
 *********************/

/*Bg positions*/
#define MY_GUI_BG_NONE (-LV_VER_RES)
#define MY_GUI_BG_FULL 0
#define MY_GUI_BG_NORMAL (-2 * (LV_VER_RES / 3))
#define MY_GUI_BG_SMALL (-5 * (LV_VER_RES / 6))

/*Sizes*/
#define MY_GUI_BTN_H   (240)
#define MY_GUI_BTN_W   (320)

/*Animations*/
#define MY_GUI_ANIM_Y (LV_VER_RES / 20)
#define MY_GUI_ANIM_DELAY (40)
#define MY_GUI_ANIM_TIME  (150)
#define MY_GUI_ANIM_TIME_BG  (300)

/*Padding*/
#define MY_GUI_TITLE_PAD 10

#define DEBUG_UI


/**********************
 *      TYPEDEFS
 **********************/
 
typedef enum {
    DISPLAY_AND_SOUND_DISPLAY_BRIGHTNESS = 0,
    DISPLAY_AND_SOUND_SPEAKER_VOLUME,
    MOTOR_ITEM_TYPE,
    MOTOR_ITEM_PROTECT,
    MOTOR_ITEM_PROTECT2,
}motor_item_t;


typedef struct
{
	lv_obj_t *scr;                			//Load the object of the currently active screen
	lv_obj_t * bg_circle;         			//Big circle on the screen
  lv_group_t * g;               			//group of the icons
  lv_obj_t * battery_state_icon;      //battery state icon
	lv_obj_t * box;                     //box to content the icons
	lv_obj_t *popup;                    //for sub windows displaying
	lv_obj_t *toolbar;                  //hold the date 
	lv_obj_t* list_btn;                 //list button
}My_obj;                              //Object set

typedef struct 
{
   char* percent_str_disp;             // display the percentage of the battery
	 char* time_str_disp;                //time string to display
	 char* icons_str[5]  ;               //icons array
	 lv_obj_t * battery_obj_lab;         //show the battery level
	 lv_obj_t * time_date_lab;           //time label

} My_labels;

typedef struct
{
	lv_style_t time_style_label;

}My_styles;

void lv_ex_settings_2(lv_obj_t * parent);

//AN ICON HAS TWO COMPONENTS
typedef struct{
     lv_obj_t * cont;
     lv_obj_t * obj;
}icon_t;


typedef struct{

   lv_task_t *my_task_1;

}My_tasks;

	
 

//HOME ICONS, IT HAS FOUR BY THE TIME
typedef struct{
     icon_t * icon1;
     icon_t * icon2;
     icon_t * icon3;
     icon_t * icon4;
}home_icon_t;

home_icon_t home_icon;



/**********************
 *  STATIC PROTOTYPES
 **********************/

 //THE FUNCTION OF MY HOME SCREEN
static void home_open(uint32_t delay);
static void add_home_icon_group();
static void ecg_recorder();
static void toggle_door();
static void open_settings();
static void setting_app(lv_obj_t* parent);
//static void open_profiles();


//EVENT DECLARATION
LV_EVENT_CB_DECLARE(back_to_home_event_cb);
LV_EVENT_CB_DECLARE(ecg_recorder_icon_event_cb);
LV_EVENT_CB_DECLARE(toggle_door_icon_event_cb);
LV_EVENT_CB_DECLARE(open_settings_icon_event_cb);


static icon_t * add_icon(lv_obj_t * parent, const void * src);
static void add_label_(const char * txt, lv_obj_t * src, lv_obj_t * cont);
static lv_obj_t * add_title(const char * txt, lv_obj_t * src, my_gui_theme_t theme);
static lv_obj_t * add_back(lv_event_cb_t event_cb);
static lv_obj_t * add_loader(void (*end_cb)(lv_anim_t *));
static void loader_anim_cb(void * arc, lv_anim_value_t v);
void display_battery_status(my_gui_battery_status_type_t level);
static void display_date_time();

  //for my ecg displaying 


static void my_gui_anim_bg(uint32_t delay, lv_color_t color, int32_t y_new);
static void my_gui_anim_out(lv_obj_t * obj, uint32_t delay);
static void my_gui_anim_out_all(lv_obj_t * obj, uint32_t delay);
static void my_gui_anim_in(lv_obj_t * obj, uint32_t delay);

/**********************
 *  STATIC VARIABLES
 **********************/
static bool error_state = false;
//static lv_group_t * g;
//static lv_obj_t * bg_circle;
static lv_obj_t * bg_left_status_icons;
static lv_obj_t * bg_right_status_icons;
static lv_obj_t * bg_shade;
//static lv_obj_t * popup;
static lv_obj_t * abort_title;
static lv_obj_t * abort_btn;
static lv_obj_t * no_btn;
static lv_obj_t * reflow_bottom_btn;
static lv_obj_t * heater_state_icon;
static lv_obj_t * door_state_icon;
static lv_obj_t * temp_state_icon;
static lv_obj_t * temp_state_symbol;
static lv_obj_t * battery_percent_bg;    //to display the label and the battery icon
//static lv_obj_t * battery_state_icon;
static lv_style_t  battery_style_label;
static lv_obj_t*  time_date;
//static lv_style_t time_style_label;

/**************************
*   STRUCTURE DECLARATIONS
**************************/

My_obj my_objs_1;
My_labels my_labels_1;
My_styles my_styles_1;
My_tasks my_task_1;



/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void my_gui(void)
{
	



		//DECLARATION OF THE THEM
   /*lv_theme_t * th = my_gui_theme_init(LV_COLOR_BLACK, LV_COLOR_BLACK,
            0, &lv_font_montserrat_10, &lv_font_montserrat_12,
            &lv_font_montserrat_14, &lv_font_montserrat_16);
    lv_theme_set_act(th);*/


    /*CREATE A SCREEN, SET THE STYLE , AND LOAD THE SCREEN*/
	  static lv_style_t style_bg;
	  lv_style_init(&style_bg);
    lv_style_set_bg_opa(&style_bg, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_bg, LV_STATE_DEFAULT, MY_GUI_BLUE);  //BLACK
	  lv_style_set_border_side(&style_bg,LV_STATE_DEFAULT,0);
   
	
 
	
    my_objs_1.scr = lv_obj_create(NULL, NULL);
		lv_obj_add_style(my_objs_1.scr , LV_OBJ_PART_MAIN, &style_bg);
    lv_scr_load(my_objs_1.scr);
	
   
	   /*Declare the big circle  on the screen here */
	  /*my_objs_1.bg_circle = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_clean_style_list(my_objs_1.bg_circle, LV_OBJ_PART_MAIN);
    lv_obj_set_style_local_bg_opa(my_objs_1.bg_circle, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_obj_set_style_local_bg_color(my_objs_1.bg_circle, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x2c3e40));
    lv_obj_set_style_local_radius(my_objs_1.bg_circle, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_VER_RES/2);
    lv_obj_set_size(my_objs_1.bg_circle, LV_HOR_RES, LV_VER_RES);*/
	

		//THE BG RIGHT STATUS ICON DECLARATION
    /*bg_right_status_icons = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_set_size(bg_right_status_icons, 40, 15);
    lv_obj_set_style_local_bg_opa(bg_right_status_icons, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_10);
    lv_obj_align(bg_right_status_icons, NULL, LV_ALIGN_IN_TOP_RIGHT, 0, 0);*/

    /*Display the battery and change the level, sow the time  */
    display_battery_status(MY_GUI_BATTERY_LEVEL_3);
		display_date_time();   



    my_objs_1.g = lv_group_create();
    home_open(0);
}


//ACTIVATE A DESACTIVATE THE HEATER STATUS ICON CONTROL HERE
void display_battery_status(my_gui_battery_status_type_t level){
	 
	
	
	  /*update the percentage of the battery*/
	  my_labels_1.percent_str_disp = "75%" ;  
    my_objs_1.battery_state_icon = lv_img_create(lv_scr_act(), NULL);
	
	/*style declaration*/
	   lv_style_init(&battery_style_label);
     lv_style_set_text_color(&battery_style_label, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	 
	/* percentage number display label  , eig 75%*/
		 my_labels_1.battery_obj_lab = lv_label_create(lv_scr_act(), NULL);
     lv_label_set_text(my_labels_1.battery_obj_lab, my_labels_1.percent_str_disp);
		 lv_obj_add_style(my_labels_1.battery_obj_lab,LV_LABEL_PART_MAIN,	&battery_style_label);
     lv_obj_align(my_labels_1.battery_obj_lab, NULL, LV_ALIGN_IN_TOP_RIGHT, -35,5);
	
    if(level == MY_GUI_BATTERY_LEVEL_FULL){
        
        LV_IMG_DECLARE(battery_full_icon);
        lv_img_set_src(my_objs_1.battery_state_icon, &battery_full_icon);
        lv_obj_align(my_objs_1.battery_state_icon, NULL, LV_ALIGN_IN_TOP_RIGHT, -5, 5);
    }else if(level == MY_GUI_BATTERY_LEVEL_1){
			
        LV_IMG_DECLARE(battery_level1_icon);
        lv_img_set_src(my_objs_1.battery_state_icon, &battery_level1_icon);
        lv_obj_align(my_objs_1.battery_state_icon, NULL, LV_ALIGN_IN_TOP_RIGHT, -5, 5);
			
    }else if(level == MY_GUI_BATTERY_LEVEL_2){
			
        LV_IMG_DECLARE(battery_level2_icon);
        lv_img_set_src(my_objs_1.battery_state_icon, &battery_level2_icon);
        lv_obj_align(my_objs_1.battery_state_icon, NULL, LV_ALIGN_IN_TOP_RIGHT, -5, 5);
			
    }else if(level == MY_GUI_BATTERY_LEVEL_3){
			
        LV_IMG_DECLARE(battery_level3_icon);
        lv_img_set_src(my_objs_1.battery_state_icon, &battery_level3_icon);
        lv_obj_align(my_objs_1.battery_state_icon, NULL, LV_ALIGN_IN_TOP_RIGHT, -5, 5);
			
    }else if(level == MY_GUI_BATTERY_LEVEL_4){
			
        LV_IMG_DECLARE(battery_level4_icon);
        lv_img_set_src(my_objs_1.battery_state_icon, &battery_level4_icon);
        lv_obj_align(my_objs_1.battery_state_icon, NULL, LV_ALIGN_IN_TOP_RIGHT, -5, 0);
    }else if(level == MY_GUI_BATTERY_LEVEL_EMPTY){
			
        LV_IMG_DECLARE(battery_empty_icon);
        lv_img_set_src(my_objs_1.battery_state_icon, &battery_empty_icon);
        lv_obj_align(my_objs_1.battery_state_icon, NULL, LV_ALIGN_IN_TOP_RIGHT, -5, 0);
    }
}


//DISPLAY CHARGING BATTERY FUNCTION HERE.  THE FUNCTION WILL BE WRITTEN HERE 
//*************************************************************************//
static void display_date_time(){

	  /*update the percentage of the battery*/
	  my_labels_1.time_str_disp = "22:32" ;  //DECLARATION OF ICONS
    /*Create the label object*/
	  my_labels_1.time_date_lab = lv_label_create(lv_scr_act(), NULL);
	  lv_label_set_text(my_labels_1.time_date_lab, my_labels_1.time_str_disp);
	
	   /*Create the style of the label*/
	  lv_style_init(&my_styles_1.time_style_label);
    lv_style_set_text_color(&my_styles_1.time_style_label, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	  lv_obj_add_style(my_labels_1.time_date_lab,LV_LABEL_PART_MAIN,	&my_styles_1.time_style_label);
    lv_obj_align(my_labels_1.time_date_lab, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 5);

}
/**********************
 *   STATIC FUNCTIONS
 **********************/
 void home_open(uint32_t delay) {
	 
	  static lv_style_t style_box;
	  lv_style_init(&style_box);
    lv_style_set_bg_opa(&style_box, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_border_color(&style_box, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	  lv_style_set_border_side(&style_box,LV_STATE_DEFAULT,0);
	  lv_style_set_bg_color(&style_box, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    
	 
   
    /* Initialize each group with appropriate objects */
    lv_coord_t box_w = 215;                         //set the size of the screen
    my_objs_1.box = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_set_style_local_bg_opa(my_objs_1.box, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP);
    lv_obj_set_size(my_objs_1.box, box_w, box_w);
    lv_obj_align(my_objs_1.box, NULL, LV_ALIGN_CENTER, 0, 0);
	  lv_obj_add_style(my_objs_1.box, LV_OBJ_PART_MAIN, &style_box);
	 
	 

	  /*Declaration of images*/
    LV_IMG_DECLARE(ecg_recorder_icon);
    LV_IMG_DECLARE(pulse_oximeter_icon);
    LV_IMG_DECLARE(settings_icon);
    LV_IMG_DECLARE(data_review_icon);
	
	
		//*****************************************

    if(home_icon.icon1!=NULL){
        lv_mem_free(home_icon.icon1);
        lv_mem_free(home_icon.icon2);
        lv_mem_free(home_icon.icon3);
        lv_mem_free(home_icon.icon4);
    }
	  home_icon.icon1 = add_icon(my_objs_1.box, &ecg_recorder_icon);
    lv_obj_align_origo(home_icon.icon1->cont, NULL, LV_ALIGN_IN_LEFT_MID, (box_w - 64*2)/3 + 64/2, -45);
		lv_obj_set_style_local_border_side(home_icon.icon1->cont,LV_STATE_DEFAULT,0,0);  //REMOVE THEN OUTLINE 
    lv_obj_set_event_cb(home_icon.icon1->obj, ecg_recorder_icon_event_cb);
	 

    home_icon.icon2 = add_icon(my_objs_1.box, &pulse_oximeter_icon);
    lv_obj_align_origo(home_icon.icon2->cont, NULL, LV_ALIGN_IN_LEFT_MID, (box_w - 64*2)/3*2 + 64/2 + 64 + 10, -45);
    lv_obj_set_event_cb(home_icon.icon2->obj, toggle_door_icon_event_cb);
		lv_obj_set_style_local_border_side(home_icon.icon2->cont,LV_STATE_DEFAULT,0,0);
		

    home_icon.icon3 = add_icon(my_objs_1.box, &data_review_icon);
    lv_obj_align_origo(home_icon.icon3->cont, NULL, LV_ALIGN_IN_LEFT_MID, (box_w - 64*2)/3*2 + 64/2 + 64 + 10, 45);
    //lv_obj_set_event_cb(home_icon.icon3->obj, open_profiles_icon_event_cb);
		lv_obj_set_style_local_border_side(home_icon.icon3->cont,LV_STATE_DEFAULT,0,0);
		

    home_icon.icon4 = add_icon(my_objs_1.box, &settings_icon);
    lv_obj_align_origo(home_icon.icon4->cont, NULL, LV_ALIGN_IN_LEFT_MID, (box_w - 64*2)/3 + 64/2, 45);
    lv_obj_set_event_cb(home_icon.icon4->obj, open_settings_icon_event_cb);
		lv_obj_set_style_local_border_side(home_icon.icon4->cont,LV_STATE_DEFAULT,0,0);
		
	
		add_home_icon_group();
    lv_group_focus_obj(home_icon.icon1->obj);
    lv_group_set_wrap(my_objs_1.g, true);

    delay += MY_GUI_ANIM_DELAY;
    my_gui_anim_in(my_objs_1.box, delay);	
}


//ADD ALL THE ICONS IN THE GROUP
static void add_home_icon_group(){
	
	  
    lv_group_add_obj(my_objs_1.g, home_icon.icon1->obj);
    lv_group_add_obj(my_objs_1.g, home_icon.icon2->obj);
    lv_group_add_obj(my_objs_1.g, home_icon.icon3->obj);
    lv_group_add_obj(my_objs_1.g, home_icon.icon4->obj);
	
	
	  /*set the icons labels*/
	  my_labels_1.icons_str[0] = "ECG Recorder";
	  my_labels_1.icons_str[1] = "Pulse Oximeter";
	  my_labels_1.icons_str[2] = "Data Review";
	  my_labels_1.icons_str[3] = "Settings";
	
	  add_label_(my_labels_1.icons_str[0], lv_scr_act(), home_icon.icon1->obj);
	  add_label_(my_labels_1.icons_str[1], lv_scr_act(), home_icon.icon2->obj);
	  add_label_(my_labels_1.icons_str[2], lv_scr_act(), home_icon.icon3->obj);
	  add_label_(my_labels_1.icons_str[3], lv_scr_act(), home_icon.icon4->obj);
}


//THIS FUNCTION IS USED TO ADD THE ICONS IN THE SCREEN 

// PARAMETERS : PARENT , IMAGE ADDRESS, LABEL ADDRESS AND THE COLOR
//NOTE THAT THE COLOR IS NOT CONNECTED 

static icon_t * add_icon(lv_obj_t * parent, const void * src) {
    
	  icon_t * icon_struct = lv_mem_alloc(sizeof(icon_t));
	  lv_obj_t * cont = lv_cont_create(parent, NULL);
    lv_obj_set_style_local_bg_opa(cont, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP);
    lv_cont_set_fit(cont, LV_FIT_TIGHT);
    lv_obj_set_style_local_pad_right(cont, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, 20);
    lv_obj_set_style_local_pad_left(cont, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, 10);
    lv_obj_set_style_local_pad_top(cont, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, 5);
    lv_obj_set_style_local_pad_bottom(cont, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, 5);

    lv_obj_t * img_icon = lv_img_create(cont, NULL);
	  lv_theme_apply(img_icon, MY_GUI_THEME_ICON);
    lv_img_set_src(img_icon, src);
    lv_obj_set_click(img_icon, true);
		
 
    icon_struct->cont = cont;
    icon_struct->obj = img_icon;
    return icon_struct;
}

//THIS FUNCTIONN ADD THE TITLE IN A PARTICULAR SCREEN
//PARAM: TEXT ADD, THE SCREEN AND THE THEME
static lv_obj_t * add_title(const char * txt, lv_obj_t * src,my_gui_theme_t theme)
{
    lv_obj_t * title = lv_label_create(src, NULL);
    lv_theme_apply(title, theme);
    lv_label_set_text(title, txt);
    lv_obj_align(title, NULL, LV_ALIGN_IN_TOP_MID, 0,MY_GUI_TITLE_PAD);
    return title;
}


/*Add the label on the icons*/
static void add_label_(const char * txt, lv_obj_t * src, lv_obj_t * cont)
{
  
	lv_obj_t * subs = lv_label_create(src, NULL);
	static lv_style_t sty;
	lv_style_init(&sty);
	lv_style_set_text_font(&sty, LV_STATE_DEFAULT,&lv_font_montserrat_12);
	lv_style_set_text_color(&sty, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	lv_obj_add_style(subs,LV_LABEL_PART_MAIN,	&sty);
  lv_label_set_text(subs, txt);
  lv_obj_align(subs, cont, LV_ALIGN_IN_BOTTOM_MID, 0,20);
	
}

//ANIMATION FUNCTION HERE 
static void my_gui_anim_in(lv_obj_t * obj, uint32_t delay)
{
    if (obj != lv_scr_act()) {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, obj);
        lv_anim_set_time(&a, MY_GUI_ANIM_TIME);
        lv_anim_set_delay(&a, delay);
        lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);
        lv_anim_set_values(&a, lv_obj_get_y(obj) - MY_GUI_ANIM_Y,lv_obj_get_y(obj));
        lv_anim_start(&a);
        lv_obj_fade_in(obj, MY_GUI_ANIM_TIME -10 , delay);
    }
}


//DECLARATION OF FUNCTIONS AFTER EVENT HAS HAPPENED 


//THIS FUNCTION IS CALLED WHEN THE START ICON IS PRESSED
static void ecg_recorder(){

    my_objs_1.popup = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_set_style_local_bg_color(my_objs_1.popup, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
		lv_obj_set_style_local_border_side(my_objs_1.popup,LV_STATE_DEFAULT,0,0);
    lv_obj_set_size(my_objs_1.popup, 320, 240);
    lv_obj_align(my_objs_1.popup, NULL, LV_ALIGN_CENTER, 0, 0);

	/*Call the main function for realtime ecg recording and displaying */

		Creat_MyWave();               
	
}       


//THIS FUNCTION IS CALLED WHEN THE SECOND ICON IS PRESSED
static void toggle_door(){
    uint32_t delay = 200;

    lv_obj_t * bg_shade = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_set_style_local_bg_opa(bg_shade, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_30);
    lv_obj_set_style_local_bg_color(bg_shade, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_obj_set_style_local_radius(bg_shade, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_VER_RES/2);
    lv_obj_set_size(bg_shade, LV_HOR_RES, LV_VER_RES);

    lv_obj_t * popup = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_set_style_local_bg_color(popup, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_obj_set_size(popup, 200, 70);
    lv_obj_align(popup, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t * title = add_title("Wait Still...", popup, MY_GUI_THEME_TITLE);


    lv_obj_t * bar1 = lv_bar_create(popup, NULL);
    lv_obj_set_size(bar1, 180, 15);
    lv_obj_align(bar1, NULL, LV_ALIGN_CENTER, 0, 10);
    lv_theme_apply(bar1, LV_THEME_BAR);
    lv_bar_set_anim_time(bar1, 3000);
    lv_bar_set_value(bar1, 100, LV_ANIM_ON);

    lv_group_remove_all_objs(my_objs_1.g);


    my_gui_anim_in(popup, delay);
    my_gui_anim_out(bg_shade, 2200);
    my_gui_anim_out(popup, 2200);
}



void my_gui_focus_door_icon(){
    lv_group_remove_all_objs(my_objs_1.g);
    add_home_icon_group();
}


//THIS FUNCTION IS CALLED WHEN THE SETTING ICON IS PRESSED
static void open_settings(){
    
	
   my_gui_anim_out_all(lv_scr_act(), 0);
	  
	 
	
    lv_obj_t* parent = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_set_size(parent, 320, 240);
	 // lv_obj_set_style_local_bg_color( parent, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	 // lv_obj_set_style_local_text_font( parent, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_20);
	
	
	  

    lv_group_remove_all_objs(my_objs_1.g);
	/*Call the setting app*/
    setting_app(parent);
	 
}


/********************************************************
           Setting function  part
********************************************************/
static void handle_event(lv_obj_t * obj, lv_event_t event){
		

    if(event == LV_EVENT_CLICKED) {
       // printf("Clicked: %s\n", lv_list_get_btn_text(obj));
			
			
			   if(strcmp (lv_list_get_btn_text(obj), "Bluetooth")==0){
					 
					 //printf("Buethoot\n");
					 //bluethoot(CURRENT_SCREEN);
					//bluethoot_event( obj, event);
				 
				 }
				 
			   if(strcmp (lv_list_get_btn_text(obj), "To Pc")==0){ printf("To Pc\n");}
				 if(strcmp (lv_list_get_btn_text(obj), "ECG lenght")==0){printf("ECG lenght\n");}
				 //if(strcmp (lv_list_get_btn_text(obj), "User Mode")==0){printf("User Mode\n");}
				 if(strcmp (lv_list_get_btn_text(obj), "Brightness")==0){printf("Brightness\n");}
				 if(strcmp (lv_list_get_btn_text(obj), "Voice")==0){printf("Voice\n");}
				 if(strcmp (lv_list_get_btn_text(obj), "Date & Time")==0){printf("Date & Time\n");}
				 if(strcmp (lv_list_get_btn_text(obj), "Erase All Data")==0){printf("Erase All Data\n");}
				 if(strcmp (lv_list_get_btn_text(obj), "Factory Reset")==0){printf("Factory Reset\n");}
				 if(strcmp (lv_list_get_btn_text(obj), "Software Update")==0){printf("Software Update\n");}
				 if(strcmp (lv_list_get_btn_text(obj), "About")==0){printf("About\n");}
    }

	}


//CREATE MY LIST
 static void setting_app(lv_obj_t* parent){
   
	
	 lv_obj_t * list1 = lv_list_create(lv_scr_act(), NULL);
	
   lv_obj_set_size(list1, 320, 240);
   lv_obj_align(list1, NULL, LV_ALIGN_CENTER, 0, 0);
   lv_obj_t* list_btn;
	
    LV_IMG_DECLARE(bluethoot_set);
    LV_IMG_DECLARE(topc_set);
    LV_IMG_DECLARE(ecglenght_set);
    LV_IMG_DECLARE(brightness_set);
	  LV_IMG_DECLARE(voice_set);
    LV_IMG_DECLARE(datetime_set);
    LV_IMG_DECLARE(erase_set);
    LV_IMG_DECLARE(factoryreset_set);
	  LV_IMG_DECLARE(softwareupdate_set);
    LV_IMG_DECLARE(about_set);
    
	
    /*Add buttons to the list*/
    lv_list_set_anim_time(list1, 10);     //set animation in ms
    lv_list_set_edge_flash(list1, false);
    list_btn = lv_list_add_btn(list1, &bluethoot_set, "Bluetooth");
    lv_obj_set_event_cb(list_btn, &handle_event);
    list_btn = lv_list_add_btn(list1, &topc_set, "To Pc");
    lv_obj_set_event_cb(list_btn, &handle_event);
    list_btn = lv_list_add_btn(list1, &ecglenght_set, "ECG Lenght");
    lv_obj_set_event_cb(list_btn, &handle_event);
    //list_btn = lv_list_add_btn(list1, &pulse_oximeter_icon, "User Mode");
    //lv_obj_set_event_cb(list_btn, &handle_event);
    list_btn = lv_list_add_btn(list1, &brightness_set, "Brightness");
    lv_obj_set_event_cb(list_btn, &handle_event);
    list_btn = lv_list_add_btn(list1, &voice_set, "Voice");
    lv_obj_set_event_cb(list_btn, &handle_event);
    list_btn = lv_list_add_btn(list1, &datetime_set, "Date & Time");
    lv_obj_set_event_cb(list_btn, &handle_event);
    list_btn = lv_list_add_btn(list1, &erase_set, "Erase All Data");
    lv_obj_set_event_cb(list_btn, &handle_event);
    list_btn = lv_list_add_btn(list1, &factoryreset_set, "Factory Reset");
    lv_obj_set_event_cb(list_btn, &handle_event);
    list_btn = lv_list_add_btn(list1, &softwareupdate_set, "Software Update");
    lv_obj_set_event_cb(list_btn, &handle_event);
    list_btn = lv_list_add_btn(list1, &about_set, "About");
    lv_obj_set_event_cb(list_btn, &handle_event);
}
/***************************end**************************************************/

//DECLARATION OF EVENTS HERE 
LV_EVENT_CB_DECLARE(ecg_recorder_icon_event_cb){
     if (e == LV_EVENT_CLICKED) {
        ecg_recorder();
    }
 
}

LV_EVENT_CB_DECLARE(open_profiles_icon_event_cb) {
    if (e == LV_EVENT_CLICKED) {
        //open_profiles();
    }
}



void my_gui_back_home(){
	
	
	      my_gui_anim_out_all(lv_scr_act(), 0);
        home_open(200);//200
		  	//Recall the time function
			  display_date_time();
			//Recall the battery function
			display_battery_status(MY_GUI_BATTERY_LEVEL_3);
    }


LV_EVENT_CB_DECLARE(back_to_home_event_cb)
{
    if (e == LV_EVENT_CLICKED) {
        my_gui_anim_out_all(lv_scr_act(), 0);

        home_open(0);//200
			
			//Recall the time function
			display_date_time();
			//Recall the battery function
			display_battery_status(MY_GUI_BATTERY_LEVEL_3);

        uint32_t icon_selected = (uint32_t)lv_obj_get_user_data(obj);

        if(icon_selected>0){
            //workaround
            lv_style_int_t trans_delay = lv_obj_get_style_transition_delay(home_icon.icon2->obj, LV_OBJ_PART_MAIN);
            lv_obj_set_style_local_transition_delay(home_icon.icon1->obj, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
            //
            if(icon_selected==1){
                lv_group_focus_obj(home_icon.icon2->obj);
            }else if(icon_selected==2){
                lv_group_focus_obj(home_icon.icon3->obj);
               // settings_save();   //SHOULD ADD THE SAVE FUNCTION LATER 
            }else if(icon_selected==3){
                lv_group_focus_obj(home_icon.icon4->obj);
                //settings_save();   //SHOULD ADD THE SAVE FUNCTION LATER 
            }
            //workaround
            lv_obj_set_style_local_transition_delay(home_icon.icon1->obj, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, trans_delay);
        }
    }
}


LV_EVENT_CB_DECLARE(abort_reflow_event_cb){
     
	if (e == LV_EVENT_CLICKED) {
        
		    
		my_gui_anim_in(my_objs_1.popup, 100);
    my_gui_anim_out(bg_shade, 100);
    my_gui_anim_out(my_objs_1.popup, 100);
    my_gui_focus_door_icon();
			
				 
     }
}

LV_EVENT_CB_DECLARE(no_abort_event_cb){
	
    if (e == LV_EVENT_CLICKED)  {
    my_gui_anim_out(bg_shade, 0);
    my_gui_anim_out(my_objs_1.popup, 0);
    my_gui_anim_out(abort_title, 0);
    my_gui_anim_out(abort_btn, 0);
    my_gui_anim_out(no_btn, 0);

    lv_group_add_obj(my_objs_1.g, reflow_bottom_btn);
    lv_group_focus_obj(reflow_bottom_btn);
    }
}

LV_EVENT_CB_DECLARE(toggle_door_icon_event_cb) {
    if (e == LV_EVENT_CLICKED) {
        toggle_door();
    }
    //icon_generic_event_cb(obj, e);
}

LV_EVENT_CB_DECLARE(open_settings_icon_event_cb) {
    if (e == LV_EVENT_CLICKED) {
        open_settings();
    }
   // icon_generic_event_cb(obj, e);
}
//ANIMATIONS HERE 

static void my_gui_anim_out(lv_obj_t * obj, uint32_t delay) {
    lv_obj_t * child = lv_obj_get_child_back(obj, NULL);
    while(child) {
        if(child != my_objs_1.battery_state_icon && child != my_labels_1.battery_obj_lab &&  child != lv_scr_act() && child != my_labels_1.time_date_lab) {
            lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_var(&a, child);
            lv_anim_set_time(&a, MY_GUI_ANIM_TIME);
            lv_anim_set_delay(&a, delay);
            lv_anim_set_ready_cb(&a, lv_obj_del_anim_ready_cb);
            lv_anim_start(&a);

            lv_obj_fade_out(child, MY_GUI_ANIM_TIME - 70, delay + 70);
        }
        child = lv_obj_get_child_back(obj, child);
    }

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, obj);
    lv_anim_set_time(&a, MY_GUI_ANIM_TIME);
    lv_anim_set_delay(&a, delay);
    lv_anim_set_ready_cb(&a, lv_obj_del_anim_ready_cb);
    lv_anim_start(&a);
    lv_obj_fade_out(obj, MY_GUI_ANIM_TIME - 70, delay + 70);
}

static void my_gui_anim_out_all(lv_obj_t * obj, uint32_t delay) {
	
	
    lv_obj_t * child = lv_obj_get_child_back(obj, NULL);
    while(child) {
         if(child != my_objs_1.battery_state_icon && child != my_labels_1.battery_obj_lab &&  child != lv_scr_act() && child != my_labels_1.time_date_lab) {
            lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_var(&a, child);
            lv_anim_set_time(&a, MY_GUI_ANIM_TIME);
            lv_anim_set_delay(&a, delay);

            lv_anim_set_ready_cb(&a, lv_obj_del_anim_ready_cb);
            lv_anim_start(&a);

            lv_obj_fade_out(child, MY_GUI_ANIM_TIME-70, delay+70 );
        }
        child = lv_obj_get_child_back(obj, child);
    }
}