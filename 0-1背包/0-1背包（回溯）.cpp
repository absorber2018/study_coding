#include<iostream>
using namespace std;
class Knap{
private:
    int c=7;
    int n=4;
    int w[5]={0,2,2,6,5};
    int p[5]={0,6,3,5,4};
    int cw=0;
    int cp=0;
    int bestp=0;
public:
    void Backtrack(int i)
    {

        if(i>n){
            bestp=cp;
            return;
        }
        if(cw+w[i]<=c){
            cw+=w[i];
            cp+=p[i];
            Backtrack(i+1);
            cw-=w[i];
            cp-=p[i];
        }
        if(Bound(i+1)>bestp){
            Backtrack(i+1);
        }
    }
    int Bound(int i)
    {
        int cleft=c-cw;
        int b=cp;
        while(i<=n&&w[i]<=cleft){
            cleft-=w[i];
            b+=p[i];
            i++;
        }
        if(i<=n){b+=p[i]*cleft/w[i];}
        return b;

    }
    void sort()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
            if(p[i]/w[i]<p[j]/w[j]){
                int t=p[i];
                p[i]=p[j];
                p[j]=t;
                t=w[i];
                w[i]=w[j];
                w[j]=t;}
            }
        }
    }
    void print()
    {
        cout<<bestp;
    }
};
int main()
{
    Knap a;
    a.sort();
    a.Backtrack(1);
    a.print();
}
