$( function() {

    var sessions = {};
    var socket = io.connect("http://"+window.location.hostname);
    socket.on('connect', function(data){
	for(var i=0,max=data.length; i<max ;i++){
	    sessions[i] = data[i];
	    $("#session").append("<div class='inactive'>"+data[i]+"</div>");
	}
    });

    function connect(url){
	session = io.connect("http://"+window.location.hostname+"/"+sessions[url]);
	session.on('connect', function(data) {
	   
	});
    }
//events
    var flag = 0;
    var action = [];
    var element = document.getElementById('session');
    var trigger = document.getElementById('container');
    element.addEventListener("click",function(e){
	var el = ;
	el.classList.remove();
	el.classList.add();
	connect(el.val());
    });
    trigger.addEventListener("click",function(e){
	action.push(el.val());
	session.emit(action);
    });
});