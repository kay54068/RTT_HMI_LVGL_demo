PROJECT(rtthread C CXX ASM)

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# ------------------------------------------------------------------------------
# Build Options 
# ------------------------------------------------------------------------------
option(BUILD_DOC "Build documentation with doxygen" OFF)

set(ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

SET(DOC_DIR ${ROOT_PATH}/docs)


SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_PROCESSOR cortex-m4)
#SET(CMAKE_VERBOSE_MAKEFILE ON)

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

SET(CMAKE_C_COMPILER "/usr/bin/arm-none-eabi-gcc")
SET(CMAKE_ASM_COMPILER "/usr/bin/arm-none-eabi-gcc")
SET(CMAKE_C_FLAGS " -mcpu=cortex-m4 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Dgcc -Os")
SET(CMAKE_ASM_FLAGS " -c -mcpu=cortex-m4 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -x assembler-with-cpp -Wa,-mimplicit-it=thumb ")
SET(CMAKE_C_COMPILER_WORKS TRUE)

SET(CMAKE_CXX_COMPILER "/usr/bin/arm-none-eabi-g++")
SET(CMAKE_CXX_FLAGS " -mcpu=cortex-m4 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Dgcc -Os")
SET(CMAKE_CXX_COMPILER_WORKS TRUE)

SET(CMAKE_OBJCOPY "/usr/bin/arm-none-eabi-objcopy")
SET(CMAKE_SIZE "/usr/bin/arm-none-eabi-size")

SET(CMAKE_EXE_LINKER_FLAGS " -mcpu=cortex-m4 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Wl,--gc-sections,-Map=rtthread.map,-cref,-u,Reset_Handler -T ${CMAKE_SOURCE_DIR}/ld-script/fsp.ld -L ${CMAKE_SOURCE_DIR}/ld-script/")

SET(CMAKE_CXX_STANDARD 14)


message(STATUS "ROOT_PATH : \"${ROOT_PATH}\"")
message(STATUS "DOC_DIR : \"${DOC_DIR}\"")


