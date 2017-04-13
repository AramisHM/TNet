//				  07/08/2015
// TinyEnet - Minimalistic Networking engine
// Wrapper for ENet Networking Engine
// Copyright (c) 2015 Aramis Hornung Moraes
//
//

#include "TClient.h"
#include <string.h>
TNETClient::TNETClient(int port, char * server_ip) {
	// b. Create a host using enet_host_create
	client = 0;
	client = enet_host_create(NULL, 1, 2, 57600/8, 14400/8);

	if (client == NULL) {
		printf("TNETClient> An error occured while trying to create an ENet server host\n\n");
	}
	/*
	enet_address_set_host(&address, server_ip);
	address.port = port;

	// c. Connect and user service
	peer = enet_host_connect(client, &address, 2, 0);

	if (peer == NULL) {
		printf("TNETClient> No available peers for initializing an ENet connection\n\n");
		exit(EXIT_FAILURE);
	}
	*/
}

TNETClient::~TNETClient()
{
	enet_host_destroy(client);
}

int TNETClient::update(int uSecs)
{
	if (enet_host_service(client, &event, uSecs) > 0) {
		switch(event.type) {
			case ENET_EVENT_TYPE_RECEIVE:
				//printf("(Client) Message from server : %s\n", event.packet->data);
				// Lets broadcast this message to all
				// enet_host_broadcast(client, 0, event.packet);
				enet_packet_destroy(event.packet);
				return 1;
				break;

			case ENET_EVENT_TYPE_CONNECT:
				//printf("(Client) We got a new connection from %x\n",event.peer->address.host);
				return 2;
				break;

			case ENET_EVENT_TYPE_DISCONNECT:
				//printf("(Client) %s disconnected.\n", event.peer->data);
				// Reset client's information
				event.peer->data = NULL;
				return 3;
				break;
		}
	}
}

int TNETClient::send_peer(char* message, int len)
{
	//printf("Say > ");
	//gets(message);
	if(!len)
		len = strlen(message);
	if (strlen(message) > 0 || len > 0) {
		ENetPacket *packet = enet_packet_create(message, len + 1, ENET_PACKET_FLAG_RELIABLE);
		return enet_peer_send(peer, 0, packet);
	}
	return 0;
}

int TNETClient::send(char* message, int port, char *ip, int len)
{
	ENetAddress taddress;
   // ENetHost *tclient;
    //ENetPeer *tpeer;
    ENetEvent tevent;
	enet_host_service (client, & event, 10); // process any previous message.
    /*tclient = enet_host_create(NULL, 1, 2, 57600/8, 14400/8);

    if (tclient == NULL) {
        fprintf(stderr, "An error occured while trying to create an ENet server host\n");
		enet_host_destroy(tclient);
        return 0;
    }*/
    enet_address_set_host(&taddress, ip);
    taddress.port = port;

    // c. Connect and user service
    peer = enet_host_connect(client, &taddress, 2, 0);
    if (peer == NULL) {
        printf("No available peers for initializing an ENet connection");
		//enet_peer_reset(peer);
        //enet_host_destroy(client);
        return 0;
    }
    //enet_host_service(client, &tevent, 100);
	
	// If we had some event that interested us
	if (enet_host_service(client, &tevent, 128) > 0) {
		if(tevent.type == ENET_EVENT_TYPE_CONNECT)
		{
			if (len > 0) {
				ENetPacket *packet = enet_packet_create(message, strlen(message) + 1, ENET_PACKET_FLAG_RELIABLE);
				//printf("seding message...\n");
				enet_peer_send(peer, 0, packet);
				enet_host_service(client, &tevent, 0);
				//enet_peer_reset(peer);

				//enet_host_destroy(client);


				// DISCONNECT THE DAMN PEER U GOOF
				printf("Sending disconnect packet.\n");
				enet_peer_disconnect (peer, 0);
				/* Allow up to 3 seconds for the disconnect to succeed
				 * and drop any packets received packets.
				 */
				enet_host_service (client, & tevent, 10);
				enet_peer_reset (peer);
				printf("Message sendm peed disconnected..\n");
				return 1;
					/*
				while (enet_host_service (client, & event, 10) > 0)
				{
					switch (event.type)
					{
					case ENET_EVENT_TYPE_RECEIVE:
						enet_packet_destroy (event.packet);
						break;
					case ENET_EVENT_TYPE_DISCONNECT:
						puts ("Disconnection succeeded.\n"); // Debug message TODO: hide later
						return 1;
					}
				}
				/* We've arrived here, so the disconnect attempt didn't */
				/* succeed yet.  Force the connection down.             */
				
				//enet_peer_reset (peer);
			}	
			
		}
	}
	else
	{
		printf("send [error]> Couldn't communicate with destination.\n");
		enet_host_service(client, &tevent, 0);
	}
	enet_peer_reset(peer);
	return 0;
}
