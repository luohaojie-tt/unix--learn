#include "stdio.h"
#include "arpa/inet.h"
int main(int argc,char *argv[])
{
	int num = 0x01020304;
	int sum = htonl(num);
	printf("%x\n",sum);
	int app = ntohl(sum);
	printf("%x\n",app);
	return 0;
}
