// Authors - Maor Naftali (ID 205882699) and Yuval Kogan (ID 310596424)
// Project - DNS Client
// Description - header file of the DNS Client - Declare global variables and functions

#ifndef SOCKET_EXAMPLE_CLIENT_H
struct hostent GetHostByName1(const char *host_name);
struct hostent dnsQuery(const char *input_address);
int CheckValidInput(const char *input_string);
int CheckIfQuit(const char *input_string);


//typedef struct hostent {
//	char  *h_name;
//	char  **h_aliases;
//	short h_addrtype;
//	short h_length;
//	char  **h_addr_list;
//} HOSTENT, *PHOSTENT, *LPHOSTENT;
#endif // SOCKET_EXAMPLE_CLIENT_H
