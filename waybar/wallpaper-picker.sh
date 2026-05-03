#!/bin/bash

WALLPAPERS_DIR="$HOME/Wallpapers"

find "$WALLPAPERS_DIR" -type f \( -iname "*.jpg" -o -iname "*.png" -o -iname "*.jpeg" \) | \
wofi --dmenu \
     --prompt "Select Wallpaper..." \
     --width 500 \
     --height 230 \
     --cache-file /dev/null \
     --insensitive \
     | xargs -I {} ~/.config/waybar/wal-set "{}"
