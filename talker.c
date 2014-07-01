#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>                                                                              
#define PORT      5000
#define LENGTH    512                                                                               
int main(int argc,char *argv[])
{  int sockfd;
   int num;
   char sdbuf[LENGTH];
   struct sockaddr_in addr_remote;
   char sdstr[]={"MagicARM2410 UDP Experiment."}                                                                       
   if(argc!=2)
   {
     printf("Usage:talker HOST IP(ex:/talker 192.168.0.94).\n");
     return (0);
   }
   if((sockfd=socket(AF_INET,SOCK_DGRAM,0))==-1)
   {
     printf("ERROR:Failed to obtain Socket Descriptor!\n");
     return(0);
   }
    addr_remote.sin_family=AF_INET;
    addr_remote.sin_port=htons(PORT);
    inet_pton(AF_INET,argv[1],&addr_remote.sin_addr);
    bzero(&(addr_remote.sin_zero),8);                                                                              
    bzero(sdbuf,LENGTH);
    num=sendto(sockfd,sdstr,strlen(sdstr),0,(struct sockaddr*)&addr_remote,sizeof(struct sockaddr_in));
    if(num<0)
    {
      printf("ERROR:Failed to send your data!\n",argv[1],num);
    }
   else
   { 
     printf("OK:Sent to %s total %d bytes!\n",argv[1],num);
   }                                                                            
   close(sockfd);
   return(0);
}
