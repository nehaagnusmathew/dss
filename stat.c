#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
void main()
{
 char*path,path1[10];
 struct stat*nfile;
 nfile=(struct stat*)malloc(sizeof(struct stat));
 printf("Enter the filename: ");
 scanf("%s",path1);
 stat (path1,nfile );
 printf("UserID:%d\n",nfile->st_uid);
 printf("Blocksize:%ld\n" , nfile->st_blksize);
 printf("Last access time:%ld\n",nfile->st_atime);
 printf("Last modification time :%ld\n",nfile->st_mtime);
 printf("Production mode :%d\n",nfile->st_mode);
 printf("Size of the file :%ld\n",nfile->st_size);
 printf("Number of links :%ld\n",nfile->st_nlink);
 }
