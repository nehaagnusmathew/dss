#include<stdio.h>
void main()
{

int n,i,x,count=0,time=0,a[20];

time++;
time++;
printf("enter the number of elements in an array");
time++;
scanf("%d",&n);
time++;
printf("enter the elements of the array ");
time++;
for(i=0;i<n;i++)
{
 time++;
 scanf("%d",&a[i]);
 time++;
}
time++;
printf("enter the element to be searched");
time++;
scanf("%d",&x);
time++;
for(i=0;i<n;i++)
{
 time++;
 if(a[i]==x)
 
 {
 time++;
 count++;
 printf("the element is found at location %d\n",i+1);
 time++;
 
 }
 
}
time++;
if(count>0)
{
time++;
printf("the element is found %d times\n",count);
time++;
}
else
{
time++;
printf("the item not found");
time++;
}


printf("space complexity=%d \n",((5*4)+(n*4)));
time++;
time++;
printf("time complexity=%d",time);

}
