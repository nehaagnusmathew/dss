#include<stdio.h>
void main(){
int n,i,j,temp,time=0;
printf("Enter the number of processes: ");
scanf("%d",&n);
int btime[n],wtime[n],ttime[n],p[n];
for(i=0;i<n;i++)
{
p[i]=i+1;
printf("Enter the burst time for P%d: ",p[i]);
scanf("%d",&btime[i]);
}
float avg_wtime=0,avg_ttime=0;
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(btime[i]>btime[j]){
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
wtime[0]=0;
for(i=1;i<n;i++)
{
wtime[i]=wtime[i-1]+btime[i-1];
avg_wtime+=wtime[i];
}
avg_wtime/=n;
for(i=0;i<n;i++)
{
ttime[i]=wtime[i]+btime[i];
avg_ttime+=ttime[i];
}
avg_ttime/=n;
printf("\nP\tBursttime\tWaitingtime\tTurnaroundtime");
for(i=0;i<n;i++){
printf("\nP%d\t\t%d\t\t%d\t\t%d",p[i],btime[i],wtime[i],ttime[i]);
}
printf("\nAverage waiting time =%f",avg_wtime);
printf("\nAverage turn around time=%f",avg_ttime);
printf("\n\nGantt chart:\n");
for(i=0;i<n;i++)
printf("-------------------------------");
printf("\n|");
for(i=0;i<n;i++)
printf("P%d   |\t",p[i]);
printf("\n");
for(i=0;i<n;i++)
printf("-------------------------------");
printf("\n0\t");
for(i=0;i<n;i++){
time+=btime[i];
printf("%d\t",time);
}
}


