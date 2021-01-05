import * as Net from "net";

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

function connectionListener(socket:Net.Socket):void
{
	socket.write('Echo server. Welcome!\r\n');

	function incomingDataListener (data:Buffer):void
	{
		socket.write(respond(data.toString()));
	}

	socket.on ('data',incomingDataListener);

}

let server:Net.Server = Net.createServer(connectionListener);

server.listen(1337, '127.0.0.1');