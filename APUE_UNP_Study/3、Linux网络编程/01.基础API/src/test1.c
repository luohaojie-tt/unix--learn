#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // int argc = 1;
    // char* argv[10];
    /* if( argc >= 2 )
     {
       //  printf( "usage: %s ip_address port_number\n", basename( argv[0] ) );
           printf("argc is %d\n",argc);
         return 1;
     }
     */
    const char *ip = argv[1];
    int port = atoi(argv[2]);
    printf("%s", ip);
    printf("11111");
    printf("%d", port);
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    printf("%d", address.sin_family);
    //本机ip：183.230.177.205
    inet_pton( AF_INET, "127.0.0.1", &address.sin_addr );
    printf("%s  \n",inet_ntoa(address.sin_addr));
    // printf("%s",address.sin_addr); 20001
     address.sin_port = htons( 6666 );
     printf("%d\n",address.sin_port);

    int sock = socket( PF_INET, SOCK_STREAM, 0 );
    printf("%d\n",sock);
     assert( sock >= 0 );   //判断函数，条件为真，则程序没有出错，继续执行，反之条件为假，程序停止执行，提示错误
     printf("start\n");

      int ret = bind( sock, ( struct sockaddr* )&address, sizeof( address ) );
      printf("%d\n",ret);
    //assert( ret != -1 );
     printf("counti\n");

     ret = listen( sock, 5 );
     printf("%d\n",ret);
   assert( ret != -1 );

      struct sockaddr_in client;
     socklen_t client_addrlength = sizeof( client );
     printf("%d\n",client_addrlength);
      int connfd = accept( sock, ( struct sockaddr* )&client, &client_addrlength );
      printf("%d\n",connfd);
    /* if ( connfd < 0 )
     {
         printf( "errno is: %d\n", errno );
     printf("在执行if里面的内容  connfd is %d",connfd);
     }
     else
     {
         close( STDOUT_FILENO );
         dup( connfd );
         printf( "abcd\n" );
         close( connfd );
     }

     close( sock );
     */
    return 0;
}
