#include <iostream>
using namespace std;

void Knapsack(int (&v)[6],int (&w)[6],int c,int n,int (&m)[20][20])
{
    int jMax=min(w[0]-1,c);
    for(int j=1;j<=jMax;j++)
        m[0][j]=0;
    for(int j=w[0];j<=c;j++)
        m[0][j]=v[0];
    for(int i=1;i<=n;i++)
    {
        jMax=min(w[i]-1,c);
        for(int j=1;j<=jMax;j++)
            m[i+1][j]=m[i][j];
        for(int j=w[i];j<=c;j++)
            m[i+1][j]=max(m[i][j],m[i][j-w[i]]+v[i+1]);
    }
    /* for(int j=1;j<=15;j++)
        {
            for(int i=1;i<=10;i++)
                 cout<<m[i][j]<<"\t";
           cout<<endl;
        }
    */

}
void Traceback(int (&m)[20][20],int (&w)[6],int (&v)[6],int c,int n,int (&x)[6])
{
    int sum=0;
    for(int i=1;i<=n;i++)
        if(m[i][c]==m[i+1][c])
           x[i]=0;
    else
    {
        x[i]=1;
        c-=w[i];
        sum+=v[i];
    }
    x[n]=(m[n][c])?1:0;
    if(x[n]==1)
        sum+=v[n];
    cout<<sum;
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
    Traceback(m,w,v,c,n,x);
    return 0;
}
