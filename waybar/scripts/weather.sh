#!/bin/bash

CITY=$(curl -s https://ipinfo.io/city 2>/dev/null || echo "Unknown")

DATA=$(curl -s "https://wttr.in/${CITY// /+}?format=j1" 2>/dev/null)

if [ -z "$DATA" ] || [ "$(echo "$DATA" | jq -r '.current_condition[0].temp_C' 2>/dev/null)" = "null" ]; then
    echo '{"text": "󰅚 ", "tooltip": "Weather unavailable"}'
    exit 1
fi

TEMP=$(echo "$DATA" | jq -r '.current_condition[0].temp_C')
FEELS=$(echo "$DATA" | jq -r '.current_condition[0].FeelsLikeC')
WEATHER_CODE=$(echo "$DATA" | jq -r '.current_condition[0].weatherCode')

case $WEATHER_CODE in
    113) ICON=" " ;;    
    116) ICON=" " ;;        
    119) ICON=" " ;;      
    122) ICON=" " ;;    
    143|176|263|266|281|284|293|296|299|302|305|308) ICON=" " ;; 
    311|314|317|320|323|326|329|332|335|338|350|353|356|359|362|365|368|371|374|377) ICON=" " ;;
    179|182|185|200|227|230|386|389|392|395) ICON=" " ;;
    389|392|395) ICON=" " ;;
    *) ICON=" " ;;      
esac

HOUR=$(date +%H)
if [ "$HOUR" -ge 20 ] || [ "$HOUR" -le 6 ]; then
    case $ICON in
        ) ICON=" " ;;  
        ) ICON=" " ;;
    esac
fi

TEXT="${ICON} ${TEMP}°C"

echo "{\"text\": \"$TEXT\", \"tooltip\": \"${CITY}\nFeels like: ${FEELS}°C\"}"
