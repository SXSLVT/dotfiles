#!/bin/bash

entries="󰐥 Shutdown\n󰑐 Restart\n󰤄 Sleep"

selected=$(echo -e "$entries" | wofi --dmenu --normal-window --width 200 --height 188 --prompt "Power" --cache-file /dev/null)

case $selected in
  *Shutdown*)
    systemctl poweroff ;;
  *Restart*)
    systemctl reboot ;;
  *Sleep*)
    systemctl suspend ;;
esac
