#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

const int N=1000;
struct book/*��š���������𡢳����硢���ߡ��������ڡ����λ�á��ݲ�������״̬��־���Ƿ�ɽ����*/
{
    int num;
    char name[20];
    char classes[20];
    char publish[20];
    char author[20];
    char date[20];
    char place[20];
    int amount;
    char state[5];
};

void Creats(struct book books[],int *n,int *a)
{
    int i=0,j;
    FILE *fp1;
    fp1=fopen("C:\\a.txt","r");
    if(fp1==NULL)
        printf ("��_���򿪴���\n");
    else
    {
        while (!feof(fp1))
		{
            fscanf (fp1,"%d%s%s%s%s%s%s%d%s",&books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,&books[i].amount,books[i].state);
            i++;
        }
		printf("\n");
        printf ("��--~\(�R���Q)/~������--��ȡ�ɹ�-------��\n");
        *n=i;
        for(j=0;j<i-1;j++)
			*a=*a+books[j].amount;
    }
    fclose(fp1);
	getchar();
}

void Creat(struct book books[],int *n,int *a)//1
{
	system("CLS");
    Creats(books,n,a);
	printf("\n");
	printf("��------���������!-----��\n");
	getchar();
}






void Zengjia(struct book books[], int *n)
{
    int i;
    int a;
    i = *n;
    FILE *fp1;
	system("cls");//����
    printf("��---�t(������)�r--ͼ����Ϣ����--�t(������)�r--��\n");
    do
    {
        printf("��n���밴˳������ͼ����Ϣ:\n\n");
        printf("����������ͼ��ı��:\n");
        scanf("%d", &books[i].num);
        printf("����������ͼ�������:\n");
        scanf("%s", books[i].name);
        printf("����������ͼ������:\n");
        scanf("%s", books[i].classes);
        printf("����������ͼ��ĳ�����:\n");
        scanf("%s", books[i].publish);
        printf("����������ͼ�������:\n");
        scanf("%s", books[i].author);
        printf("����������ͼ��ĳ�������:\n");
        scanf("%s", books[i].date);
        printf("����������ͼ�����Чλ��:\n");
        scanf("%s", books[i].place);
        printf("������ͼ��Ĺݲ�����:\n");
        scanf("%d", &books[i].amount);
        printf("����������ͼ���״̬:\n");
        scanf("%s", books[i].state);
        (*n)++;
        printf("�Ƿ���Ҫ�������ͼ��:(0Ϊ�������ӣ����������Ӱ�0�������)\n");
		scanf("%d",&a);


    }
    while (a);
    {
        printf("\(^o^)/���ͼ��ɹ�!");

    }
	getchar();
	getchar();
}



void Xiugai(struct book books[],int *n)
{

    int i,k,a,p;
	system("cls");//����
    printf("��-----^_^------ͼ����Ϣ�޸�-----^_^-----��\n\n");
	printf("<(�����)>��������Ҫ�޸ĵ�ͼ��ı��:\n");
	scanf("%d",&p);
	do
     {k=*n-1;
    do
      k--;

    while(k>=0&&books[k].num!=p);
    if(k<0)
     {printf("\t|----�Ҳ���ͼ����Ϣ��----|\n");
	printf("\t|----����������ͼ����ţ�----|\n");
    scanf("%d",&p);}}
    while(k<0);
		do
		{

		   printf("��---�t(������)�r---�޸�ͼ������ѡ��---�t(������)�r---��:\n");
           printf("����-----��š�\n");
           printf("����-----������\n");
           printf("����-----���\n");
           printf("����-----�����硿\n");
           printf("����-----���ߡ�\n");
           printf("����-----�������ڡ�\n");
           printf("����-----��Чλ�á�\n");
           printf("����-----�ݲ�������\n");
           printf("����-----״̬��\n");
           printf("�r(�s3�t)�q����������ѡ��:\n");
		   printf("\n");
		   scanf("%d",&i);
		   printf("��----------------------�Ʃ�a����y--------------------��\n");
           switch(i)
		   {
		    case 1:	printf("�������޸ĺ�ı��:\n");
                scanf("%d",&books[k].num);break;
            case 2: printf("�������޸ĺ������:\n");
                scanf("%s",books[k].name);break;
            case 3: printf("�������޸ĺ�����:\n");
                scanf("%s",books[k].classes);break;
            case 4: printf("�������޸ĺ�ĳ�����:\n");
                scanf("%s",books[k].publish);break;
            case 5: printf("�������޸ĺ������:\n");
                scanf("%s",books[k].author);break;
            case 6: printf("�������޸ĺ�ĳ�������:\n");
                scanf("%s",books[k].date);break;
            case 7: printf("�������޸ĺ����Чλ��:\n");
                scanf("%s",books[k].place);break;
            case 8: printf("�������޸ĺ�Ĺݲ�����:\n");
                scanf("%d",&books[k].amount);break;
            case 9: printf("�������޸ĺ��״̬:\n");
                scanf("%s",books[k].state);break;
		   }
		printf("�޸ĳɹ�!");
		printf("�Ƿ���Ҫ�����޸�ͼ��:(0Ϊ�����޸ģ��������޸İ�0�������)\n");
		scanf("%d",&a);
		}
		while(a);
		{
			printf("�޸Ľ���!");
		}

	printf("��---���������!---��\n");
    	getchar();
		getchar();
		}

