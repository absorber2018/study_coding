/*
#include <iostream>
using namespace std;
int q(int n,int m)
{
    if((n<1)||(m<1)) return 0;
    if((n==1)||(m==1))
    {
     if(n<m)
     {
         cout<<n<<"+"<<m<<endl;
     }
     else
     {
        while(n>0)
        {
           cout<<m<<"+";

           n=n-m;
        }
            cout<<"*";
       cout<<endl;
     }
    }
    if(n<m) q(n,n);
    if(n==m)
        {
           // cout<<m<<"+"<<endl;
            q(n,m-1);

        }
         q(n,m-1);
         q(n-m,m);
}
int main()
{
    int n;
    int m;
    cout<<"请输入待划分的整数";
    cin>>n;
    m=n-1;
    //for(int m=1;m<=n;m++)
     q(n,m);
    return 0;
}
*/
///*
#include<stdio.h>
#include<string.h>
//计算划分种数
int divideNumber(int n,int m)
{
if(m==1 || n==1)
return 1;
if(n<m)
return divideNumber(n,n);
else if(n==m)
return divideNumber(n,m-1)+1;
else
return divideNumber(n-m,m)+divideNumber(n,m-1); }
//输出划分结果
void divide(char *s,int first,int other)
{
int i;
static char t[50];//保存上一次的输出结果
char temp[50],str[3]={0};
if(other==0){
if(s[0]==t[0])
printf(",%s",s);
else
printf("%s",s);
strcpy(t,s);
}
for(i=other;i>=1;i--){
if(i>first)
continue;
strcpy(temp,s);
str[0]='+';
str[1]='0'+i;
strcat(s,str);
divide(s,i,other-i);
strcpy(s,temp);
}
}
int main()
{
    int i,n;
    char s[50]={0};
    char str[3]={0};
    scanf("%d",&n);
    printf("划分种类：%d\n",divideNumber(n,n));
    for(i=n;i>=1;i--)
    {
        if(i==n)
            printf("%d",n);
        else
            {
              s[0]=0;
              str[0]='0'+i;
              strcat(s,str);
              divide(s,i,n-i);
            }
            puts("");
    }
    return 0;
}
//*/
