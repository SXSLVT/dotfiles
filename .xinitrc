xwallpaper --zoom Pictures/bmw.jpg &
xset r rate 170 40 &
xrandr -s 1920x1080 &
picom -b &
exec /usr/bin/pipewire &
exec /usr/bin/pipewire-pulse &
exec /usr/bin/wireplumber &
exec i3;
