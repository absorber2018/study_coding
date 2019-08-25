
#include <stdio.h>
int swap(int *p1,int *p2);
int main()
{ int x,y,z;
  printf("input 3 integers:\n");
  scanf("%d%d%d",&x,&y,&z);
  if(x>y)
	  swap(&x,&y);
  if(x>z)
	  swap(&x,&z);
  if(y>z)
	  swap(&y,&z);
  printf("from small to big:\n");
  printf("%5d%5d%5d\n",x,y,z);
  return 0;
}

int swap(int *p1,int *p2)
{ int t;
  t=*p1;
  *p1=*p2;
  *p2=t;
  return 0;
}
