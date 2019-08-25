#include <stdio.h>
#define MaxVertexNum 100  /* ��󶥵�����Ϊ100 */
#define MaxCost 9999  /* �ߵ�Ȩֵ���Ϊ9999 */
typedef char VertexType;  /* ����������Ϊ�ַ��� */
typedef int  EdgeType;/* �ߵ�Ȩֵ��Ϊ���� */
typedef struct
   { VertexType vexs[MaxVertexNum];   /* ��Ŷ�����Ϣ */
      EdgeType  edges[MaxVertexNum][MaxVertexNum]; /* ����ڽӹ�ϵ */
      int  n,e; /*�������ͱ���*/
}Mgraph;
void CreateMGraph(Mgraph *G)
  {int i,j,k,w;
    printf("�����붥�����ͱ���(�����ʽΪ:������,����):\n") ;
    scanf("%d,%d",&(G->n),&(G->e));
    printf("�����붥����Ϣ:\n");
    for(i=0;i<G->n;i++)
        scanf("\n%c",&(G->vexs[i]));
	for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++)
            G->edges[i][j]=MaxCost;
    printf("������ÿ���߶�Ӧ��������������(�����ʽΪ:i,j,w):\n");
              for(k=0;k<G->e;k++)
                   { scanf("%d,%d,%d",&i,&j,&w);
                         G->edges[i][j]=w;
                         G->edges[j][i]=w;
				  }
    }
void Prim(int gm[][MaxVertexNum],int tree[],int cost[],int n)
  { int i,j,k,mincost,flag[MaxVertexNum];
    for (i=1; i<n; i++) flag[i]=0;
    flag[0]=1;  /*һ��ʼ��С��������ֻ��0�Ŷ���V0���� U ��ֻ��V0*/
    for (i=1; i<n; i++)
     { cost[i]=gm[0][i];
       tree[i]=0; }
    for (i=1;i<n;i++) /* ѭ��n-1��,ÿ�������С��������һ���� */
     { mincost=MaxCost; k=0;
       for(j=1;j<n;j++)
         {if (flag[j]==0 && cost[j]<mincost)
            { mincost=cost[j];k=j;}
          }   /* �ҳ�ֵ��С�� cost[k] */
       flag[k]=1;/* ��Vk���뵽��ǰ��С�������У����� Vk ���뵽 U �� */
       for(j=1;j<n;j++)/* �޸�cost[ ]��tree[ ] */
          if (flag[j]==0 && gm[k][j]<cost[j])
            { cost[j]=gm[k][j];tree[j]=k;}
       }
   }

void ShortestPath(Mgraph *G,int P[ ],int D[ ])
   {  int final[MaxVertexNum],i,j,k,min;
	  final[0]=1; /* ��ʼʱ����S��ֻ��0�Ŷ��� */
      D[0]=0;
      P[0]=-1; /* 0�Ŷ�����ǰ������ ����-1��ʾ */
      for(i=1;i<G->n;i++)
         { final[i]=0;
           D[i]=G->edges[0][i];
           P[i]=0; /* P[i]���i�Ŷ����ǰ������ */
        }
      for(i=1;i<G->n; i++) /*�ظ�G->n-1��*/
        { min=MaxCost;
          for(k=0;k<G->n;k++)
	        if(final[k]==0&&D[k]<min)
                {j=k;min=D[k];}
            final[j]=1;  /* ������j���뼯��S */
         for(k=0;k<G->n;k++)
	        if(final[k]==0&&D[j]+G->edges[j][k]< D[k])
                 { D[k]=D[j]+G->edges[j][k];
		           P[k]=j; }
       }
  }
void main()
{Mgraph G;
int tree[MaxVertexNum],cost[MaxVertexNum];
 int P[MaxVertexNum],D[MaxVertexNum];
 int i,pre;
 CreateMGraph(&G);
 Prim(G.edges,tree,cost,G.n);
 for (i=1;i<G.n;i++)
 printf("edge:(%d,%d),wight:%d\n",tree[i],tree[i+1],cost[i]);                                                /* �����С�������е�ÿ���� */
 ShortestPath(&G,P,D);
 for(i=1;i<G.n; i++)
      { printf("%d:%d",D[i],i);
         pre= P[i];
         while(pre>=0)
             { printf("<-%d",pre);
                pre=P[pre];
              }
         printf("\n");
      }
 }
