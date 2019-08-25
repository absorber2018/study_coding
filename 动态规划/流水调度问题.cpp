#include <iostream>
using namespace std;
class Jobtybe
    {
    public:
        int key,index;
        bool job;
    };
void sort(Jobtybe *d,int n)
{
    Jobtybe temp;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        if(d[i].key>d[j].key)
    {
        temp.key=d[i].key;
        temp.job=d[i].job;
        temp.index=d[i].index;
        d[i].key=d[j].key;
        d[i].job=d[j].job;
        d[i].index=d[j].index;
        d[j].key=temp.key;
        d[j].job=temp.job;
        d[j].index=temp.index;
    }
}
int FlowShop(int n,int (&a)[4],int (&b)[4],int (&c)[4])
{

    Jobtybe *d=new Jobtybe[n];
    for(int i=0;i<n;i++)
    {
        d[i].key=a[i]>b[i]?b[i]:a[i];
        d[i].job=a[i]<=b[i];
        d[i].index=i;
    }
    sort(d,n);
    int j=0,k=n-1;
    for(int i=0;i<n;i++)
    {
        if(d[i].job)
            c[j++]=d[i].index;
        else
            c[k--]=d[i].index;
    }
    j=a[c[0]];
    k=j+b[c[0]];
    for(int i=1;i<n;i++)
    {
        j+=a[c[i]];
        k=j<k?k+b[c[i]]:j+b[c[i]];
    }
    delete d;
    return k;
}
int main()
{
    int n=4;
    int a[4]={2,5,7,10};
    int b[4]={3,8,4,11};
    int c[4]={0};
    int k=FlowShop(n,a,b,c);
    cout<<k;
}
