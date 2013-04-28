
function descriptor()
    return { title = "Remote Control For VLC" ;
             version = "0.1" ;
             author = "Robo" ;
             capabilities = {} }
end

function activate()
    dlg = vlc.dialog("VLC-Remote")
    list = dlg:add_list(1, 3, 4, 1)
    button_play = dlg:add_button("Play", click_play, 1, 4, 4, 1)
    dlg:show()
end

function click_play()
    selection = list:get_selection()
    if (not selection) then return 1 end
    local sel = nil

    -- Play
    vlc.playlist.clear()
    vlc.playlist.add()
    vlc.playlist.play()
end

function deactivate()
end

function close()
    vlc.deactivate()
end