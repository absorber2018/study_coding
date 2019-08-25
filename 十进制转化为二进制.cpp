//第五章第15题
//下面程序功能为：将一个十进制整数转换为二进制整数后输出
#include <stdio.h>
int main()
{   int i,n=0;
    int a[50],num;
	//num用于存放待转换的十进制数，a用于存放其对应的二进制数位
    printf("请输入一个十进制整数：\n");
	scanf("%d",&num);
	//通过循环对num不断除以2，获得的余数保存在a中的各个元素中
	while(num!=0)
	{ a[n]=num%2;
	  n++;
	  num=num/2;
	}
	//输出结果，余数倒着输出
    printf("转换得到的二进制整数为：\n");
    for(i=n-1;i>=0;i--)
       printf("%d",a[i]);
	printf("\n");
	return 0;
}
