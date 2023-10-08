/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-18     Meco Man     The first version
 */
#include <lvgl.h>
#include <stdbool.h>
#include <rtdevice.h>

#include <drv_clcd.h>

lv_indev_t * touch_indev;

static lv_indev_state_t last_state = LV_INDEV_STATE_REL;
static rt_int16_t last_x = 0;
static rt_int16_t last_y = 0;

static void input_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    data->point.x = last_x;
    data->point.y = last_y;
    data->state = last_state;
}

void lv_port_indev_input(rt_int16_t x, rt_int16_t y, lv_indev_state_t state)
{
    last_state = state;
    last_x = x;
    last_y = y;
}

void lv_port_indev_init(void)
{
    static lv_indev_drv_t indev_drv;

    lv_indev_drv_init(&indev_drv);      /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = input_read;

    /*Register the driver in LVGL and save the created input device object*/
    touch_indev = lv_indev_drv_register(&indev_drv);
    
    LV_IMG_DECLARE(mouse_cursor_icon);                          /*Declare the image source.*/
    lv_obj_t * cursor_obj = lv_img_create(lv_scr_act());       /*Create an image object for the cursor */
    lv_img_set_src(cursor_obj, &mouse_cursor_icon);             /*Set the image source*/
    lv_indev_set_cursor(touch_indev, cursor_obj);               /*Connect the image  object to the driver*/
}
