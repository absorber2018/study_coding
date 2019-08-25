#include <iostream>
using namespace std;
int Swap(int &a,int &b)
{
    if(a==b)
       return 0;
    else
    {
    int temp=a;
    a=b;
    b=temp;
        }
}
void Perm(int list[],int k,int m)
{
    int sum=0;
   if(k==m)
    {
        //cout<<endl<<sum++;
        for(int i=0;i<=m;i++)
        {
           cout<<list[i];
        }
        cout<<endl;
    }
    else
        for(int i=k;i<=m;i++)
    {
        if(list[i]==list[i+1]||list[i]==list[i+2]||list[i]==list[i+3])
           continue;
          else
          {
        Swap(list[k],list[i]);
        Perm(list,k+1,m);
        Swap(list[k],list[i]);
          }
    }
}
int main()
{
    int a[]={1,5,4,7};
    Perm(a,0,3);
    return 0;
}
