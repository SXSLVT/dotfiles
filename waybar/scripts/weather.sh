#!/bin/bash

CACHE_FILE="$HOME/.cache/waybar-weather-raw.json"
UNIT_FILE="$HOME/.cache/weather-unit"
CITY="Beacon Hills"          # ← CHANGE THIS TO YOUR CITY

[ ! -f "$UNIT_FILE" ] && echo "C" > "$UNIT_FILE"
UNIT=$(cat "$UNIT_FILE")

if [ ! -f "$CACHE_FILE" ] || [ $(( $(date +%s) - $(stat -c %Y "$CACHE_FILE") )) -gt 600 ]; then
    curl -s "https://wttr.in/${CITY// /+}?format=j1" -o "$CACHE_FILE"
fi

if [ ! -s "$CACHE_FILE" ] || [ "$(jq -r '.current_condition[0].temp_C' "$CACHE_FILE" 2>/dev/null)" = "null" ]; then
    echo '{"text": "󰅚 ", "tooltip": "Weather unavailable"}'
    exit 1
fi

TEMP_C=$(jq -r '.current_condition[0].temp_C' "$CACHE_FILE")
FEELS_C=$(jq -r '.current_condition[0].FeelsLikeC' "$CACHE_FILE")
WEATHER_CODE=$(jq -r '.current_condition[0].weatherCode' "$CACHE_FILE")

if [ "$UNIT" = "F" ]; then
    TEMP=$(awk "BEGIN {printf \"%.0f\", ($TEMP_C * 9/5 + 32)}")
    FEELS=$(awk "BEGIN {printf \"%.0f\", ($FEELS_C * 9/5 + 32)}")
    UNIT_SYMBOL="°F"
else
    TEMP=$TEMP_C
    FEELS=$FEELS_C
    UNIT_SYMBOL="°C"
fi

case $WEATHER_CODE in
    113) ICON=" " ;;    
    116) ICON=" " ;;        
    119|122) ICON=" " ;;    
    143|176|263|266|281|284|293|296|299|302|305|308) ICON=" " ;; 
    311|314|317|320|323|326|329|332|335|338|350|353|356|359|362|365|368|371|374|377) ICON=" " ;;
    179|182|185|200|227|230|386|389|392|395) ICON=" " ;;
    *) ICON=" " ;;      
esac

HOUR=$(date +%H)
if [ "$HOUR" -ge 20 ] || [ "$HOUR" -le 6 ]; then
    case $ICON in
        ) ICON=" " ;;  
        ) ICON=" " ;;
    esac
fi

TEXT="${ICON} ${TEMP}${UNIT_SYMBOL}"

echo "{\"text\": \"$TEXT\", \"tooltip\": \"${CITY}\nFeels like: ${FEELS}${UNIT_SYMBOL}\"}"
