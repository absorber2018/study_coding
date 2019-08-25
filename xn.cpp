#include <stdio.h>
int mul(int,int);
int main()
{int x,n,f;
printf("please input number and times");
scanf("%d %d",&x,&n);
f=mul(x,n);
printf("(%d,%d):f=%d",x,n,f);
}

int mul(int x,int n)
{int f,i=0;
if(i
{i++;
f=x*mul(x,n);
}
else
    return(f);

}
