/**
 * @file gui_scr_boot.c
 *
 */

#include "lvgl.h"
#include "gui_maker.h"


/*********************
 *      DEFINES
 *********************/
#define BOOT_IMG_FILENAME "Max_logo.png"

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *      VARIABLES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void setup_scr_boot(lv_ui *ui, lv_obj_t *page)
{
    (void)ui; /*Unused*/

    char buffer[256];
    lv_snprintf(buffer, sizeof(buffer), "A:/%s", BOOT_IMG_FILENAME);
    // printf("load img : %s",buffer);
    lv_obj_t *img = lv_img_create(page);
    lv_img_set_src(img, buffer);
    lv_obj_align_to(img, page, LV_ALIGN_TOP_MID, 0, 16);


    lv_obj_t *preload = lv_spinner_create(page, 1000, 40);
    lv_obj_set_size(preload, 78, 78);
    lv_obj_set_style_arc_color(preload, lv_color_hex(0x1D2A5C), LV_PART_INDICATOR);
    lv_obj_align_to(preload, page, LV_ALIGN_BOTTOM_MID, 0, -64);

}
