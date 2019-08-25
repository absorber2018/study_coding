#include <stdio.h>
int flower(int t);
int main()
{int t,n;
for(t=100;t<=999;t++)
{n=flower(t);
if(n==1)
printf("%d   ",t);
}return(0);}

int flower(int t)
{int a,b,c,d,p;
a=t/100;
b=(t%100)/10;
c=t%10;
d=a*a*a+b*b*b+c*c*c;
if(d==t)
    p=1;
else p=0;
return p;}
