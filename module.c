#include<stdio.h>
int a,b;
void add()
{
printf("\nEnter the two numbers to be added\n");
scanf("%d %d",&a,&b);
printf("The result is a+b= %d\n",a+b);
}
void sub()
{
printf("\nEnter the two numbers to be subtracted\n");
scanf("%d %d",&a,&b);
printf("The result is a-b= %d\n",a-b);
}
void mul()
{
printf("\nEnter the two numbers to be Multiply\n");
scanf("%d %d",&a,&b);
printf("The result is a*b= %d\n",a*b);
}
void division()
{
printf("\nEnter the two numbers to find division\n");
scanf("%d %d",&a,&b);
printf("The result is a/b= %d\n",a/b);
}
