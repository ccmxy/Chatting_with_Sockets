#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
	//create a socket
	int network_socket;	
	//AF_INET = domain, sock_stream for TCP socket, protocol 0 for default
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	// specify address for socket:
	struct sockaddr_in server_address;
	//Set family of address:
	server_address.sin_family = AF_INET;
	//Set port:
	server_address.sin_port = htons(2077);
	//Specify ip address:
	server_address.sin_addr.s_addr = INADDR_ANY;
	

	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)); 
	//Error check connection
	if (connection_status == -1){
		printf("ERROR: Connection failed");
	}

	// receive data from the server
	char server_response[256];
	char client_msg[256] = "I'm enjoying myself";
	int quit = 0;
	send(network_socket, client_msg, sizeof(client_msg), 0);
	while(quit == 0){
		recv(network_socket, &server_response, sizeof(server_response), 0);
		// print out server's response:
		if (strcmp(server_response, "\\quit") == 0) {
			printf("Server Bob has closed this connection. Goodbye.\n");
			quit = 1;
			break;
		}
		printf("ServerBob> %s\n", server_response);
		//Prompt user:
		printf(" You: ");
		fgets(client_msg, 500, stdin);
		strtok(client_msg, "\n"); //Remove newline
		if (strcmp(client_msg, "\\quit") != 0) {
			printf("Waiting for response from server Bob...\n");
			send(network_socket, client_msg, sizeof(client_msg), 0);
		}
		else{
			printf("Closing connection");
			close(network_socket);
			quit = 1;
			break;
		}
	}
	//Close the socket
	close(network_socket);
	return 0;
}
