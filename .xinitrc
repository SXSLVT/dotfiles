xwallpaper --zoom Pictures/bmw.jpg &
xset r rate 170 40 &
xrandr -s 1920x1080 &
picom -b &
dbus-launch pipewire &
dbus-launch pipewire-pulse &
dbus-launch wireplumber &
exec i3;
