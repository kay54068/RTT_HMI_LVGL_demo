/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2023-02-22     Rbb666        First version
 */

#ifndef LV_CONF_H
#define LV_CONF_H

#include <rtconfig.h>

/* Enable additional color format support */
#define DLG_LVGL_CF                 0

#define LV_USE_GPU_RA6M3_G2D        1
#define LV_GPU_RA6M3_G2D_INCLUDE    "hal_data.h"

#define LV_USE_PERF_MONITOR         1
#define LV_COLOR_DEPTH              16

#ifdef PKG_USING_ILI9341
    #define LV_HOR_RES_MAX          240
    #define LV_VER_RES_MAX          320
    #define LV_COLOR_16_SWAP        1
    #define LV_DPI_DEF              99
#else
    #define LV_HOR_RES_MAX          DISPLAY_HSIZE_INPUT0
    #define LV_VER_RES_MAX          DISPLAY_VSIZE_INPUT0
    #define LV_DPI_DEF              89
#endif

#ifdef BSP_USING_LVGL_VIDEO_DEMO
    #define LV_USE_FILE_EXPLORER    1
    #if LV_USE_FILE_EXPLORER
        /*Maximum length of path*/
        #define LV_FILE_EXPLORER_PATH_MAX_LEN        (128)
        /*Quick access bar, 1:use, 0:not use*/
        /*Requires: lv_list*/
        #define LV_FILE_EXPLORER_QUICK_ACCESS        0
    #endif

    #define LV_USE_FS_STDIO 1
    #if LV_USE_FS_STDIO
        #define LV_FS_STDIO_LETTER 'A'      /*Set an upper cased letter on which the drive will accessible (e.g. 'A')*/
        #define LV_FS_STDIO_PATH ""        /*Set the working directory. File/directory paths will be appended to it.*/
        #define LV_FS_STDIO_CACHE_SIZE  0   /*>0 to cache this number of bytes in lv_fs_read()*/
    #endif
    #define LV_USE_PNG 1
    #define LV_USE_SJPG 1

    #define LV_IMG_CACHE_DEF_SIZE 64
#endif

#ifdef PKG_USING_LV_MUSIC_DEMO
    /* music player demo */
    #define LV_USE_DEMO_RTT_MUSIC       1
    #define LV_DEMO_RTT_MUSIC_AUTO_PLAY 1
    #define LV_FONT_MONTSERRAT_12       1
    #define LV_FONT_MONTSERRAT_16       1
    #define LV_COLOR_SCREEN_TRANSP      0
#endif /* PKG_USING_LV_MUSIC_DEMO */

#endif
