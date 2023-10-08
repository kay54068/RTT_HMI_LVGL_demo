/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#include "gui_maker.h"
#include <stdio.h>
lv_ui guimaker_ui;

void lv_user_gui_init(void)
{
    setup_ui(&guimaker_ui);
}
