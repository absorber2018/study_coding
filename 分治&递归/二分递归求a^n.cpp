#include <iostream>
using namespace std;
int Multiply(int a,int n)
{
      if(n>0)
     {
         n--;
         a=a*Multiply(a,n);
     }
     else
        return 1;
     return a;
}
int main()
{
    int a,n;
    cin>>a>>n;
    int an=Multiply(a,n);
    cout<<an;
    return 0;
}
