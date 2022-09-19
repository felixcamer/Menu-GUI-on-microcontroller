#ifndef __DISPLAY_WAVES_H
#define __DISPLAY_WAVES_H	 
#include "lcd.h"
#include "lvgl.h"

extern  volatile u8  start_wave;
u8 LeadChecker();

void Creat_MyWave(void);
void ReWave_cb(lv_task_t* task);
void ReWave_task_etr(void);
void ecg_realtime_disp_task_etr(void);   
void disp_float(u16 x,u16 y,float num,u8 size);

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*REFLOW_OVEN_UI_H*/


