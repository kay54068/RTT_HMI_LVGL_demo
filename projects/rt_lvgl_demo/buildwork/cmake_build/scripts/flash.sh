#!/bin/sh
sudo pyocd flash --frequency=8000000 --target=R7FA6M3AH --erase=auto $1
