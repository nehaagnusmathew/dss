#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main(){
char*args[]={"./exec",NULL};
execvp(args[0],args);
printf("\n End");
}
