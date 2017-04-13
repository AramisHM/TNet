//				  07/08/2015
// TinyEnet - Minimalistic Networking engine
// Wrapper for ENet Networking Engine
// Copyright (c) 2015 Aramis Hornung Moraes
//


#include "TPacket.h"

t_packet TPacket::getPacket()
{
	return packet;
}
void TPacket::setPacket(t_packet packt) // Adapted for Enet only.
{
	packet = packt;
}

char* TPacket::getSenderIP() // Adapted for Enet only.
{
	
	enet_address_get_host_ip(&packet.event.peer->address,host_ip,16);
	host_ip[16] = 0;
	return host_ip;
}
