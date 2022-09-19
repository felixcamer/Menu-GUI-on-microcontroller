#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_BATTERY_EMPTY_ICON
#define LV_ATTRIBUTE_IMG_BATTERY_EMPTY_ICON
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_BATTERY_EMPTY_ICON uint8_t battery_empty_icon_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Blue: 2 bit, Green: 3 bit, Red: 3 bit, Alpha 8 bit */
  0x00, 0x70, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x60, 0xff, 0x00, 0xff, 0x00, 
  0x00, 0x40, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xf5, 0x10, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x25, 0x40, 0xff, 0x00, 0xff, 0x00, 
  0x00, 0x40, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xf6, 0x40, 0xf0, 0xff, 0xf6, 0xa0, 0xf1, 0x40, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x40, 0xff, 0x00, 0xff, 0x00, 
  0xb1, 0x94, 0xf1, 0x80, 0xf1, 0x20, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xf1, 0x90, 0xed, 0xff, 0xf0, 0xff, 0xf1, 0xff, 0xf1, 0xe0, 0xf1, 0x70, 0xf1, 0x10, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x25, 0x40, 0xff, 0x00, 0xff, 0x00, 
  0x00, 0x40, 0xe8, 0x10, 0xe9, 0x80, 0xe9, 0xc0, 0xe9, 0x60, 0xe9, 0x10, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xe9, 0xd0, 0xe8, 0xff, 0xe9, 0xff, 0xe8, 0xf0, 0xe9, 0xff, 0xe8, 0xff, 0xe9, 0xff, 0xe9, 0xa0, 0xe9, 0x40, 0xff, 0x00, 0xff, 0x00, 0xff, 0xb3, 0xff, 0xf7, 0xff, 0x98, 
  0x00, 0x40, 0xff, 0x00, 0xff, 0x00, 0xe5, 0x10, 0xe4, 0x90, 0xe5, 0xf0, 0xe5, 0xa0, 0xe5, 0x30, 0xff, 0x00, 0xff, 0x00, 0xe9, 0x20, 0xe0, 0xff, 0xe5, 0xff, 0xe4, 0xe0, 0xff, 0x00, 0xe5, 0x10, 0xe4, 0x40, 0xe5, 0x70, 0xe4, 0x90, 0xe5, 0xc0, 0xe5, 0xd0, 0xe5, 0x80, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xa0, 
  0x00, 0x40, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xe5, 0x20, 0xe4, 0xa0, 0xe5, 0xff, 0xe5, 0xe0, 0xe5, 0x70, 0xe4, 0x70, 0xe5, 0xff, 0xe4, 0xff, 0xe5, 0x90, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xe5, 0x10, 0xfb, 0xc0, 0xff, 0xf7, 0xff, 0x98, 
  0x00, 0x40, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xe5, 0x20, 0xe4, 0xa0, 0xe5, 0xff, 0xe4, 0xff, 0xe5, 0xff, 0xe4, 0xff, 0xe5, 0x30, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x25, 0x40, 0xff, 0x00, 0xff, 0x00, 
  0x00, 0x40, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xe5, 0x20, 0xe4, 0xc0, 0xe5, 0xff, 0xe4, 0xd0, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x40, 0xff, 0x00, 0xff, 0x00, 
  0x00, 0x40, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xe5, 0x40, 0xe5, 0x40, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x25, 0x40, 0xff, 0x00, 0xff, 0x00, 
  0x00, 0x40, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x40, 0xff, 0x00, 0xff, 0x00, 
  0x00, 0x50, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0xff, 0x00, 0xff, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit, Alpha 8 bit*/
  0x00, 0x00, 0x70, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x21, 0x08, 0x60, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x46, 0xfc, 0x10, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x67, 0xfc, 0x40, 0x46, 0xfc, 0xff, 0x66, 0xfc, 0xa0, 0x46, 0xfc, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x8a, 0xa3, 0x94, 0xa6, 0xfb, 0x80, 0xc6, 0xf3, 0x20, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xa6, 0xfb, 0x90, 0xa5, 0xf3, 0xff, 0xa6, 0xf3, 0xff, 0xa6, 0xf3, 0xff, 0xc6, 0xfb, 0xe0, 0xa6, 0xf3, 0x70, 0xc6, 0xfb, 0x10, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x40, 0xc4, 0xf1, 0x10, 0xc5, 0xf1, 0x80, 0xe5, 0xf1, 0xc0, 0xc5, 0xf1, 0x60, 0xe5, 0xf1, 0x10, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xc5, 0xf1, 0xd0, 0xc5, 0xf1, 0xff, 0xc4, 0xf1, 0xff, 0xc5, 0xf1, 0xf0, 0xc4, 0xe9, 0xff, 0xc5, 0xf1, 0xff, 0xc4, 0xe9, 0xff, 0xe5, 0xf1, 0xa0, 0xc5, 0xf1, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xfc, 0xe6, 0xb3, 0xff, 0xff, 0xf7, 0xff, 0xff, 0x98, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xe5, 0xf0, 0x10, 0xe4, 0xe8, 0x90, 0xe5, 0xf0, 0xf0, 0xe5, 0xf0, 0xa0, 0xe5, 0xf0, 0x30, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xe5, 0xf0, 0x20, 0xe4, 0xe8, 0xff, 0xe5, 0xf0, 0xff, 0xe4, 0xe8, 0xe0, 0xff, 0xff, 0x00, 0xe5, 0xf0, 0x10, 0xe4, 0xe8, 0x40, 0xe5, 0xf0, 0x70, 0xe4, 0xe8, 0x90, 0xe5, 0xf0, 0xc0, 0xe5, 0xf0, 0xd0, 0xe4, 0xf0, 0x80, 0xbb, 0xe6, 0xc0, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xa0, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xe5, 0xf0, 0x20, 0xe4, 0xe8, 0xa0, 0xe5, 0xf0, 0xff, 0xe5, 0xf0, 0xe0, 0xe4, 0xf0, 0x70, 0xe5, 0xe8, 0x70, 0xe4, 0xf0, 0xff, 0xe5, 0xe8, 0xff, 0xe4, 0xf0, 0x90, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xe5, 0xf0, 0x10, 0x99, 0xe6, 0xc0, 0xff, 0xff, 0xf7, 0xff, 0xff, 0x98, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xe5, 0xf0, 0x20, 0xe4, 0xe8, 0xa0, 0xe5, 0xf0, 0xff, 0xe4, 0xf0, 0xff, 0xe5, 0xe8, 0xff, 0xe4, 0xf0, 0xff, 0xe5, 0xe8, 0x30, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x01, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xe5, 0xf0, 0x20, 0xe4, 0xe8, 0xc0, 0xe5, 0xf0, 0xff, 0xe4, 0xe8, 0xd0, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xe5, 0xf0, 0x40, 0xe4, 0xf0, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x50, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format:  Blue: 5 bit Green: 6 bit, Red: 5 bit, Alpha 8 bit  BUT the 2  color bytes are swapped*/
  0x00, 0x00, 0x70, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x60, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xfc, 0x46, 0x10, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xfc, 0x67, 0x40, 0xfc, 0x46, 0xff, 0xfc, 0x66, 0xa0, 0xfc, 0x46, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0xa3, 0x8a, 0x94, 0xfb, 0xa6, 0x80, 0xf3, 0xc6, 0x20, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xfb, 0xa6, 0x90, 0xf3, 0xa5, 0xff, 0xf3, 0xa6, 0xff, 0xf3, 0xa6, 0xff, 0xfb, 0xc6, 0xe0, 0xf3, 0xa6, 0x70, 0xfb, 0xc6, 0x10, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x40, 0xf1, 0xc4, 0x10, 0xf1, 0xc5, 0x80, 0xf1, 0xe5, 0xc0, 0xf1, 0xc5, 0x60, 0xf1, 0xe5, 0x10, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf1, 0xc5, 0xd0, 0xf1, 0xc5, 0xff, 0xf1, 0xc4, 0xff, 0xf1, 0xc5, 0xf0, 0xe9, 0xc4, 0xff, 0xf1, 0xc5, 0xff, 0xe9, 0xc4, 0xff, 0xf1, 0xe5, 0xa0, 0xf1, 0xc5, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xe6, 0xfc, 0xb3, 0xff, 0xff, 0xf7, 0xff, 0xff, 0x98, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf0, 0xe5, 0x10, 0xe8, 0xe4, 0x90, 0xf0, 0xe5, 0xf0, 0xf0, 0xe5, 0xa0, 0xf0, 0xe5, 0x30, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf0, 0xe5, 0x20, 0xe8, 0xe4, 0xff, 0xf0, 0xe5, 0xff, 0xe8, 0xe4, 0xe0, 0xff, 0xff, 0x00, 0xf0, 0xe5, 0x10, 0xe8, 0xe4, 0x40, 0xf0, 0xe5, 0x70, 0xe8, 0xe4, 0x90, 0xf0, 0xe5, 0xc0, 0xf0, 0xe5, 0xd0, 0xf0, 0xe4, 0x80, 0xe6, 0xbb, 0xc0, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xa0, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf0, 0xe5, 0x20, 0xe8, 0xe4, 0xa0, 0xf0, 0xe5, 0xff, 0xf0, 0xe5, 0xe0, 0xf0, 0xe4, 0x70, 0xe8, 0xe5, 0x70, 0xf0, 0xe4, 0xff, 0xe8, 0xe5, 0xff, 0xf0, 0xe4, 0x90, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf0, 0xe5, 0x10, 0xe6, 0x99, 0xc0, 0xff, 0xff, 0xf7, 0xff, 0xff, 0x98, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf0, 0xe5, 0x20, 0xe8, 0xe4, 0xa0, 0xf0, 0xe5, 0xff, 0xf0, 0xe4, 0xff, 0xe8, 0xe5, 0xff, 0xf0, 0xe4, 0xff, 0xe8, 0xe5, 0x30, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x01, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf0, 0xe5, 0x20, 0xe8, 0xe4, 0xc0, 0xf0, 0xe5, 0xff, 0xe8, 0xe4, 0xd0, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xf0, 0xe5, 0x40, 0xf0, 0xe4, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x50, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format:  Blue: 8 bit, Green: 8 bit, Red: 8 bit, Alpha: 8 bit*/
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x01, 0x01, 0x01, 0x60, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x31, 0x89, 0xf6, 0x10, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x31, 0x89, 0xf6, 0x40, 0x31, 0x89, 0xf6, 0xff, 0x31, 0x89, 0xf6, 0xa0, 0x31, 0x89, 0xf6, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0x4f, 0x6e, 0x9f, 0x94, 0x2d, 0x75, 0xf3, 0x80, 0x2d, 0x75, 0xf3, 0x20, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x2d, 0x75, 0xf3, 0x90, 0x2d, 0x75, 0xf3, 0xff, 0x2d, 0x75, 0xf3, 0xff, 0x2d, 0x75, 0xf3, 0xff, 0x2d, 0x75, 0xf3, 0xe0, 0x2d, 0x75, 0xf3, 0x70, 0x2d, 0x75, 0xf3, 0x10, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0x25, 0x39, 0xee, 0x10, 0x25, 0x39, 0xee, 0x80, 0x25, 0x39, 0xee, 0xc0, 0x25, 0x39, 0xee, 0x60, 0x25, 0x39, 0xee, 0x10, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x25, 0x39, 0xee, 0xd0, 0x25, 0x39, 0xee, 0xff, 0x25, 0x39, 0xee, 0xff, 0x25, 0x39, 0xee, 0xf0, 0x25, 0x39, 0xee, 0xff, 0x25, 0x39, 0xee, 0xff, 0x25, 0x39, 0xee, 0xff, 0x25, 0x39, 0xee, 0xa0, 0x25, 0x39, 0xee, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xdc, 0xda, 0xdc, 0xb3, 0xfd, 0xfc, 0xff, 0xf7, 0xfc, 0xfc, 0xff, 0x98, 
  0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x24, 0x1c, 0xed, 0x10, 0x24, 0x1c, 0xed, 0x90, 0x24, 0x1c, 0xed, 0xf0, 0x24, 0x1c, 0xed, 0xa0, 0x24, 0x1c, 0xed, 0x30, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x24, 0x1c, 0xed, 0x20, 0x24, 0x1c, 0xed, 0xff, 0x24, 0x1c, 0xed, 0xff, 0x24, 0x1c, 0xed, 0xe0, 0xff, 0xff, 0xff, 0x00, 0x24, 0x1c, 0xed, 0x10, 0x24, 0x1c, 0xed, 0x40, 0x24, 0x1c, 0xed, 0x70, 0x24, 0x1c, 0xed, 0x90, 0x24, 0x1c, 0xed, 0xc0, 0x24, 0x1c, 0xed, 0xd0, 0x24, 0x1c, 0xed, 0x80, 0xd3, 0xd5, 0xe0, 0xc0, 0xf6, 0xf4, 0xfe, 0xff, 0xfc, 0xfb, 0xff, 0xa0, 
  0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x24, 0x1c, 0xed, 0x20, 0x24, 0x1c, 0xed, 0xa0, 0x24, 0x1c, 0xed, 0xff, 0x24, 0x1c, 0xed, 0xe0, 0x24, 0x1c, 0xed, 0x70, 0x24, 0x1c, 0xed, 0x70, 0x24, 0x1c, 0xed, 0xff, 0x24, 0x1c, 0xed, 0xff, 0x24, 0x1c, 0xed, 0x90, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x24, 0x1c, 0xed, 0x10, 0xca, 0xcf, 0xde, 0xc0, 0xfd, 0xfc, 0xff, 0xf7, 0xfc, 0xfc, 0xff, 0x98, 
  0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x24, 0x1c, 0xed, 0x20, 0x24, 0x1c, 0xed, 0xa0, 0x24, 0x1c, 0xed, 0xff, 0x24, 0x1c, 0xed, 0xff, 0x24, 0x1c, 0xed, 0xff, 0x24, 0x1c, 0xed, 0xff, 0x24, 0x1c, 0xed, 0x30, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x24, 0x1c, 0xed, 0x20, 0x24, 0x1c, 0xed, 0xc0, 0x24, 0x1c, 0xed, 0xff, 0x24, 0x1c, 0xed, 0xd0, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x24, 0x1c, 0xed, 0x40, 0x24, 0x1c, 0xed, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
  0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 
#endif
};

const lv_img_dsc_t battery_empty_icon = {
  .header.always_zero = 0,
  .header.w = 25,
  .header.h = 12,
  .data_size = 300 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .data = battery_empty_icon_map,
};

