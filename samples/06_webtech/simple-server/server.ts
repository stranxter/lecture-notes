import * as Net from "net";

function respond(command:string):string
{
	if (command=='sayhello\n')
	{
		return 'Hello!\n';
	} else if (command =='howareyou\n')
	{
		return 'Very well, thank you!\n';
	}
	else
	{
		return 'Sorry. Don\'t know this command: ' + command;
	}
}

let clientsCounter:number = 0;

function connectionListener(socket:Net.Socket):void
{
	clientsCounter++;
	let clientNumber:number = clientsCounter;
	
	console.log("Connection established. Clients so far: " + clientsCounter);
	socket.write('Echo server. Welcome!\n');
	
	socket.on('data',
		      (data:Buffer):void => 
				       {socket.write('[' + clientNumber + ']' +
				                     respond(data.toString()));});
}

let server:Net.Server = Net.createServer(connectionListener);
server.listen(1337);