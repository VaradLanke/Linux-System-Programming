/*
**	Client Socket Program
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //socket apis
#include <sys/types.h> // types
#include <netinet/in.h> // nw structs


int main(int argc, char **argv)
{
	int network_socket;
	int connection_status;
	char buff[256];
	struct sockaddr_in server_address;

	//create socket
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	//specify an address for socket
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(4500);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// connect with server
	connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	if(connection_status == -1)
	{
		printf("[ERROR] Connection failed with server..!\n");
		close(network_socket);
		return -1;
	}

	printf("[INFO] Connection Established.\n");

	//receive data from server
	recv(network_socket, &buff, sizeof(buff), 0);
	printf("[INFO] Data from server : \n %s\n", buff);

	//close socket
	close(network_socket);

	return 0;
}
