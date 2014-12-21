#include <stdio.h>
#include <stdlib.h>
void sig_proccess(int signo){
	printf("catch a exit signal!\n");
	exit(1);
}
void sig_pipe(int sign){
	printf("catch a SIGPIPE signal\n");
}
void proccess_conn_server(int s){
	ssize_t size = 0;
	char buffer[1024];
	for(;;){
		size = recv(s,buffer,1024,0);
		if(size == 0){
			return;
		}
		
		sprintf(buffer,"%d bytes altogether\n",size);
		send(s,buffer,strlen(buffer)+1,0);
	}
	close(s);
}
void proccess_conn_client(int s){
	ssize_t size = 0;
	char buffer[1024];
	for(;;){
		size = read(0,buffer,1024);
		if(size > 0){
			send(s,buffer,size,0);
			size = recv(s,buffer,1024,0);
			write(1,buffer,size);
		}
	}
	close(s);
}
