#include<stdio.h>
int main()
{
int i,n;
float avgw=0,avgt=0;
printf("Enter the number of processes: ");
scanf("%d",&n);
int btime[n];
printf("Enter the burst time of the processes: ");
for(i=1;i<=n;i++)
{
 printf("Process %d:",i);
 scanf("%d",&btime[i]);
 }
 int wtime[n];
 int ttime[n];
 wtime[1]=0;
 for(i=2;i<=n;i++)
 {
 wtime[i]=wtime[i-1]+btime[i-1];
 avgw=avgw+wtime[i];
 }
 for(i=1;i<=n;i++)
 {
 ttime[i]=btime[i]+wtime[i];
 avgt=avgt+ttime[i];
 }
 printf("\nProcess ID      Burst Time      Waiting Time      Turnaround Time\n");
 for(i=1;i<=n;i++)
 {
  printf("%d\t\t\t%d\t\t%d\t\t%d\t\t\n",i,btime[i],wtime[i],ttime[i]);
  }
  printf("\n---------------------------------------------------------------------------------------\n");
  printf("The average waiting time=%f\n",avgw/n);
  printf("The average turnaround timr=%f\n",avgt/n);
  int temp=0;
  printf("\n----------------------------------------------------------------------------------------\n");
  printf("Gantt chart\n\t");
  for(i=1;i<=n;i++)
  {
   printf(" P[%d]\t",i);
   }
   printf("\n");
   printf("-----------------------------------------------------------------------------------------\n");
   for(i=1;i<=n;i++)
   {
   printf("\t%d",temp);
   temp=temp+btime[i];
   }
   printf("\n");
   return 0;
   }
