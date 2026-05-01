if status is-interactive
    set -U fish_greeting
    function fish_greeting
        synfetch
    end
    starship init fish | source
end

function last_history_item
    echo $history[1]
end

abbr -a !! --position anywhere --function last_history_item

alias ls='eza -l --icons --color=always'
