#!/bin/bash

entries="󰐥 Shutdown\n󰑐 Restart\n󰤄 Sleep"

selected=$(echo -e "$entries" | fuzzel --dmenu --width 15 --lines 3 --no-sort --index)

case $selected in
  Shutdown)
    systemctl poweroff ;;
  Restart)
    systemctl reboot ;;
  Sleep)
    systemctl suspend ;;
esac
