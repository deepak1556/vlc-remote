
function descriptor()
    return { title = "Remote Control For VLC" ;
             version = "0.1" ;
             author = "Robo" ;
             capabilities = {} }
end

function activate()
    local host, port = "localhost", 8081
    local socket = require("socket")
    local tcp = assert(socket.tcp())
    tcp:connect(host,port)
    tcp:send("hello world\n")
    local val = tcp:receive()
end

function action()
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