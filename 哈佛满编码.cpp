#include <stdio.h>
#include <stdlib.h>
#define MAXVALUE 10000 /*���ȨֵΪ10000 */
#define MAXLEAF 30 /* �����30��Ҷ�ӽ�� */
#define MAXNODE MAXLEAF*2-1
/* ����������޶�Ϊ1�Ľ��,�ܽ����n=n0+n2 ����n0 =30ʱ,���ݶ���������
n0=n2+1, n2 = n0-1=29�����Թ������������30+29 =59����� */
#define MAXBIT 10
typedef struct
  {int weight;
   int parent;
   int lchild;
   int rchild;
  }HNodeType;
void Create_HuffMTree(HNodeType HFMTree[ ],int n)
    {int m1,m2,x1,x2;
     int i,j;
      for(i=0;i<2*n-1;i++)
         {HFMTree[i].weight=0;
           HFMTree[i].parent=-1;
           HFMTree[i].lchild=-1;
           HFMTree[i].rchild=-1;}
      for (i=0;i<n;i++)
        scanf("%d",&HFMTree[i].weight);
	  for(i=0;i<n-1;i++)
    { x1=x2=MAXVALUE;
       m1=m2=0;
       for (j=0;j<n+i;j++)
          {if (HFMTree[j].parent==-1&&
                  HFMTree[j].weight<x1)
                 {x2=x1;m2=m1;
                   x1=HFMTree[j].weight;
                   m1=j;}
            else if(HFMTree[j].parent==-1&& HFMTree[j].weight<x2)
                   {x2=HFMTree[j].weight;
                     m2=j;}
           }
 HFMTree[m1].parent=n+i;
 HFMTree[m2].parent=n+i;
 HFMTree[n+i].weight=HFMTree[x1].weight+HFMTree[x2].weight;
 HFMTree[n+i].lchild=m1  ;
 HFMTree[n+i].rchild=m2;}
}

void  HFcode(HNodeType ht[ ],int n)
{   int s[MAXNODE] ,i,c,p,top; //MaxNodeΪ���Ľ����
   for(i=0;i<n;i++)
    {  c=i; p=ht[i].parent;   top=-1;
       while(p!=-1)
       { top++;
         if(ht[p].lchild==c) s[top]=0;
         else s[top]=1;
         c=p; p=ht[c].parent;
       }
      printf("\n%d�Ĺ���������Ϊ�� ",ht[i].weight);
      while(top>=0                )
        printf("%d",s[top--]);
   }
}

int main()
{HNodeType HFM[MAXNODE];
 int num;
 scanf("%d",&num);
 Create_HuffMTree(HFM,num);
 HFcode( HFM ,num                 );
 return 0;
}
