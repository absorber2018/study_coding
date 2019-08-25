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
typedef struct
        { int bit[MAXBIT ];  /*������ַ�����������Ŀռ�*/
           int start;      /* ������ַ�����������Ŀ�ʼλ�� */
         }HCodeType;
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
 HFMTree[n+i].weight= HFMTree[x1].weight+ HFMTree[x2].weight;
 HFMTree[n+i].lchild=m1;
 HFMTree[n+i].rchild=m2;}
}

void HuffmanCode(HNodeType HFMTree[ ], HCodeType HuffCode[  ],int n)
 { HCodeType cd;
    int i,j,c,p;
    for(i=0;i<n;i++)
     {cd.start=n-1;
       c=i;
       p=HFMTree[c].parent;
       while(p!=-1)
           { if(HFMTree[p].lchild==c)
	              cd.bit[cd.start]=0;
	         else
	              cd.bit[cd.start]=1;
              cd.start--;
	         c=p;
	         p=HFMTree[p].parent;
           }
for (j=cd.start +1       ;j<n;j++)
     HuffCode[i].bit[j]=cd.bit[j];
     HuffCode[i].start=cd.start;
 }
}
int main()
{HNodeType HFM[MAXNODE];
 int num;
 int i,j;
 HCodeType HFMCode[MAXLEAF];
 scanf("%d",&num);
 Create_HuffMTree(HFM,num);
 HuffmanCode(HFM,HFMCode,num);
 for(i=0;i<num;i++)
    {for (j=HFMCode[i].start +1                   ;j<num;j++)
      printf ("%d",HFMCode[i].bit[j]);
      printf("\n");
    }
    return 0;
}
