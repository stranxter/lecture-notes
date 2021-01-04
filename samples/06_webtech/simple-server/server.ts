import * as net from "net";


function respond(command:string):string
{
	if (command=='sayhello\r\n')
	{
		return 'Hello!\r\n';
	} else
	{
		return 'Sorry. Don\'t know this command: ' + command;
	}
}

function connectionListener(socket:net.Socket):void
{
	socket.write('Echo server. Welcome!\r\n');
	socket.on ('data',function (data:Buffer){socket.write(respond(data.toString()));});

}

let server:net.Server = net.createServer(connectionListener);

server.listen(1337, '127.0.0.1');