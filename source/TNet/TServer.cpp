//				  07/08/2015
// TinyEnet - Minimalistic Networking engine
// Wrapper for ENet Networking Engine
// Copyright (c) 2015 Aramis Hornung Moraes
//
//

#include "TServer.h"



void create_stack(Stack *S)
{
    S->size = 0;
}
void *stack_top(Stack *S)
{
    if (S->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return 0;
    } 

    return S->data[S->size-1];
}
int stack_push(Stack *S, void *d)
{
    if (S->size < TSTACK_MAX)
	{
        S->data[S->size++] = d;
		return 1;
	}
    else
        fprintf(stderr, "Error: stack full\n");
	return 0;
}
void *stack_pop(Stack *S)
{
    if (S->size == 0)
	{
        fprintf(stderr, "Error: stack empty\n");
		return 0;
	}
    else
	{
		S->size--;
		return S->data[S->size];
	//	free(S->data[S->size-1]);
        
	}
}

TNETServer::TNETServer(int port)
{
	// b. Create a host using enet_host_create
	address.host = ENET_HOST_ANY;
	address.port = port;

	server = enet_host_create(&address, 255, 2, 0, 0);

	if (server == NULL) {
		printf("TNETServer> An error occured while trying to create an ENet server host\n\n");
		exit(EXIT_FAILURE);
	}
	// c. Connect and user service
	eventStatus = 1;

	create_stack(&message_stack);

	printf("TNETServer [STATUS]> Server running, port: %d\n\n", port);
	
}
TNETServer::~TNETServer()
{
	enet_host_destroy(server);
}

int TNETServer::update(int uSecs)
{
	// c. Connect and user service
	if (1) {
		eventStatus = enet_host_service(server, &enet_event, uSecs);
		// If we had some enet_event that interested us
		while (eventStatus > 0 ) {
			switch(enet_event.type) {
			case ENET_EVENT_TYPE_CONNECT:
				eventStatus = enet_host_service(server, &enet_event, uSecs);
					//printf("(Server) We got a new connection from %x\n", enet_event.peer->address.host);
				if(enet_event.type == ENET_EVENT_TYPE_RECEIVE)
					return 1;
				else
					return 2;
					break;

				case ENET_EVENT_TYPE_RECEIVE:
					//printf("(Server) Message from client : %s\n", enet_event.packet->data);
					// Lets broadcast this message to all
					//enet_host_broadcast(server, 0, enet_event.packet);
					return 1;
					break;

				case ENET_EVENT_TYPE_DISCONNECT:
					//printf("%s disconnected.\n", enet_event.peer->data);
					// Reset client's information
					enet_event.peer->data=NULL;
					return 3;
					//break;
			}
		}
	}
	return 0;
}

// WARWNING! DO NOT modify this variable directly, dont forget to
// make a copy of this variable, this is a direct reference to the
// message data packat.
char* TNETServer::getMessage()
{
	return (char*)enet_event.packet->data;
}

TPacket TNETServer::getPacket()
{
	TPacket packet;
	t_packet pckt;
	pckt.event = enet_event;
	packet.setPacket(pckt);
	return packet;
}

void TNETServer::setPacket(TPacket pckt)
{
	// it may be confusing, but we are interested in the event here,
	// since enet suport event. Remember, this is a wrapper, it is
	// supposed  to support other engines, that dont work with Events
	// but packets.
	enet_event = pckt.getPacket().event;
}

int TNETServer::stackPushMessage(char *msg)
{
	return stack_push(&message_stack, msg);
}

void* TNETServer::stackPopMessage()
{
	return stack_pop(&message_stack);
}

int TNETServer::stackSize()
{
	return message_stack.size;
}

void *TNETServer::stackHead()
{
	return stack_top(&message_stack);
}
