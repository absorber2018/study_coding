#include <iostream>
using namespace std;

void Knapsack(int (&v)[6],int (&w)[6],int c,int n,int (&m)[20][20])
{
    int jMax=min(w[n]-1,c);
    for(int j=0;j<=jMax;j++)
        m[n][j]=0;
    for(int j=w[n];j<=c;j++)
        m[n][j]=v[n];
    for(int i=n-1;i>1;i--)
    {
        jMax=min(w[i]-1,c);
        for(int j=0;j<=jMax;j++)
            m[i][j]=m[i+1][j];
        for(int j=w[i];j<=c;j++)
            m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
    }
    m[1][c]=m[2][c];
    if(c>=w[1])
        m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
    cout<<endl<<m[1][c];
}
void Traceback(int (&m)[20][20],int (&w)[6],int c,int n,int (&x)[6])
{
    for(int i=1;i<n;i++)
        if(m[i][c]==m[i+1][c])
           x[i]=0;
    else
    {
        x[i]=1;
        c-=w[i];
    }
    x[n]=(m[n][c])?1:0;
    cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<x[i]<<" ";
}
int main()
{
    int w[6]={0,2,2,6,5,4};
    int v[6]={0,6,3,5,4,6};
    int x[6]={0};
    int n=5;
    int c=10;
    int m[20][20]={0};
    Knapsack(v,w,c,n,m);
    Traceback(m,w,c,n,x);
    return 0;
}
