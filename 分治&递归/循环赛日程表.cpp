#include<iostream>
using namespace std;
int k=3;
int sum=8;
int a[8][8];
void Table()
{
    int n=1;
    for(int i=1;i<=k;i++)
        n*=2;
    for(int i=1;i<=n;i++)
        a[1][i]=i;
    int m=1;
    for(int s=1;s<=k;s++)
   {
        n/=2;
        for(int t=1;t<=n;t++)
            for(int i=m+1;i<=2*m;i++)
               for(int j=m+1;j<=2*m;j++)
        {
            a[i][j+(t-1)*m*2]=a[i-m][j+(t-1)*m*2-m];
            a[i][j+(t-1)*m*2-m]=a[i-m][j+(t-1)*m*2];
        }
        m*=2;
    }
}
int main()
{
     Table();
     for(int i=1;i<sum;i++)
       {
           for(int j=1;j<=sum;j++)
            cout<<a[i][j]<<" ";
           cout<<endl;
       }
     return 0;
}
