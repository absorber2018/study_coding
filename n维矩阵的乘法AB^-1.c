#include<stdio.h>
int i,j,k,N;
float y=1.0;

void first(float a[N][N],float b[N][N],float c[N][N])
    {
     printf("�������a(����������ȣ�����0����):\n");
       for(i=0;i<N;i++)
       {
            for(j=0;j<N;j++)
              scanf("%f",&a[i][j]);
       }
     printf("�����������b(����������ȣ�����0����):\n");
        for(i=0;i<N;i++)
        {
           for(j=0;j<N;j++)
             scanf("%f",&b[i][j]);
        }
         inverse(b);
            for(i=0;i<N;i++)
                for(j=0;j<N;j++)
                    {
                    c[i][j]=0;
	               for(k=0;k<N;k++)
	                    c[i][j]+=a[i][k]*b[k][j];
	                    }

        printf("�������A��B�ĳ˻�����C:\n");
        for(i=0;i<N;i++)
        {
             for(j=0;j<N;j++)
	         printf("%3.2f\t",c[i][j]);
	             printf("\n");
	    }

    }

void inverse(float m[N][N])
{
         float d[N][2*N];
         float  t,x;
         int k;
        printf("Bԭ����Ϊ��\n");
         for (i=0;i<N;i++)
         {
            for (j=0;j<N;j++)
               printf("%3.2f\t",m[i][j]);
                    printf("\n");
         }
     for(i=0;i<N;i++)
        for(j=0;j<(2*N);j++)
       {
          if (j<N)
            d[i][j]=m[i][j];
           else if (j==N+i)
               d[i][j]=1.0;
                  else
              d[i][j]=0.0;
                          }
      for(i=0;i<N;i++)
      {
           for(k=0;k<N;k++)
           {
              if(k!=i)
            {  if(d[i][i]==0)
                  t=0;
                  else
                t=d[k][i]/d[i][i];
                for(j=0;j<(2*N);j++)
                    {
                        x=d[i][j]*t;
                        d[k][j]=d[k][j]-x;
                    }
            }
           }
      }

     for(i=0;i<N;i++)
        {
            if(d[i][i]==0)
                d[i][j]==0;
                  else
            t=d[i][i];
            for(j=0;j<(2*N);j++)
              d[i][j]=d[i][j]/t;
                   }

      for(i=0;i<N;i++)
         y=y*d[i][i];
  if(y==0)
    printf("�Բ���������ľ���û����������������롣\n");
  else
      {
         for(i=0;i<N;i++)
          for(j=0;j<N;j++)
            m[i][j]=d[i][j+N];
         printf("B�����Ϊ��\n");
         for (i=0;i<N;i++)
          {
            for (j=0;j<N;j++)
              printf("%3.2f\t",m[i][j]);
               printf("\n");
        }
     }
}

int main ()
{
    printf("������������Ĭ����������ȣ��������ʱȱʡ������0���룩:\n");
    scanf("%d",&N);
    float a[N][N],b[N][N],c[N][N];
    first(a,b,c);
    return 0;
 }

