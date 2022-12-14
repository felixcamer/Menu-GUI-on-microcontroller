#ifndef __MY_GUI_SETTINGS_H
#define __MY_GUI_SETTINGS_H	 

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stdlib.h>	
	
typedef struct{
    uint8_t major_version;
    uint8_t minor_version;
    uint8_t patch_version;
    uint8_t display_brightness;
    uint8_t speaker_volume;
    float pid_p_presoak;
    float pid_i_presoak;
    float pid_d_presoak;
    float pid_p_soak;
    float pid_i_soak;
    float pid_d_soak;
    float pid_p_reflow;
    float pid_i_reflow;
    float pid_d_reflow;
    uint8_t current_reflow_profile;
}my_gui_settings_t;

#define REFLOW_OVEN_FIRMWARE_MAJOR_VERSION 1
#define REFLOW_OVEN_FIRMWARE_MINOR_VERSION 1
#define REFLOW_OVEN_FIRMWARE_PATCH_VERSION 0

extern my_gui_settings_t my_gui_setting;

void settings_setup();
void settings_load();
void settings_save();
void settings_reset();
char* settings_dump();


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*REFLOW_OVEN_UI_H*/


