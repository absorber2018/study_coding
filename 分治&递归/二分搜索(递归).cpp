#include <iostream>
using namespace std;
int Search(int a[],const int&x,int left,int right)
{
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(x==a[middle])
            return middle;
        if(x>a[middle])
        {
            left=middle+1;
            Search(a,x,left,right);
        }
            else
            {
                right=middle-1;
                Search(a,x,left,right);
            }
    }
    return -1;
}
int main()
{
    int a[5]={0,3,4,2,6};
    cout<<"��������ҵ���"<<endl;
    int x;
    cin>>x;
    cout<<Search(a,x,0,4);
    return 0;
}
