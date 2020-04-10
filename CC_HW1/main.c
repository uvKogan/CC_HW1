// Authors - Maor Naftali (ID #########) and Yuval Kogan (ID 310596424)
// Project - DNS Client
// Description - main file of the DNS Client - include headers and call main functions

// Library Includes
#include <stdio.h>
#include <string.h>
// Project Includes
#include "Defines.h"
#include "DNSClient.h"

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
};