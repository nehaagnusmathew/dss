#include<stdio.h>
struct poly
{
int coeff;
int expo;
};
void main()
{
int n,i;
printf("enter the number of terms in polynomial:");
scanf("%d",&n);
struct poly A[n];
printf("enter the terms in polynomial\n");
for(i=0;i<n;i++)
{
printf("enter coefficient of term %d :",i+1);
scanf("%d",&A[i].coeff);
printf("enter exponent of term %d :",i+1);
scanf("%d",&A[i].expo);
}
printf("the polynomial expression is :\n");
for(i=0;i<n;i++)
{
if(i<n-1)
{
printf("(%dx^%d)+",A[i].coeff,A[i].expo);
}
else
{
printf("(%dx^%d)",A[i].coeff,A[i].expo);
}
}
}


