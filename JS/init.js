new QWebChannel(qt.webChannelTransport,
    function(channel){
        window.hover_handler = channel.objects.hover_handler;
    });