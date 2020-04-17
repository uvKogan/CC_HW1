// Authors - Maor Naftali (ID #########) and Yuval Kogan (ID 310596424)
// Project - DNS Client
// Description - functions inplementation file of the DNS Client 

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

int CheckValidInput(const char *input_string) { // TODO - expend to more cefisticated checks?
	int dot = 0;
	char *invalid_char = "!@#$%^&*()_+<>\\?:\"[]|';,";
	for (int i = 0; i < strlen(input_string); i++) {
		for (int j = 0; j < strlen(invalid_char); j++) {
			if (input_string[i] == invalid_char[j]) {
				return 0; //invalid input
			}
		}
		if (dot == 1 && input_string[i] != '.') {
			dot = 0;
		}
		if (input_string[i] == '.' && dot == 0) {
			dot = 1;
		}
		else if (input_string[i] == '.' && dot == 1) {
			return 0; // two dots in a row (..)
		}
	}
	return 1; //valid input
};

int CheckIfQuit(const char *input_string) { // TODO - deal with shorter strings than quit
	char *is_quit = "quit";
	for (int i = 0; i < strlen(input_string); i++) {
		if (input_string[i] != is_quit[i]) {
			return 0; // not quit
		}
	}
	return 1; // all chars matches - quit
}

struct hostent GetHostByName1(const char *host_name) {
	WSADATA wsaData;
	int iResult;
	DWORD dwError;
	int i = 0;
	struct hostent *remoteHost;
	struct in_addr addr;
	char **pAlias;
	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
	}

	remoteHost = gethostbyname(host_name);
	if (remoteHost == NULL) {
		remoteHost = malloc(100 * sizeof(remoteHost));
		remoteHost->h_name = "NULL"; // cant return NULL structure, I decide how to check it. 
	}
	return *remoteHost;
};