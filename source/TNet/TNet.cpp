#include "TNet.h"

// Always call this before doing anything with the enigne.
int startTNetEngine()
{
	// a. Initialize enet
	if (enet_initialize() != 0) {
		printf("An error occured while initializing ENet.\n");
		exit(EXIT_FAILURE);
	}
	printf("             07.08.2015\nTNet - Tiny Networking Engine\nA wrapper for the ENet Networking Engine\nCopyright (c) 2015 Aramis Hornung Moraes\n\n");
	atexit(enet_deinitialize);
	return 0;
}

// Call this to stop the engine
int stopTNetEngine()
{
	enet_deinitialize();
	return 0;
}