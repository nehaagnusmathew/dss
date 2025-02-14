#include <stdio.h>
void main(){
int i,j,n;
printf("Enter Number of Processes:");
scanf("%d",&n);
float bt[n],wt[n],tt[n];
printf("\nEnter the process details:");
for(i=0;i<n;i++){
printf("\nP%d Burst Time:", i+1);
scanf("%f",&bt[i]);
}
float avg_wt=0,avg_tt=0;
for(i=0;i<n;i++){
wt[i]=wt[i-1]+bt[i-1];
avg_wt+=wt[i];
}
avg_wt/=n;
for(i=0;i<n;i++){
tt[i]=bt[i]+wt[i];
avg_tt+=tt[i];
}
avg_tt/=n;
printf("\nProcess \tBurst Time\tWaiting Time\tTurn Around Time");
for(i=0;i<n;i++){
printf("\nP%d \t\t%.2f\t\t%.2f\t\t%.2f",i+1,bt[i],wt[i],tt[i]);
}
printf("\nAverage Waiting time = %f",avg_wt);
printf("\nAverage Turn Around time = %f\n",avg_tt);
for(i=0;i<n;i++){
printf("-------");
}
printf("\n");
for(i=0;i<n;i++){
printf("|  P%d  ",i+1);
}
printf("|");
printf("\n");
for(i=0;i<n;i++){
printf("-------");
}
printf("\n");
int time=0;
for(i=0;i<n+1;i++){
printf("%d     ",time);
time+=bt[i];
}
}
