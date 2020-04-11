// Authors - Maor Naftali (ID #########) and Yuval Kogan (ID 310596424)
// Project - DNS Client
// Description - main file of the DNS Client - include headers and call main functions

// Project Includes

#include "DNSClient.h"
//#include "Functions.c"
// Library Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Project Includes
#include "Defines.h"

// gethostbyname example includes
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")


// Description - main function the DNS Client - user interface
// Parameters - receives as a parameter ServerIp, ServerPort 
// Returns - 0 if succesful, error code otherwise
int main(int argc, char *argv[]) {
	if (argc < NUM_OF_INPUT_ARGUMENTS) { return ERR_CODE_NOT_ENOUGH_ARGUMENTS; };
	if (argc > NUM_OF_INPUT_ARGUMENTS) { return ERR_CODE_TOO_MANY_ARGUMENTS; };
	printf("Hello World!\n");
	int sum;
	int two = 2;
	sum = two + two;
	printf("2+2=%d\n", sum);

	// gethostbyname example
	char *host_name;
	host_name = argv[1];
	int host_answer;
	host_answer = GetHostByName1(host_name);
	return host_answer; // 0 if successful
};

