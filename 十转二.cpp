#include <stdio.h>
int main()
{
int a,t[50],i,n=0,y;
printf("please input number");
scanf ("%d",&a);

while(a!=0)
{
y=a%2;
t[n]=y;
a=a/2;
n++;
}
for(i=n-1;i>=0;i--)
printf("%d",t[i]);
return 0;
}
