#include "stdio.h"
#include "arpa/inet.h"
#include "sys/socket.h"
#include "string.h"
#include "unistd.h"
#include "sys/types.h"
int main(int argc,char *argv[])
{
	int sock_fd  = socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(9000);
//	server_addr.sin_addr.s_addr ="192.168.1.2";
	inet_pton(AF_INET,"192.168.50.66",&server_addr.sin_addr.s_addr);
	if(sock_fd<0)
		perror("");
	while(1)
	{
		char buf[128]="";
		fgets(buf,sizeof(buf),stdin);
		buf[strlen(buf)-1]=0;
		sendto(sock_fd,buf,strlen(buf),0,(struct sockaddr*) &server_addr,sizeof(server_addr));
		char read_buf[128]="";
		recvfrom(sock_fd,read_buf,sizeof(read_buf),0,NULL,NULL);
		printf("%s\n",read_buf);
	}
	return 0;
}
