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


int GetHostByName1(const char *host_name) {

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
		return 1;
	}

	printf("Calling gethostbyname with %s\n", host_name);
	remoteHost = gethostbyname(host_name);
	if (remoteHost == NULL) {
		dwError = WSAGetLastError();
		if (dwError != 0) {
			if (dwError == WSAHOST_NOT_FOUND) {
				printf("Host not found\n");
				return 1;
			}
			else if (dwError == WSANO_DATA) {
				printf("No data record found\n");
				return 1;
			}
			else {
				printf("Function failed with error: %ld\n", dwError);
				return 1;
			}
		}
	}
	else {
		for (pAlias = remoteHost->h_aliases; *pAlias != 0; pAlias++) {
			printf("Alternate name #%d: %s\n", ++i, *pAlias);
		}

		i = 0;
		if (remoteHost->h_addrtype == AF_INET)
		{
			while (remoteHost->h_addr_list[i] != 0) {
				addr.s_addr = *(u_long *)remoteHost->h_addr_list[i++];
				printf("IP Address: %s\n", inet_ntoa(addr));
			}
		}
		else if (remoteHost->h_addrtype == AF_NETBIOS)
		{
			printf("NETBIOS address was returned\n");
		}
	}

	return 0;
};