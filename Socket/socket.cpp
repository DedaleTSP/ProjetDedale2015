#include "socket.h"

using namespace std;

Socket::Socket(std::string myIP, std::string ip, int port)
{
	const char * ipc = ip.c_str();
	s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
	socketMe.sin_family = AF_INET;
	socketMe.sin_port = htons(port);
	socketMe.sin_addr.s_addr = htonl(INADDR_ANY);

	socketOther.sin_family = AF_INET;
	socketOther.sin_port = htons(port);
	inet_pton(AF_INET, ipc, &socketOther.sin_addr);
}
void Socket::Connect()
{

}
void Socket::Close() 
{
	close(s);
}
std::string Socket::Listen()
{
	recvfrom(s, buf, BUFFERLENGTH, 0, (struct sockaddr *)&socketOther, (socklen_t*)&slen);
	return buf;
}

void Socket::Send(std::string message)
{
	sprintf(buf, "%s", message.c_str());
	sendto(s, buf, BUFFERLENGTH, 0, (struct sockaddr *)&socketOther, (socklen_t)slen);
}
