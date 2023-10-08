/**
 * @file gui_maker.h
 *
 */

#ifndef GUI_MAKER_H
#define GUI_MAKER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"



/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
enum SCR_ID {
    SCR_BOOT = 0
};

typedef struct {

    /**
     * Header
     */
    lv_obj_t *header;

} lv_ui;

/***********************
 * GLOBAL VARIABLES
 ***********************/
extern lv_ui guimaker_ui;


/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void setup_ui(lv_ui *ui);
void setup_scr_boot(lv_ui *ui, lv_obj_t *page);

/*gui_page_mgmt.c*/
void page_init();
void page_open(int scr_id);


#ifdef __cplusplus
}
#endif
#endif
