#!/bin/bash

UNIT_FILE="$HOME/.cache/weather-unit"
[ ! -f "$UNIT_FILE" ] && echo "C" > "$UNIT_FILE"

CURRENT=$(cat "$UNIT_FILE")
[ "$CURRENT" = "C" ] && echo "F" > "$UNIT_FILE" || echo "C" > "$UNIT_FILE"

pkill -SIGRTMIN+8 waybar