void Shanchu(struct book books[], int *n)//2
{
    int i, k;
    int a;
	system("cls");//����
    printf("��----��(^o^)��---ͼ����Ϣɾ��----��(^o^)��---��\n\n");
    printf("Y(^_^)Y������������ɾ��ͼ��ĺ���:\n");
    scanf("%d", &k);
    if (*n == 0)
        printf("��_��ͼ���ļ�Ϊ��\n");
    else if (k<1 || k>*n)
        printf("��_��ɾ��λ�ò�����\n");
    else
    {
        printf("ѡ��ɾ����%d��ͼ��,��ȷ��:�ѩn��(0Ϊȡ��ɾ������ɾ����0�������)\n",k);
        scanf("%d",&a);
	}
        while (a)
        {
            for (i = k; i < *n; i++)
			{
				books[i - 1] = books[i];
			}
			printf("ɾ���ɹ�!\n");
			a=0;
			(*n)--;
        }
		a=1;
        while(!a)
		{
			printf("ȡ��ɾ���ɹ�!\n");
			a=1;
		}
		printf("��--------���������!-------��\n");
		getchar();
		getchar();
}


void Change(struct book books[], int *n)
{
	int a;
	system("cls");//����
	printf("��---o(�Rv�Q)o~~---��ӭ����ͼ�����ϵͳ���� ɾ�� �޸Ľ���---o(�Rv�Q)o~~---��\n\n");
	    printf("����-------------���ӡ�\n\n");
		printf("����-------------ɾ����\n\n");
		printf("����-------------�޸ġ�\n\n");
		printf("��0----������һ��----��\n");
		printf("\n");
		printf("(0^��^0)������ѡ��:\n");
		scanf("%d",&a);
		switch(a)
		{
		case 1: Zengjia(books,n);break;
		case 2: Shanchu(books,n);break;
		case 3: Xiugai(books,n);break;
		}


}



