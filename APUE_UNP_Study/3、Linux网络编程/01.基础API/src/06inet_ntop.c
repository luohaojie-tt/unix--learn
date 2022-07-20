#include "stdio.h"
#include "arpa/inet.h"
int main(int argc,char *argv[])
{
	char buf_ip[]="192.168.1.2";
	int num=0;
	inet_pton(AF_INET,buf_ip,&num);
	unsigned char *p = (char *)&num;

	char ip[INET_ADDRSTRLEN]="";
	inet_ntop(AF_INET,&num,ip,INET_ADDRSTRLEN);
	printf("ip=%s\n",ip);
	return 0;
}
