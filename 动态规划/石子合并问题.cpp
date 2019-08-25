#include<iostream>
using namespace std;
int p[100][100]={0};
int dp[100][100];
int n;

void init(int *a){
    for(int i=1;i<=n;i++)
    {//
        p[i][i]=a[i];
        for(int j=i+1;j<=n;j++)
        {//i~j合并就是i~j-1合并数目加上j的数目
            p[i][j]=p[i][j-1]+a[j];
        }
    }
}

int Maxvalue(){
    int i,j,r,k;
    for(r=2;r<=n;r++)
    {//合并的石子堆数
        for(i=1;i+r-1<=n;i++)
        {//开始合并的石子堆
            j=i+r-1;//结束的堆
            dp[i][j] = p[i][i]+dp[i+1][j] + p[i+1][j];
            for(k=i+1;k<j;k++)
            {

                int temp=dp[i][k]+dp[k+1][j] + p[i][k]+p[k+1][j];
                if(temp>dp[i][j])
                    dp[i][j]=temp;
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        cout<<dp[i][j]<<" ";
     cout<<endl;

    }
    return dp[1][n];
}

int Minvalue(){
    int i,j,r,k;
    for(r=2;r<=n;r++)
    {
        for(i=1;i+r-1<=n;i++)
        {
            j=i+r-1;
            dp[i][j] = p[i][i]+dp[i+1][j] + p[i+1][j];
            for(k=i+1;k<j;k++)
            {
                int temp=dp[i][k]+dp[k+1][j] + p[i][k]+p[k+1][j];
                if(temp<dp[i][j])
                    dp[i][j]=temp;
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        cout<<dp[i][j]<<" ";
     cout<<endl;

    }
    return dp[1][n];
}

int main()
{
    int a[100];
    int max=0,min=9999999;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       cin>>a[i];
    }
   // memset(dp,0,sizeof(dp));
    init(a);
    max=Maxvalue();
    min=Minvalue();
    cout<<max<<" "<<min;
    return 0;
}
