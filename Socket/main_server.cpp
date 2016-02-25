#include "./socket.h"

using namespace std;

int main(void)
{	
	Socket* s = new Socket("192.168.43.142", "192.168.43.74", 6666);
	std::string out = s->Listen();
	printf("Data: %s\n", out.c_str());
	s->Close();
	return(0);
}

