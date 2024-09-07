#include<stdio.h> 
int front=-1,rear=-1,m,i,item;
int a[20];
void enqueue();
void dequeue();
void display();
void main()
{
int n;
printf("Enter the size of queue: ");
scanf("%d",&m);
do
{
printf("Enter your choice: ");
printf("1.Enqueue\n");
printf("2.Dequeue\n");
printf("3.Display\n");
printf("4.Exit\n");
scanf("%d",&n);
switch(n)
{
case 1:enqueue();
break;
case 2:dequeue();
break;
case 3:display();
break;
case 4:printf("Exiting..\n");
break;
default:printf("enter a valid option:");
}}
while(n!=4);
}

void enqueue(){
if(front==(rear+1)%m)
{
printf("Overflow Error");
}
else if(front==-1&&rear==-1)
{

front++;
rear++;
printf("Enter the value:");
scanf("%d",&a[rear]);
}
else{
rear=(rear+1)%m;
printf("Enter the value:");
scanf("%d",&a[rear]);
}
}
void dequeue(){
if (front==-1&&rear==-1){
printf("Underflow error");
} else if(front==rear)
{
item=a[front];
front=-1;
rear=-1;
}
else
{
printf("Deleted value is %d\n",a[front]);
front=(front+1)%m;
}
}
void display(){
if (front==-1&&rear==-1){
printf("Queue Empty \n");
}else{
printf("The Queue is:");
for(i=front;i<=rear;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
}
}