INCLUDE_DIRECTORIES(
	.
	board/ports/audio
	rt-thread/components/libc/compilers/common/include
	rt-thread/components/libc/compilers/newlib
	rt-thread/libcpu/arm/common
	rt-thread/libcpu/arm/cortex-m4
	rt-thread/components/drivers/include
	rt-thread/components/drivers/touch
	board
	board/ports
	board/ports/wifi
	libraries/HAL_Drivers
	libraries/HAL_Drivers/config
	rt-thread/components/dfs/dfs_v1/include
	rt-thread/components/dfs/dfs_v1/filesystems/elmfat
	rt-thread/components/dfs/dfs_v1/filesystems/devfs
	rt-thread/components/finsh
	board/ports/touch/gt911/inc
	rt-thread/include
	packages/LVGL-v8.3.9/src
	packages/LVGL-v8.3.9/src/font
	packages/LVGL-v8.3.9/src/misc
	packages/LVGL-v8.3.9/src/core
	packages/LVGL-v8.3.9/src/widgets
	packages/LVGL-v8.3.9/src/draw
	packages/LVGL-v8.3.9/src/hal
	packages/LVGL-v8.3.9/src/extra
	packages/LVGL-v8.3.9/src/draw/stm32_dma2d
	packages/LVGL-v8.3.9/src/draw/sdl
	packages/LVGL-v8.3.9/src/draw/swm341_dma2d
	packages/LVGL-v8.3.9/src/draw/arm2d
	packages/LVGL-v8.3.9/src/draw/sw
	packages/LVGL-v8.3.9/src/draw/renesas
	packages/LVGL-v8.3.9/src/draw/nxp/pxp
	packages/LVGL-v8.3.9/src/draw/nxp/vglite
	packages/LVGL-v8.3.9/src/extra/themes
	packages/LVGL-v8.3.9/src/extra/others
	packages/LVGL-v8.3.9/src/extra/widgets
	packages/LVGL-v8.3.9/src/extra/libs
	packages/LVGL-v8.3.9/src/extra/layouts
	packages/LVGL-v8.3.9/src/extra/themes/default
	packages/LVGL-v8.3.9/src/extra/themes/mono
	packages/LVGL-v8.3.9/src/extra/themes/basic
	packages/LVGL-v8.3.9/src/extra/others/monkey
	packages/LVGL-v8.3.9/src/extra/others/imgfont
	packages/LVGL-v8.3.9/src/extra/others/msg
	packages/LVGL-v8.3.9/src/extra/others/fragment
	packages/LVGL-v8.3.9/src/extra/others/gridnav
	packages/LVGL-v8.3.9/src/extra/others/snapshot
	packages/LVGL-v8.3.9/src/extra/others/ime
	packages/LVGL-v8.3.9/src/extra/widgets/calendar
	packages/LVGL-v8.3.9/src/extra/widgets/spinner
	packages/LVGL-v8.3.9/src/extra/widgets/keyboard
	packages/LVGL-v8.3.9/src/extra/widgets/menu
	packages/LVGL-v8.3.9/src/extra/widgets/led
	packages/LVGL-v8.3.9/src/extra/widgets/colorwheel
	packages/LVGL-v8.3.9/src/extra/widgets/meter
	packages/LVGL-v8.3.9/src/extra/widgets/imgbtn
	packages/LVGL-v8.3.9/src/extra/widgets/tabview
	packages/LVGL-v8.3.9/src/extra/widgets/spinbox
	packages/LVGL-v8.3.9/src/extra/widgets/chart
	packages/LVGL-v8.3.9/src/extra/widgets/msgbox
	packages/LVGL-v8.3.9/src/extra/widgets/tileview
	packages/LVGL-v8.3.9/src/extra/widgets/list
	packages/LVGL-v8.3.9/src/extra/widgets/win
	packages/LVGL-v8.3.9/src/extra/widgets/animimg
	packages/LVGL-v8.3.9/src/extra/widgets/span
	packages/LVGL-v8.3.9/src/extra/libs/png
	packages/LVGL-v8.3.9/src/extra/libs/sjpg
	packages/LVGL-v8.3.9/src/extra/libs/gif
	packages/LVGL-v8.3.9/src/extra/libs/ffmpeg
	packages/LVGL-v8.3.9/src/extra/libs/bmp
	packages/LVGL-v8.3.9/src/extra/libs/fsdrv
	packages/LVGL-v8.3.9/src/extra/libs/freetype
	packages/LVGL-v8.3.9/src/extra/libs/rlottie
	packages/LVGL-v8.3.9/src/extra/libs/qrcode
	packages/LVGL-v8.3.9/src/extra/layouts/flex
	packages/LVGL-v8.3.9/src/extra/layouts/grid
	board/lvgl/demo/file_explorer
	board/lvgl/demo/video/img
	board/lvgl/demo/video
	board/lvgl/demo
	packages/LVGL-v8.3.9/env_support/rt-thread
	board/lvgl
	board/ports/avi/player
	board/ports/avi
	rt-thread/components/libc/posix/ipc
	rt-thread/components/libc/posix/io/stdio
	rt-thread/components/libc/posix/io/poll
	ra/arm/CMSIS_5/CMSIS/Core/Include
	ra/fsp/inc
	ra/fsp/inc/api
	ra/fsp/inc/instances
	ra/tes/dave2d/inc
	ra_cfg/fsp_cfg
	ra_cfg/fsp_cfg/bsp
	ra_gen
)

ADD_DEFINITIONS(
	-DRT_USING_LIBC
	-DRT_USING_NEWLIBC
	-D_POSIX_C_SOURCE=1
	-D__RTTHREAD__
)

