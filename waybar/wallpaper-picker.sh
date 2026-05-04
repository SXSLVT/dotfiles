#!/bin/bash

WALLPAPERS_DIR="$HOME/Wallpapers"

selected=$(find "$WALLPAPERS_DIR" -type f \( -iname "*.jpg" -o -iname "*.png" -o -iname "*.jpeg" \) | while read -r img; do
    name=$(basename "$img")
    echo -e "img:$img:text:$name"
done | \
wofi --dmenu \
     --prompt "Select Wallpaper..." \
     --width 500 \
     --height 230 \
     --cache-file /dev/null \
     --normal-window \
     --insensitive \
     --allow-images \
     --image-size 150)

if [ -n "$selected" ]; then
    img_path=$(echo "$selected" | sed 's/^img://;s/:text:.*$//')
    cp "$img_path" "$HOME/.cache/current_wallpaper.png"
    awww img "$img_path" --transition-type right
    ~/.config/waybar/wal-set "$img_path"
fi