void Find1(struct book books[],int n)
{
    int i;
    i=n-1;
    int m;
	system("CLS");
    printf("(^o^)������Ҫ���ҵı��");
    scanf ("%d",&m);
    while (i>0&&books[i].num!=m)
        i--;
    if (i==0)
        printf ("δ�ҵ�\n");
    else
        printf("%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
    getchar();
	getchar();
}

void Find2(struct book books[],int n)
{
    int i;
    i=n-1;
    char a[20];
	system("CLS");
    printf("�t(������)�r������Ҫ���ҵ�����:");
    scanf("%s",a);
    while (i>0&&strcmp(a,books[i].name)!=0)
        i--;
    if (i==0)
        printf ("(���ꡥ)δ�ҵ�\n");
    else
        printf("%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
    getchar();
	getchar();
}

void Find3(struct book books[],int n)
{
    int i,j=0,s[N];
    i=n-1;
    char a[20];
	system("CLS");
    printf("�t(������)�r������Ҫ���ҵ����:");
    scanf("%s",a);
	while (i>0&&strcmp(a,books[i].classes)!=0)
        i--;
    if (i==0)
        printf ("δ�ҵ�\n");
    else
        printf("%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
    getchar();
	getchar();
}

void Find4(struct book books[],int n)
{
    int i;
    i=n-1;
    char a[20];
	system("CLS");
    printf("�r(�s���t)�q������Ҫ���ҵĳ�����:");
    scanf("%s",a);
    while (i>0&&strcmp(a,books[i].publish)!=0)
        i--;
    if (i==0)
        printf ("��_��δ�ҵ�\n");
    else
        printf("%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
    getchar();
	getchar();
}

void Find5(struct book books[],int n)
{
    int i;
    i=n-1;
    char a[20];
	system("CLS");
    printf("(^o^)������Ҫ���ҵ�����:");
    scanf("%s",a);
    while (i>0&&strcmp(a,books[i].author)!=0)
        i--;
    if (i==0)
	{
        printf ("��_��δ�ҵ�\n");
	}
    else
	{
        printf("%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);

	}
	getchar();
	getchar();
}
void Find(struct book books[],int n)//3
{
    int m=6;

	while(m)
	{
		 system("CLS");
		 printf ("��--------o(�Rv�Q)o~~--------��\n\n");
		 printf ("����-----���ձ�Ų�ѯ-------��\n");
		 printf ("����-----����������ѯ-------��\n");
		 printf ("����-----��������ѯ-------��\n");
		 printf ("����-----���ճ������ѯ-----��\n");
		 printf ("����-----�������߲�ѯ-------��\n");
		 printf ("��0-----������һ��---------��\n");
		 printf("\n");
		 printf ("��--------o(�Rv�Q)o~~--------��\n");
		scanf("%d",&m);
		switch (m)
		{
			case 1:{Find1(books,n);break;}
			case 2:{Find2(books,n);break;}
			case 3:{Find3(books,n);break;}
		    case 4:{Find4(books,n);break;}
		    case 5:{Find5(books,n);break;}
		    case 0:{return;}
		}
	}
	getchar();
	getchar();
}




void Borrow(struct book books[],int *n)//4
{   int i,j,t;
    char copy[5]="no";
    int person;
	system("cls");//����
    printf("\t|----������ͼ����ţ�----|\n");
    scanf("%d",&i);
     do
     {t=*n-1;
    do
      t--;

    while(t>=0&&books[t].num!=i);
    if(t<0)
     {printf("\t|----�Ҳ���ͼ����Ϣ��----|\n");
	printf("\t|----����������ͼ����ţ�----|\n");
    scanf("%d",&i);}}
    while(t<0);

    printf("\t|----���������������----|\n");
    scanf("%d",&j);
    if(j>books[t].amount)
	{printf("\t��������,����Ľ�������\n");
	printf("\t|----�������������������----|\n");
    scanf("%d",&j);}
    printf("\t|----������ѧ��֤��ţ�----|\n");
    scanf("%d",&person);
    books[t].amount=books[t].amount-j;
    if(books[t].amount==0)
        strcpy(books[t].state,copy);
    printf("\t|----����ɹ���----|\n");
   getchar();
	getchar();
}

void Return(struct book books[],int *n)//5
{    int i,j,t;
    char copy[5]="yes";
    system("cls");//����
    printf("\t|----������ͼ����ţ�----|\n");
    scanf("%d",&i);
     do
     {t=*n-1;
    do
      t--;

    while(t>=0&&books[t].num!=i);
    if(t<0)
     {printf("\t|----�Ҳ���ͼ����Ϣ��----|\n");
	printf("\t|----����������ͼ����ţ�----|\n");
    scanf("%d",&i);}}
    while(t<0);
    printf("\t|----�����뻹��������----|\n");
    scanf("%d",&j);
    books[t].amount=books[t].amount+j;
    if(books[t].amount>0)
        strcpy(books[t].state,copy);
    printf("\t|----����ɹ���----|\n");
   getchar();
	getchar();
}


void Sort(struct book books[],int *n)//6
{   int i,j;
    struct book cb;
	system("cls");//����
    printf("��-----------^_^-------------ͼ �� �� Ϣ �� ��-------------^_^-----------��\n");
    for(j=0;j<*n-1;j++)
        for(i=j+1;i<*n;i++)
            if(books[i].num<books[j].num)
            {
				cb=books[i];
                books[i]=books[j];
                books[j]=cb;
            }
    printf("ͼ������(����ͼ���Ŵ�С��������)\n");
   printf(" ��� ͼ������ ��� ������ ���� �������� �ݲش� �ݲ��� ״̬��־���Ƿ�ɽ���� \n");
    for(i=0;i<*n;i++)
        printf(" %d %s %s %s %s %s %s %d %s\n",
              books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
    getchar();
	getchar();
}

void Print(struct book books[],int *n)//7
{
    int i;
	system("CLS");
    printf ("��----------�����T��------------ͼ �� �� Ϣ----------�����T��--------��\n\n");
    printf ("��� ���� ��� ������ ���� �������� ���λ�� �ݲ����� ״̬��־\n");
    for (i=0;i<*n;i++)
        printf("%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
	printf("\n");
    printf ("��-----------------------------�Ʃ�a����y----------------------------��\n");
	getchar();
	getchar();
}




void Write(struct book books[],int n)//8
{
    FILE *fp2;
    int i;
    fp2=fopen("C:\\b.txt","w");
	system("CLS");
    if(fp2==NULL)
	{

        printf ("��_���򿪴���");
	}
    else
    {

        for (i=0;i<n-1;i++)
            fprintf(fp2,"%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
         fprintf(fp2,"%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
		printf("Y(^_^)Y����ɹ�");
    fclose(fp2);
    }
    getchar();
	getchar();
}







int main()
{
    int menunum=10;
    int i,m=3,a=0;
    struct book books[N];
    int n=0;
    system("color 3D");
    while (m--)
    {
		system("CLS");
        printf("��----------�����T��------�� ӭ ʹ �� ͼ �� �� �� ϵ ͳ--------�����T��------��\n\n");
        printf("o(�Rv�Q)o~~����������������%d��!!!\n\n",m);
		printf("����������:");
        scanf("%d",&i);
        if(i!=666)//123456Ϊ�û��Զ�������
            ;
        else
        {
            while(menunum)
            {
				system("CLS");
                printf ("��--------�r(�s���t)�q��--------��\n\n");
                printf ("����------���ݶ�ȡ------��\n");
                printf ("����------��ɾ��--------��\n");
                printf ("����------��ѯ----------��\n");
                printf ("����------����----------��\n");
                printf ("����------����----------��\n");
                printf ("����------����----------��\n");
                printf ("����------��ʾ----------��\n");
                printf ("����------����д��------��\n");
                printf ("��0------�˳�����------��\n");
				printf("\n");
				printf ("��----------�Ʃ�a����y----------��\n");
                scanf("%d",&menunum);
                switch(menunum)
                {
                  case 0:return 0;//�˳�����
                  case 1:{Creat(books,&n,&a);break;}//���ݶ�ȡ
                  case 2:{Change(books,&n);break;}//����ɾ���Ĺ���
                  case 3:{Find(books,n);break;}//��ѯ����
                  case 4:{Borrow(books,&n);break;}//�������
                  case 5:{Return(books,&n);break;}//�������
                  case 6:{Sort(books,&n);break;}//������
                  case 7:{Print(books,&n);break;}//��ʾ����
                  case 8:{Write(books,n);break;}//����д�빦��
                  default: {printf("��_���������");}
                }
            }
        }
    }
    return 0;
}
/*���ܣ���ϵͳ����ͼ��ݹݲ�ͼ�����Ϣ�������߲�ѯ�ͽ��н軹�顣ÿ��ͼ��Ļ�����Ϣ��������š���������𡢳����硢���ߡ��������ڡ����λ�á��ݲ�������״̬��־���Ƿ�ɽ������ϵͳ�ṩ���¹��ܹ��û�ѡ��
 (1)���ݶ�ȡ���ܣ���ָ�������ļ��ж�ȡ����ͼ��Ļ�����Ϣ��c
 (2)����ɾ���Ĺ��ܣ��ɶ�ͼ�������Ϣ���в��롢ɾ�����޸ģ�a
 (3)��ѯ���ܣ��ɰ��ձ�š���������𡢳���������߽�����Ŀ��Ϣ�Ĳ�ѯ��c
 (4)��������ɰ��ձ�Ž��н���Ĵ���b
 (5)��������ɰ��ձ�Ž��л���Ĵ���b
 (6)�����ܣ��ɰ��ձ�š���𡢳������ڵȽ�������b
 (7)��ʾ���ܣ�������Ļ����ʾ����ͼ��Ļ�����Ϣ��c
 (8) ����д�빦�ܣ��ɽ�����ͼ����Ϣд��ָ�������ļ��С�c
 ���飺һ��������ݶ��롢���ӡ�ɾ�����޸ģ�һ�˸�����ɽ衢�������������ܣ�һ�˸����ļ�д���������ʾ��ѯ���ܡ���ʾ���ܡ��˵����ܼ���������*/

