#include<iostream>
int sum=0;
using namespace std;

    int Mergr(int a[],int b[],int l,int i,int r)
    {
        int j,k;
        k=l;
        j=i+1;
        while(l<=i&&j<=r)
        {
            if(a[l]<=a[j])
            {
                b[k++]=a[l++];

            }
            else
            {
                b[k++]=a[j++];
                sum=sum+j-l;
            }

        }
        while(l<=i)
        {
            b[k++]=a[l++];
        }
        while(j<=r)
        {
            b[k++]=a[j++];
        }
        return 0;
    }
    void Copy(int a[],int b[],int l,int r)
    {
        int i=l;
        while(i<=r)
        {
            a[i]=b[i];
            i++;
        }
    }
    int MergrSort(int a[],int l,int r)
    {
        int b[r];
        if(l<r)
        {
            int i=(l+r)/2;
            MergrSort(a,l,i);
            MergrSort(a,i+1,r);
            Mergr(a,b,l,i,r);
            Copy(a,b,l,r);
        }
        return 0;
    }

int main()
{
    int n;
    cout<<"你要进行几个数字的合并排序？"<<endl;
    cin>>n;
    sum=n-1;
    int a[n];
    int l=0,r=n-1;
    cout<<"请输入需要合并排序的数字："<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    MergrSort(a,l,r);
   cout<<"排序好的序列为："<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
  cout<<"逆序对个数为："<<sum<<endl;
    return 0;
}
