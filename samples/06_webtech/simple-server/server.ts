import * as Net from "net";

function respond(command:string):string
{
	if (command=='sayhello\n')
	{
		return 'Hello!\n';
	} else
	{
		return 'Sorry. Don\'t know this command: ' + command;
	}
}

let clientsCounter:number = 0;

function connectionListener(socket:Net.Socket):void
{
	clientsCounter++;
	console.log("Connection established. Clients so far: " + clientsCounter);

	
	socket.write('Echo server. Welcome!\n');
	let clientNumber:number = clientsCounter;

	function incomingDataListener (data:Buffer):void
	{
		
		socket.write('[' + clientNumber + ']' + respond(data.toString()));
	}

	socket.on('data',incomingDataListener);

}

let server:Net.Server = Net.createServer(connectionListener);

server.listen(1337);