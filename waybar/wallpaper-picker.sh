#!/bin/bash

WALLPAPERS_DIR="$HOME/Wallpapers"

find "$WALLPAPERS_DIR" -type f \( -iname "*.jpg" -o -iname "*.png" -o -iname "*.jpeg" \) | while read -r img; do
    name=$(basename "$img")
    echo -e "img:$img:text:$name"
done | \
wofi --dmenu \
     --prompt "Select Wallpaper..." \
     --width 500 \
     --height 250 \
     --cache-file /dev/null \
     --normal-window \
     --insensitive \
     --allow-images \
     --image-size 100 | \
     sed 's/.*:text://' | xargs -I {} find "$WALLPAPERS_DIR" -name "{}" | xargs -I {} ~/.config/waybar/wal-set "{}"
