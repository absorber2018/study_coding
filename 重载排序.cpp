#include<iostream>
#include<string.h>
using namespace std;
void sort(int* p,int n);
void sort(char *p[],int n);
int main()
{
 int a[]={1,4,3,5,2};
 int n=sizeof(a)/sizeof(int);
 sort(a,n);
 char* b[4]={"nan jing","shang hai","bei jing","tian jing"};
 sort(b,4);
 for(int i=0;i<4;i++)
  std::cout<<a[i]<<std::endl;
 return 0;
}
void sort(int* p,int n)
{
 int temp;
 for(int i=1;i<n;i++)
 {
  for(int j=0;j<n-i;j++)
  {
   if(p[j]>p[j+1])
   {
    temp=p[j]; p[j]=p[j+1];
    p[j+1]=temp;
   }
  }
 }
}
void sort(char *p[],int n)
{
 char *temp;
 for(int i=1;i<n;i++)
 {
  for(int j=0;j<n-i;j++)
  {
     if (strcmp(p[j],p[j+1])>0)
     {
      temp=p[j]; p[j]=p[j+1]; p[j+1]=temp;
     }
  }
 }
}
