#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <string>
#include <iostream>

#define BUFFERLENGTH 100

class Socket

{
	private:
		struct sockaddr_in socketMe, socketOther;
		int s, i, slen=sizeof(socketOther);
		char buf[BUFFERLENGTH];		
	public:
		Socket(std::string myIP, std::string ip, int port);
		
		void Connect();
		void Close();
		void Listen();
		void Send(std::string message);

};

int main()
{
	return 0;
}
