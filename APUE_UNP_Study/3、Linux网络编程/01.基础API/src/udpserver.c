#include "stdio.h"
#include "arpa/inet.h"
#include "sys/socket.h"
int main(int argc, char const *argv[])
{
    /* code */
    //创建socket
    int sock_fd = socket(AF_INET,SOCK_DGRAM,0);
    if (sock_fd < 0)
    {
        perror("error");
    }
    //绑定
    struct sockaddr_in addr;//创建结构体
    addr.sin_family = AF_INET;//配置协议  ipv4
    addr.sin_port = htons(9000);//配置端口
    // inet_pton(AF_INET,"192.168.1.2",&addr.sin_addr.s_addr);
    addr.sin_addr.s_addr=0;//通配地址


    int ret = bind(sock_fd,(struct sockaddr*)&addr,sizeof(addr));
    if(ret<0)
        perror("");
        struct sockaddr_in cli_addr;
        socklen_t len = sizeof(cli_addr);
    while (1)
    {
        char buf[128]="";
        int n = recvfrom(sock_fd,buf,sizeof(buf),0,(struct sockaddr*)&cli_addr,&len);
        printf("%s\n",buf);
        sendto(sock_fd,buf,n,0,(struct sockaddr*)&cli_addr,sizeof(cli_addr));
    }
    // pclose(sock_fd);
    return 0;
}

