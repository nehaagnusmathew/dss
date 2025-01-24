#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{
pid_t childpid=fork();
if(childpid==0)
{
 printf("Iam child and child created successfully\n");
 printf("Child process ID=%d\n",getpid());
 printf("Parent process ID =%d\n",getppid());
 }
 else if(childpid>0)
 {
 printf("Iam parent and child created successfully \n");
 printf("Parent process ID =%d \n",getpid());
 printf("Child process ID = %d\n ",childpid);
 wait(NULL);
 printf("Parent process terminated and child process is running \n");
 }
 else if(childpid<0)
 {
 printf("Child creation is unsuccessfull \n");
 }
 exit(0);
 }
