/**
 * @file gui_maker.c
 *
 */

#include "lvgl.h"
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include "gui_maker.h"
#include "page_mgmt.h"

/*********************
 *      DEFINES
 *********************/

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

void setup_ui(lv_ui *ui)
{
    (void)ui; /*Unused*/
    page_init();

    page_open(SCR_BOOT);
}
