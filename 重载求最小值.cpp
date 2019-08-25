#include <iostream>
using namespace std;
/*class overload_min{
   private:
      //int data[4];
   public:
       void Min(int a,int b);
       void Min(int a,int b,int c);
       void Min(int a,int b,int c,int d);
};*/
 void Min(int a,int b){
    int i;
     i=a;
     if(b<a)
     i=b;
    cout<<i<<endl;
 }
 void Min(int a,int b,int c){
    int i;
     i=a;
     if(b<i)
     i=b;
     if(c<i)
     i=c;
    cout<<i<<endl;
 }
 void Min(int a,int b,int c,int d){
    int i;
     i=a;
     if(b<i)
     i=b;
     if(c<i)
     i=c;
     if(d<i)
     i=d;
    cout<<i<<endl;
 }

 int main(){
   int i,a,b,c,d;
   //overload_min m;
    cin>>a>>b>>c>>d;
    Min(a,b);
    Min(a,b,c);
    Min(a,b,c,d);
    return 0;
 }
