var net = require('net');
var http = require('http');
var fs = require('fs');


http.createServer(function (req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    var fileStream = fs.createReadStream("views/index.html");
    fileStream.on('data', function (data) {
        res.write(data);
    });
    fileStream.on('end', function() {
        res.end();
    });
}).listen(1337, '127.0.0.1');
console.log('Server running at http://127.0.0.1:1337/');

var server = net.createServer(function (socket) {
    socket.write('Echo server\r\n');
    socket.pipe(socket);
});

server.listen(8081, '127.0.0.1');

