#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(int argc, char **argv)
{
	int server_socket;
	int client_socket;
	int connection_status;
	char buff[256] = "Tring Ping Tring Ping";
	struct sockaddr_in server_address;

	//create socket
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	//define the server address
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(4500);
	server_address.sin_addr.s_addr = INADDR_ANY;

	//bind socket to specified IP and Port
	bind(server_socket, (struct sock_addr *) &server_address, sizeof(server_address));

	//listen for connection
	listen(server_socket,1); //1 because only one client can make connection

	//accept for connection
	client_socket = accept(server_socket, NULL, NULL);

	//send the data
	send(client_socket, buff, sizeof(buff), 0);
	printf("[INFO] Data sent to client.\n");

	//close socket
	close(server_socket);

	return 0;
}
