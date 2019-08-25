#include <iostream>
using namespace std;

void LCSLlength(int m,int n,char (&x)[4],char (&y)[6],int (&c)[50][50],int (&b)[50][50])
{
    int i,j;
    for(i=1;i<=m;i++)
        c[i][0]=0;
    for(j=1;j<=n;j++)
        c[0][i]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
    {
        if(x[i]==y[j])
        {
            c[i][j]=c[i-1][j-1]+1;
            b[i][j]=1;
        }
        else if(c[i-1][j]>=c[i][j-1])
        {
            c[i][j]=c[i-1][j];
            b[i][j]=2;
        }
        else
        {
            c[i][j]=c[i][j-1];
            b[i][j]=3;
        }
    }
}
void LCS(int i,int j,char (&x)[4],int b[50][50])
{

    if(i==0||j==0)
        return;
    if(b[i][j]==1)
    {
         LCS(i-1,j-1,x,b);
        cout<<x[i];
    }
     else if(b[i][j]==2)
        LCS(i-1,j,x,b);
         else
        LCS(i,j-1,x,b);
}
int main()
{
    char y[6]={'0','a','b','c','d','e'};
    int n=5;
    char x[4]={'0','b','c','e'};
    int m=3;
    int c[50][50],b[50][50];
    LCSLlength(m,n,x,y,c,b);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        cout<<c[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        cout<<b[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    LCS(m,n,x,b);
    return 0;
}
