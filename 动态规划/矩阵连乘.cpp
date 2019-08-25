#include <iostream>
using namespace std;
int p[7]={30,35,15,5,10,20,25};
    int n=6;
    int s[7][7]={0},m[7][7]={0};
void MatrixChain()
{
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int r=2;r<=n;r++)
        for(int i=1;i<=n-r+1;i++)
    {
        int j=i+r-1;
        m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
        s[i][j]=i;
        for(int k=i+1;k<j;k++)
        {
             int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
             if(t<m[i][j])
             {
                 m[i][j]=t;
                 s[i][j]=k;
             }
        }
    }
}
int main()
{
    MatrixChain();
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        cout<<m[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        cout<<s[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
