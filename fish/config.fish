if status is-interactive
    set -U fish_greeting
    function fish_greeting
        synfetch
    end
    starship init fish | source
end

alias ls='eza -l --icons --color=always'
