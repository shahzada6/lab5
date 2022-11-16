#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h> 
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
extern int errno; 
int main(int argc, const char *argv[]){
int fd = access("task2.cpp", F_OK);
if(fd == -1){
printf("Error Number:%d\n",errno);
perror("Error Description:");
}
else
printf("No error\n");
return 0;
}
