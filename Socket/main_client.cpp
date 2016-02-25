#include "./socket.h"

using namespace std;

int main(void)
{	
	Socket* s = new Socket("192.168.43.74", "192.168.43.142", 6666);
	s->Send("This is a test");
	s->Close();
	return(0);
}

