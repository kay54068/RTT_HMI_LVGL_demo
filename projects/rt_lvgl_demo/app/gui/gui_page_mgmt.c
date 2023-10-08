/**
 * @file gui_page_mgmt.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <unistd.h>
#include "gui_maker.h"
#include "page_mgmt.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

lv_pm_open_options_t options = {
    .animation = LV_PM_ANIMA_NONE,
    .target = LV_PM_TARGET_SELF
};
/**********************
 *   STATIC FUNCTIONS
 **********************/

static void page_boot_Load(lv_obj_t *page)
{
    printf("onLoad\n");
    setup_scr_boot(&guimaker_ui, page);
}

static void page_boot_unLoad(lv_obj_t *page)
{
    (void)page; /*Unused*/
    printf("unLoad");
}

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void page_open(int scr_id)
{
    lv_pm_open_page(scr_id, &options);
}

void page_init()
{
    lv_pm_init();

    printf("page_init\n");

    lv_pm_page_t *page0 = lv_pm_create_page(SCR_BOOT);
    page0->onLoad =  page_boot_Load;
    page0->unLoad =  page_boot_unLoad;
    
}

