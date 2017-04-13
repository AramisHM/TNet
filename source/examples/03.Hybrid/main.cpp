//				  07/08/2015
// TinyEnet - Minimalistic Networking engine
// Wrapper for ENet Networking Engine
// Copyright (c) 2015 Aramis Hornung Moraes
//
//

#include "TNet.h"
#include <string.h>

// Little example
int main(int argc, char **argv)
{
	int my_port, remote_port;
	char profile;
	char remote_ip[17];
	char my_message[1024];
	remote_ip[16]=0;

	// start the engine
	startTNetEngine();

	// gather info about the network
	printf("Choose profile client[c] or server [s]: "); fflush(stdin); scanf("%c", &profile);

	while(1)
	{
		if(profile == 's')
		{
			printf("My port: "); fflush(stdin); scanf("%d", &my_port);
			TNETServer serv = TNETServer(my_port);
			
			while(1){
				if(serv.update(1)== TEE_MESSAGE)
				{
					printf("[%s]>: %s\n", serv.getPacket().getSenderIP(), serv.getMessage());
				}
			}
		}
		else if(profile == 'c')
		{
			printf("Host ip : "); fflush(stdin); scanf("%s", &remote_ip);
			printf("Host port : "); fflush(stdin); scanf("%d", &remote_port);
			TNETClient clinet = TNETClient(remote_port, remote_ip);
			while(1){
				printf("Sayt> "); fflush(stdin); scanf("%s",&my_message);
				//clinet.send_peer(my_message);
				clinet.send(my_message, remote_port, remote_ip, strlen(my_message));
			}
			break;
		}
		else
		{
			printf("EXIT\n");
			break;
		}
	}
	return 0;
}