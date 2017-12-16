#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int	main(void)
{
	// create a socket

	int network_socket;

	// first param is a domain, second type, thrird protocol
	// AF_INET - is IPv4 Internet protocol
	// SOCK_STREAM - provides two-way connection based byte streams

	network_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	// ensure that socket was created

	if (network_socket)
		printf("SOCKET_CREATED %d\n", network_socket);
	// specify an address for the socket

	struct sockaddr_in server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);

	server_address.sin_addr.s_addr = INADDR_ANY;

	// connection to a socket
	// first parameter is an actual socket

	int connection_status;
	
	connection_status =  connect(network_socket, (struct sockaddr *)(&server_address), sizeof(server_address));	

	if (connection_status)
		printf("CONNECTION_ESTABLISHED = %d\n", connection_status);

	// recieve information from server

	char server_response[256];

	recv(network_socket, &server_response, sizeof(server_response), 0);

	// print the data we get from server

	printf("DATA_FORM_SERVER: %s\n", server_response);

	// close the socket

	close(network_socket);
	return (0);
}