SET(PROJECT_SOURCES
	src/hal_entry.c
	board/ports/audio/pwm_audio.c
	rt-thread/components/libc/compilers/common/cctype.c
	rt-thread/components/libc/compilers/common/cstdio.c
	rt-thread/components/libc/compilers/common/cstdlib.c
	rt-thread/components/libc/compilers/common/cstring.c
	rt-thread/components/libc/compilers/common/ctime.c
	rt-thread/components/libc/compilers/common/cwchar.c
	rt-thread/components/libc/compilers/newlib/syscalls.c
	rt-thread/libcpu/arm/common/atomic_arm.c
	rt-thread/libcpu/arm/common/div0.c
	rt-thread/libcpu/arm/common/showmem.c
	rt-thread/libcpu/arm/cortex-m4/context_gcc.S
	rt-thread/libcpu/arm/cortex-m4/cpuport.c
	rt-thread/components/drivers/i2c/i2c-bit-ops.c
	rt-thread/components/drivers/i2c/i2c_core.c
	rt-thread/components/drivers/i2c/i2c_dev.c
	rt-thread/components/drivers/ipc/completion.c
	rt-thread/components/drivers/ipc/dataqueue.c
	rt-thread/components/drivers/ipc/pipe.c
	rt-thread/components/drivers/ipc/ringblk_buf.c
	rt-thread/components/drivers/ipc/ringbuffer.c
	rt-thread/components/drivers/ipc/waitqueue.c
	rt-thread/components/drivers/ipc/workqueue.c
	rt-thread/components/drivers/misc/pin.c
	rt-thread/components/drivers/misc/rt_drv_pwm.c
	rt-thread/components/drivers/sdio/block_dev.c
	rt-thread/components/drivers/sdio/gpt.c
	rt-thread/components/drivers/sdio/mmc.c
	rt-thread/components/drivers/sdio/mmcsd_core.c
	rt-thread/components/drivers/sdio/sd.c
	rt-thread/components/drivers/sdio/sdio.c
	rt-thread/components/drivers/serial/serial_v2.c
	rt-thread/components/drivers/touch/touch.c
	board/ports/drv_g2d.c
	board/ports/drv_jpeg.c
	board/ports/mnt.c
	board/ra6m3_it.c
	libraries/HAL_Drivers/drv_common.c
	libraries/HAL_Drivers/drv_gpio.c
	libraries/HAL_Drivers/drv_lcd.c
	libraries/HAL_Drivers/drv_pwm.c
	libraries/HAL_Drivers/drv_sdhi.c
	libraries/HAL_Drivers/drv_soft_i2c.c
	libraries/HAL_Drivers/drv_usart_v2.c
	rt-thread/components/dfs/dfs_v1/filesystems/devfs/devfs.c
	rt-thread/components/dfs/dfs_v1/filesystems/elmfat/dfs_elm.c
	rt-thread/components/dfs/dfs_v1/filesystems/elmfat/ff.c
	rt-thread/components/dfs/dfs_v1/filesystems/elmfat/ffunicode.c
	rt-thread/components/dfs/dfs_v1/src/dfs.c
	rt-thread/components/dfs/dfs_v1/src/dfs_file.c
	rt-thread/components/dfs/dfs_v1/src/dfs_fs.c
	rt-thread/components/dfs/dfs_v1/src/dfs_posix.c
	rt-thread/components/finsh/msh_file.c
	rt-thread/components/finsh/cmd.c
	rt-thread/components/finsh/shell.c
	rt-thread/components/finsh/msh.c
	rt-thread/components/finsh/msh_parse.c
	board/ports/touch/gt911/src/gt911.c
	rt-thread/src/clock.c
	rt-thread/src/components.c
	rt-thread/src/device.c
	rt-thread/src/idle.c
	rt-thread/src/ipc.c
	rt-thread/src/irq.c
	rt-thread/src/kservice.c
	rt-thread/src/mem.c
	rt-thread/src/object.c
	rt-thread/src/scheduler_up.c
	rt-thread/src/thread.c
	rt-thread/src/timer.c
	packages/LVGL-v8.3.9/src/widgets/lv_canvas.c
	packages/LVGL-v8.3.9/src/extra/others/fragment/lv_fragment.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_arc.c
	packages/LVGL-v8.3.9/src/extra/widgets/spinbox/lv_spinbox.c
	packages/LVGL-v8.3.9/src/font/lv_font_loader.c
	packages/LVGL-v8.3.9/src/draw/arm2d/lv_gpu_arm2d.c
	packages/LVGL-v8.3.9/src/draw/nxp/pxp/lv_draw_pxp.c
	packages/LVGL-v8.3.9/src/draw/sw/lv_draw_sw_layer.c
	packages/LVGL-v8.3.9/src/core/lv_obj_scroll.c
	packages/LVGL-v8.3.9/src/draw/lv_draw_layer.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_28.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_38.c
	packages/LVGL-v8.3.9/src/extra/widgets/span/lv_span.c
	packages/LVGL-v8.3.9/src/extra/themes/basic/lv_theme_basic.c
	packages/LVGL-v8.3.9/src/misc/lv_tlsf.c
	packages/LVGL-v8.3.9/src/widgets/lv_checkbox.c
	packages/LVGL-v8.3.9/src/extra/lv_extra.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_texture_cache.c
	packages/LVGL-v8.3.9/src/extra/libs/bmp/lv_bmp.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_30.c
	packages/LVGL-v8.3.9/src/draw/nxp/pxp/lv_draw_pxp_blend.c
	packages/LVGL-v8.3.9/src/draw/sw/lv_draw_sw_rect.c
	packages/LVGL-v8.3.9/src/core/lv_event.c
	packages/LVGL-v8.3.9/src/draw/lv_img_cache.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_20.c
	packages/LVGL-v8.3.9/src/extra/widgets/menu/lv_menu.c
	packages/LVGL-v8.3.9/src/misc/lv_mem.c
	packages/LVGL-v8.3.9/src/extra/layouts/flex/lv_flex.c
	packages/LVGL-v8.3.9/src/widgets/lv_dropdown.c
	packages/LVGL-v8.3.9/src/misc/lv_timer.c
	packages/LVGL-v8.3.9/src/extra/others/snapshot/lv_snapshot.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_bg.c
	packages/LVGL-v8.3.9/src/extra/widgets/chart/lv_chart.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_40.c
	packages/LVGL-v8.3.9/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.c
	packages/LVGL-v8.3.9/src/font/lv_font_unscii_8.c
	packages/LVGL-v8.3.9/src/core/lv_theme.c
	packages/LVGL-v8.3.9/src/draw/lv_draw_arc.c
	packages/LVGL-v8.3.9/src/font/lv_font_fmt_txt.c
	packages/LVGL-v8.3.9/src/extra/libs/sjpg/tjpgd.c
	packages/LVGL-v8.3.9/src/misc/lv_lru.c
	packages/LVGL-v8.3.9/src/widgets/lv_switch.c
	packages/LVGL-v8.3.9/src/misc/lv_style_gen.c
	packages/LVGL-v8.3.9/src/extra/others/gridnav/lv_gridnav.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl.c
	packages/LVGL-v8.3.9/src/extra/libs/fsdrv/lv_fs_posix.c
	packages/LVGL-v8.3.9/src/font/lv_font_simsun_16_cjk.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_10.c
	packages/LVGL-v8.3.9/src/core/lv_refr.c
	packages/LVGL-v8.3.9/src/draw/lv_img_decoder.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_34.c
	packages/LVGL-v8.3.9/src/extra/widgets/led/lv_led.c
	packages/LVGL-v8.3.9/src/extra/others/monkey/lv_monkey.c
	packages/LVGL-v8.3.9/src/misc/lv_math.c
	packages/LVGL-v8.3.9/src/draw/sw/lv_draw_sw_line.c
	packages/LVGL-v8.3.9/src/extra/layouts/grid/lv_grid.c
	packages/LVGL-v8.3.9/src/widgets/lv_bar.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_layer.c
	packages/LVGL-v8.3.9/src/extra/widgets/msgbox/lv_msgbox.c
	packages/LVGL-v8.3.9/src/font/lv_font_dejavu_16_persian_hebrew.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_28_compressed.c
	packages/LVGL-v8.3.9/src/core/lv_obj_draw.c
	packages/LVGL-v8.3.9/src/draw/lv_draw_transform.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_12_subpx.c
	packages/LVGL-v8.3.9/src/misc/lv_utils.c
	packages/LVGL-v8.3.9/src/draw/sw/lv_draw_sw_polygon.c
	packages/LVGL-v8.3.9/src/widgets/lv_slider.c
	packages/LVGL-v8.3.9/src/extra/libs/png/lv_png.c
	packages/LVGL-v8.3.9/src/extra/others/ime/lv_ime_pinyin.c
	packages/LVGL-v8.3.9/src/draw/nxp/vglite/lv_draw_vglite_arc.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_polygon.c
	packages/LVGL-v8.3.9/src/extra/libs/freetype/lv_freetype.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_16.c
	packages/LVGL-v8.3.9/src/draw/stm32_dma2d/lv_gpu_stm32_dma2d.c
	packages/LVGL-v8.3.9/src/core/lv_obj_style.c
	packages/LVGL-v8.3.9/src/draw/lv_draw_label.c
	packages/LVGL-v8.3.9/src/extra/widgets/colorwheel/lv_colorwheel.c
	packages/LVGL-v8.3.9/src/misc/lv_area.c
	packages/LVGL-v8.3.9/src/draw/sw/lv_draw_sw_img.c
	packages/LVGL-v8.3.9/src/misc/lv_txt.c
	packages/LVGL-v8.3.9/src/widgets/lv_line.c
	packages/LVGL-v8.3.9/src/extra/libs/png/lodepng.c
	packages/LVGL-v8.3.9/src/draw/nxp/vglite/lv_draw_vglite_blend.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_img.c
	packages/LVGL-v8.3.9/src/draw/renesas/lv_gpu_d2_draw_label.c
	packages/LVGL-v8.3.9/src/extra/widgets/tileview/lv_tileview.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_42.c
	packages/LVGL-v8.3.9/src/widgets/lv_arc.c
	packages/LVGL-v8.3.9/src/core/lv_obj_class.c
	packages/LVGL-v8.3.9/src/draw/lv_draw_img.c
	packages/LVGL-v8.3.9/src/extra/others/imgfont/lv_imgfont.c
	packages/LVGL-v8.3.9/src/misc/lv_fs.c
	packages/LVGL-v8.3.9/src/draw/sw/lv_draw_sw_arc.c
	packages/LVGL-v8.3.9/src/misc/lv_printf.c
	packages/LVGL-v8.3.9/src/extra/widgets/calendar/lv_calendar_header_dropdown.c
	packages/LVGL-v8.3.9/src/draw/nxp/vglite/lv_draw_vglite.c
	packages/LVGL-v8.3.9/src/widgets/lv_img.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_stack_blur.c
	packages/LVGL-v8.3.9/src/draw/renesas/lv_gpu_d2_ra6m3.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_8.c
	packages/LVGL-v8.3.9/src/widgets/lv_label.c
	packages/LVGL-v8.3.9/src/extra/libs/fsdrv/lv_fs_fatfs.c
	packages/LVGL-v8.3.9/src/core/lv_disp.c
	packages/LVGL-v8.3.9/src/draw/lv_img_buf.c
	packages/LVGL-v8.3.9/src/extra/widgets/meter/lv_meter.c
	packages/LVGL-v8.3.9/src/misc/lv_gc.c
	packages/LVGL-v8.3.9/src/draw/sw/lv_draw_sw_blend.c
	packages/LVGL-v8.3.9/src/extra/libs/gif/lv_gif.c
	packages/LVGL-v8.3.9/src/draw/nxp/vglite/lv_draw_vglite_line.c
	packages/LVGL-v8.3.9/src/widgets/lv_table.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_rect.c
	packages/LVGL-v8.3.9/src/extra/widgets/list/lv_list.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_44.c
	packages/LVGL-v8.3.9/src/misc/lv_color.c
	packages/LVGL-v8.3.9/src/widgets/lv_btnmatrix.c
	packages/LVGL-v8.3.9/src/extra/libs/fsdrv/lv_fs_stdio.c
	packages/LVGL-v8.3.9/src/core/lv_obj_style_gen.c
	packages/LVGL-v8.3.9/src/extra/themes/default/lv_theme_default.c
	packages/LVGL-v8.3.9/src/draw/lv_draw.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_line.c
	packages/LVGL-v8.3.9/src/font/lv_font.c
	packages/LVGL-v8.3.9/src/misc/lv_log.c
	packages/LVGL-v8.3.9/src/draw/sw/lv_draw_sw_dither.c
	packages/LVGL-v8.3.9/src/core/lv_indev_scroll.c
	packages/LVGL-v8.3.9/src/draw/nxp/vglite/lv_vglite_utils.c
	packages/LVGL-v8.3.9/src/extra/widgets/spinner/lv_spinner.c
	packages/LVGL-v8.3.9/src/widgets/lv_btn.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_14.c
	packages/LVGL-v8.3.9/src/misc/lv_txt_ap.c
	packages/LVGL-v8.3.9/src/extra/libs/sjpg/lv_sjpg.c
	packages/LVGL-v8.3.9/src/extra/libs/fsdrv/lv_fs_win32.c
	packages/LVGL-v8.3.9/src/core/lv_indev.c
	packages/LVGL-v8.3.9/src/extra/others/msg/lv_msg.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_utils.c
	packages/LVGL-v8.3.9/src/extra/widgets/imgbtn/lv_imgbtn.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_22.c
	packages/LVGL-v8.3.9/src/misc/lv_anim.c
	packages/LVGL-v8.3.9/src/draw/sw/lv_draw_sw_transform.c
	packages/LVGL-v8.3.9/src/core/lv_obj_pos.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_26.c
	packages/LVGL-v8.3.9/src/draw/nxp/vglite/lv_draw_vglite_rect.c
	packages/LVGL-v8.3.9/src/extra/widgets/calendar/lv_calendar_header_arrow.c
	packages/LVGL-v8.3.9/src/widgets/lv_objx_templ.c
	packages/LVGL-v8.3.9/src/draw/swm341_dma2d/lv_gpu_swm341_dma2d.c
	packages/LVGL-v8.3.9/src/extra/widgets/win/lv_win.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_36.c
	packages/LVGL-v8.3.9/src/misc/lv_ll.c
	packages/LVGL-v8.3.9/src/draw/lv_draw_line.c
	packages/LVGL-v8.3.9/src/extra/libs/rlottie/lv_rlottie.c
	packages/LVGL-v8.3.9/src/hal/lv_hal_disp.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_composite.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_12.c
	packages/LVGL-v8.3.9/src/misc/lv_templ.c
	packages/LVGL-v8.3.9/src/draw/sw/lv_draw_sw_gradient.c
	packages/LVGL-v8.3.9/src/core/lv_group.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_32.c
	packages/LVGL-v8.3.9/src/draw/nxp/vglite/lv_vglite_buf.c
	packages/LVGL-v8.3.9/src/extra/widgets/calendar/lv_calendar.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_18.c
	packages/LVGL-v8.3.9/src/misc/lv_style.c
	packages/LVGL-v8.3.9/src/draw/lv_draw_rect.c
	packages/LVGL-v8.3.9/src/extra/themes/mono/lv_theme_mono.c
	packages/LVGL-v8.3.9/src/extra/libs/ffmpeg/lv_ffmpeg.c
	packages/LVGL-v8.3.9/src/widgets/lv_roller.c
	packages/LVGL-v8.3.9/src/hal/lv_hal_tick.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_label.c
	packages/LVGL-v8.3.9/src/extra/widgets/tabview/lv_tabview.c
	packages/LVGL-v8.3.9/src/font/lv_font_unscii_16.c
	packages/LVGL-v8.3.9/src/misc/lv_anim_timeline.c
	packages/LVGL-v8.3.9/src/draw/sw/lv_draw_sw_letter.c
	packages/LVGL-v8.3.9/src/core/lv_obj.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_48.c
	packages/LVGL-v8.3.9/src/extra/widgets/animimg/lv_animimg.c
	packages/LVGL-v8.3.9/src/misc/lv_bidi.c
	packages/LVGL-v8.3.9/src/draw/lv_draw_mask.c
	packages/LVGL-v8.3.9/src/extra/libs/qrcode/lv_qrcode.c
	packages/LVGL-v8.3.9/src/widgets/lv_textarea.c
	packages/LVGL-v8.3.9/src/hal/lv_hal_indev.c
	packages/LVGL-v8.3.9/src/extra/others/fragment/lv_fragment_manager.c
	packages/LVGL-v8.3.9/src/draw/sdl/lv_draw_sdl_mask.c
	packages/LVGL-v8.3.9/src/extra/libs/gif/gifdec.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_24.c
	packages/LVGL-v8.3.9/src/draw/nxp/pxp/lv_gpu_nxp_pxp.c
	packages/LVGL-v8.3.9/src/draw/sw/lv_draw_sw.c
	packages/LVGL-v8.3.9/src/core/lv_obj_tree.c
	packages/LVGL-v8.3.9/src/draw/lv_draw_triangle.c
	packages/LVGL-v8.3.9/src/font/lv_font_montserrat_46.c
	packages/LVGL-v8.3.9/src/extra/widgets/keyboard/lv_keyboard.c
	packages/LVGL-v8.3.9/src/misc/lv_async.c
	packages/LVGL-v8.3.9/src/extra/libs/qrcode/qrcodegen.c
	board/lvgl/demo/file_explorer/lv_file_explorer.c
	board/lvgl/demo/lv_demo.c
	board/lvgl/demo/video/img/file_icon.c
	board/lvgl/demo/video/img/ui_img_audio_wave_1_png.c
	board/lvgl/demo/video/img/ui_img_indicator_ver_png.c
	board/lvgl/demo/video/img/ui_img_next_png.c
	board/lvgl/demo/video/img/ui_img_pause_png.c
	board/lvgl/demo/video/img/ui_img_prev_png.c
	board/lvgl/demo/video/img/ui_img_run_png.c
	board/lvgl/demo/video/lv_demo_video.c
	board/lvgl/demo/video/ui_helpers.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_btn_list_pause.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_btn_list_play.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_btn_loop.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_btn_next.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_btn_pause.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_btn_play.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_btn_prev.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_btn_rnd.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_corner_left.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_corner_right.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_cover_1.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_cover_2.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_cover_3.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_icon_1.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_icon_2.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_icon_3.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_icon_4.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_list_border.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_logo.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_slider_knob.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_wave_bottom.c
	packages/lv_music_demo-v0.3.3/assets/img_lv_demo_rtt_music_wave_top.c
	packages/lv_music_demo-v0.3.3/lv_demo_rtt_music.c
	packages/lv_music_demo-v0.3.3/lv_demo_rtt_music_list.c
	packages/lv_music_demo-v0.3.3/lv_demo_rtt_music_main.c
	board/lvgl/lv_port_disp.c
	board/lvgl/lv_port_indev.c
	packages/LVGL-v8.3.9/env_support/rt-thread/lv_rt_thread_port.c
	board/ports/avi/avifile.c
	board/ports/avi/player/player.c
	ra/fsp/src/bsp/mcu/all/bsp_guard.c
	ra/fsp/src/bsp/mcu/all/bsp_group_irq.c
	ra/fsp/src/r_ether/r_ether.c
	ra/fsp/src/r_glcdc/r_glcdc.c
	ra/tes/dave2d/src/dave_dlist.c
	ra/tes/dave2d/src/dave_64bitoperation.c
	ra/tes/dave2d/src/dave_blit.c
	ra/fsp/src/r_sdhi/r_sdhi.c
	ra/fsp/src/r_drw/r_drw_memory.c
	ra/tes/dave2d/src/dave_viewport.c
	ra/tes/dave2d/src/dave_perfcount.c
	ra/fsp/src/bsp/mcu/all/bsp_delay.c
	ra/tes/dave2d/src/dave_polyline.c
	ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/system.c
	ra/fsp/src/r_jpeg/r_jpeg.c
	ra/tes/dave2d/src/dave_render.c
	ra/fsp/src/r_can/r_can.c
	ra/tes/dave2d/src/dave_curve.c
	ra/tes/dave2d/src/dave_rbuffer.c
	ra/fsp/src/bsp/mcu/all/bsp_irq.c
	ra/fsp/src/bsp/mcu/all/bsp_sbrk.c
	ra/fsp/src/r_ether_phy/r_ether_phy.c
	ra/fsp/src/r_gpt/r_gpt.c
	ra/tes/dave2d/src/dave_gradient.c
	ra/tes/dave2d/src/dave_line.c
	ra/fsp/src/r_ssi/r_ssi.c
	ra/fsp/src/r_drw/r_drw_base.c
	ra/tes/dave2d/src/dave_errorcodes.c
	ra/tes/dave2d/src/dave_edge.c
	ra/fsp/src/bsp/mcu/all/bsp_common.c
	ra/tes/dave2d/src/dave_math.c
	ra/fsp/src/r_sci_spi/r_sci_spi.c
	ra/fsp/src/r_dmac/r_dmac.c
	ra/tes/dave2d/src/dave_memory.c
	ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/startup.c
	ra/tes/dave2d/src/dave_driver.c
	ra/fsp/src/bsp/mcu/all/bsp_rom_registers.c
	ra/tes/dave2d/src/dave_triangle.c
	ra/fsp/src/bsp/mcu/all/bsp_clocks.c
	ra/fsp/src/r_icu/r_icu.c
	ra/tes/dave2d/src/dave_texture.c
	ra/tes/dave2d/src/dave_wedge.c
	ra/fsp/src/bsp/mcu/all/bsp_security.c
	ra/fsp/src/r_dtc/r_dtc.c
	ra/tes/dave2d/src/dave_base.c
	ra/tes/dave2d/src/dave_circle.c
	ra/tes/dave2d/src/dave_utility.c
	ra/fsp/src/r_sci_uart/r_sci_uart.c
	ra/fsp/src/r_drw/r_drw_irq.c
	ra/tes/dave2d/src/dave_context.c
	ra/fsp/src/r_ioport/r_ioport.c
	ra/fsp/src/bsp/mcu/all/bsp_register_protection.c
	ra/tes/dave2d/src/dave_hardware.c
	ra/tes/dave2d/src/dave_pattern.c
	ra/fsp/src/bsp/mcu/all/bsp_io.c
	ra/tes/dave2d/src/dave_quad.c
	ra/tes/dave2d/src/dave_box.c
	ra_gen/main.c
	ra_gen/vector_data.c
	ra_gen/hal_data.c
	ra_gen/common_data.c
	ra_gen/pin_data.c
)

LINK_DIRECTORIES(
)

LINK_LIBRARIES(
	c
	m
)

ADD_EXECUTABLE(${CMAKE_PROJECT_NAME}.elf ${PROJECT_SOURCES})


ADD_CUSTOM_COMMAND(TARGET ${CMAKE_PROJECT_NAME}.elf POST_BUILD 
## Output bin
COMMAND ${CMAKE_OBJCOPY} -O binary ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.bin COMMAND ${CMAKE_SIZE} ${CMAKE_PROJECT_NAME}.elf
## Output hex
COMMAND ${CMAKE_OBJCOPY} -O ihex ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.hex COMMAND ${CMAKE_SIZE} ${CMAKE_PROJECT_NAME}.elf
)


if(BUILD_DOC)
include(cmakelib/build_doxygen.cmake)
build_doxygen()
endif()
