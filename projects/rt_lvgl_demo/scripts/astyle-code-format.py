#!/usr/bin/env python3

import os


print("Formatting board")
os.system('astyle --options=.astylerc --recursive "../board/*.c,*.h"')

