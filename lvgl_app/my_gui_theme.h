/**
 * @file reflow_oven_theme.h
 *
 */

#ifndef MY_GUI_THEME_H
#define MY_GUI_THEME_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "my_gui.h"
#include "lvgl.h"
/*********************
 *      DEFINES
 *********************/
/*Colors*/
#define MY_GUI_LIGHT           lv_color_hex(0xf3f8fe)
#define MY_GUI_GRAY            lv_color_hex(0x7f8c8d)
#define MY_GUI_LIGHT_GRAY      lv_color_hex(0xbdc3c7)
#define MY_GUI_LIGHT_BLUE      lv_color_hex(0x3498db)
#define MY_GUI_BLUE            lv_color_hex(0x2c3e50)
#define MY_GUI_PURPLE          lv_color_hex(0x8e44ad)
#define MY_GUI_LIGHT_GREEN     lv_color_hex(0x2ecc71)
#define MY_GUI_GREEN           lv_color_hex(0x4cb242)
#define MY_GUI_LIGHT_ORANGE    lv_color_hex(0xe67e22)
#define MY_GUI_LIGHT_RED       lv_color_hex(0xe74c3c)
#define MY_GUI_RED             lv_color_hex(0xd51732)
#define MY_GUI_YELLOW          lv_color_hex(0xf0f000)

/**********************
 *      TYPEDEFS
 **********************/
typedef enum {
    MY_GUI_THEME_TITLE = _LV_THEME_BUILTIN_LAST,
    MY_GUI_THEME_TITLE_WHITE,
    MY_GUI_THEME_LABEL_WHITE,
    MY_GUI_THEME_ICON,
    MY_GUI_THEME_ICON_LABEL,
    MY_GUI_THEME_CHART,
    MY_GUI_THEME_BTN_BORDER,
    MY_GUI_THEME_BTN_NEUTRAL,
    MY_GUI_THEME_BTN_NEGATIVE,
    MY_GUI_THEME_BTN_POSITIVE,
    MY_GUI_THEME_BOX_BORDER,
    MY_GUI_THEME_BTN_BACK
}my_gui_theme_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/


/**
 * Initialize the default
 * @param color_primary the primary color of the theme
 * @param color_secondary the secondary color for the theme
 * @param flags ORed flags starting with `LV_THEME_DEF_FLAG_...`
 * @param font_small pointer to a small font
 * @param font_normal pointer to a normal font
 * @param font_subtitle pointer to a large font
 * @param font_title pointer to a extra large font
 * @return a pointer to reference this theme later
 */
lv_theme_t * my_gui_theme_init(lv_color_t color_primary, lv_color_t color_secondary, uint32_t flags,
                                    const lv_font_t * font_small, const lv_font_t * font_normal, const lv_font_t * font_subtitle,
                                    const lv_font_t * font_title);
/**********************
 *      MACROS
 **********************/

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
