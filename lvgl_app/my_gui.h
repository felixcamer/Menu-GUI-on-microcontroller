#ifndef __MY_GUI_H
#define __MY_GUI_H	 



#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"



/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef enum {
    MY_GUI_HEATER_STATUS_ACTIVE,
    MY_GUI_HEATER_STATUS_INACTIVE,
    MY_GUI_HEATER_STATUS_DISABLED
}my_gui_heater_status_type_t;




typedef enum {
	  MY_GUI_BATTERY_LEVEL_FULL,
    MY_GUI_BATTERY_LEVEL_1,
    MY_GUI_BATTERY_LEVEL_2,
    MY_GUI_BATTERY_LEVEL_3,
		MY_GUI_BATTERY_LEVEL_4,
	  MY_GUI_BATTERY_LEVEL_EMPTY
}my_gui_battery_status_type_t;



typedef enum {
    MY_GUI_DOOR_STATUS_UNLOCKED,
    MY_GUI_DOOR_STATUS_LOCKED
}my_gui_door_status_type_t;
/**********************
 * GLOBAL PROTOTYPES
 **********************/
void my_gui(void);
void display_heater_status(my_gui_heater_status_type_t state);
void display_door_status(my_gui_door_status_type_t state);

void my_gui_complete();
void my_gui_focus_door_icon();
void my_gui_error_popup(char* msg, uint8_t error_code_val);
void my_gui_update_temperature(char* temp);
void my_gui_anim_out(lv_obj_t * obj, uint32_t delay);
void my_gui_back_home();
//void home_open(uint32_t delay);
/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*REFLOW_OVEN_UI_H*/


