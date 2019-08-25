#include <stdio.h>
int max(int,int)
{int t,m,n;
while(n)
{t=m%n;
m=n;
n=t;
}
    return(m);}

int min (int,int,int)
{int m,n,a,i;
i=m*n/a;
return(i);}

int main()
{int m,n,dy,xb,a;
printf("please input two datas");
scanf("%d %d",&m,&n);
dy=max(m,n);
a=dy;
xb=min(m,n,a);
printf("max=%d,min=%d",dy,xb);

}
