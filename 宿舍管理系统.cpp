#include <iostream>
#include <string.h>
#include <fstream>
#include<stdlib.h>
#include <ctime>
using namespace std;
class student
{
public:
    char stu_num[11]; //ѧ�ţ������
    char stu_name[40]; //����
    char class_name[40]; //���
    char house_name[20]; //����
	student()
	{
		stu_num[0]=0;
        stu_name[0] =0;
        class_name[0] =0;
        house_name[0] =0;
	}
	student(char* a, char * b,char *c,char *d)
	{
		Setdata(a , b, c, d);
	}
	~ student(){}
    char * Getstuname(void) //��������
	{
        return stu_name ;
	}
    char* Getstunum(void) //ѧ�Ų���
	{
        return stu_num;
	}
    char * Gethousename(void) //����Ų���
	{
        return house_name;
	}
    char * Getclassname(void) //���༶����
	{
        return class_name;
	}
    void Setdata(char* a, char *b,char *c,char *d)
	{
        strcpy(stu_num,a);
        strcpy(stu_name, b);
        strcpy(class_name, c);
        strcpy(house_name, d);
	}
    void Show(void)
	{
        cout<<"ѧ��:"<<stu_num<<"\t"<<"����:"<<stu_name<<"\t";
        cout<<"�༶:"<<class_name<<"\t\t"<<"����:"<<house_name<<"\n";
	}
};


void Register();
int Enter();
int Display()//�˵�
{
    cout<<"\t\t--------------------------------------------------------------------------------\t\t\n";
    cout<<"\t\t------------------------------��������ѧ�������ϵͳ--------------------------\t\t\n";
    cout<<"\t\t-------------------------------------��¼ϵͳ-----------------------------------\t\t\n";
    cout<<"\t\t                                     1)Registerע��                             \t\t\n";
    cout<<"\t\t                                     2)Enter��¼                                \t\t\n";
    cout<<"\t\t                                     3)Exit�˳�                                 \t\t\n";
    cout<<"\t\t                              Choice:";

    int choice;//ѡ��˵�
    cin>>choice;

    switch(choice)
    {
case 1://ע��
    Register();//call function���ú���
        break;
case 2://��¼
    Enter();//call function��ͷ����
    break;
case 3://�˳�
    exit(EXIT_FAILURE);
    }
	return 0;

}
void Register()//ע��
{
    ofstream outFile;
    outFile.open("web1.txt",ios_base::out|ios_base::app);//��ע���ID��code���浽web1.txt�ļ�����
    if(!outFile.is_open())//���û�гɹ����ļ�
    {
        cout<<"���ź������Ӳ��Ϸ�����"<<endl;
        cout<<"�������"<<endl;
        cin.get();
        exit(EXIT_FAILURE);
    }
    string name;
    string code;
    cout<<"\t\t                            Please Enter members name�������û�������:";
    cin.get();//�����ַ�
    getline(cin,name);
    //ռλ������������û����������Ȼ�̫��

    outFile<<name<<endl;//��¼ע������ϵ�web1.txt�ļ���

    cout<<"\t\t                            Please Enter members code����������:";
    getline(cin,code);
    //ռλ��������������볬�����Ȼ�̫��

    outFile<<code<<endl;//��¼ע������ϵ�web1.txt�ļ���
    cout<<"ע��ɹ���";
    outFile.close();
    Display();
}
int Enter()//��¼
{
    cin.get();
    ifstream inFile;//����ifstream����
    inFile.open("web1.txt");//��ȡweb1.txt�ļ��е�ע������
    if(!inFile.is_open())//����ļ�û�гɹ���
    {
        cout<<"���ź������Ӳ��Ϸ�����"<<endl;
        exit(EXIT_FAILURE);
    }
    string name;
    string code;
    string temp;

    cout<<"\t\t                            Please Enter members name�������û�������:";
    getline(cin,name);

    while(getline(inFile,temp))//ƥ���û���
    {
        if(temp==name)//���ƥ���û����ɹ�
        {
            cout<<"\t\t                            Please Enter members code����������:";//����������
            getline(cin,code);//code
            getline(inFile,temp);//ƥ��code
            if(temp==code)//���������ȷ����¼�ɹ�
            {
                cout<<"��¼�ɹ�"<<endl;
                break;//ռλ����¼�ɹ�Ӧ��ת����������
            }
            else
            {
                cout<<"�������"<<endl;
                Display();//���أ�
            }
        }
        else
        {
            cout<<"�û������ڣ�"<<endl;
            Display();
        }
    }
	return 0;
}

int main(void)
{
	Display();
        cin.get();

	student stu[200];
	student s1;
    int flags=0;
    char stu_num [11]; //ѧ��
    char stu_name[40]; //����
    char class_name[40]; //�༶
    char house_name[20]; //����
    time_t t;
    time(&t);
    ifstream file1;//����һ�����ļ�����ĺ���file1
    ofstream file3;//����һ�����ļ�������ĺ���file3
    char flag = 'y';
	cout<<endl;
    cout<< "\t\t------------------------------��������ѧ�������ϵͳ----------------------------\t\t"<<endl;
	cout<< "\t\t\t ʱ��:" << ctime(&t);
    while( flag=='y' || flag=='Y')
	{ //��flag����ѭ��

        cout<<"\t\t--------------------------------------------------------------------------------\t\t\n";
		cout<<"\t\t--------------------------------------------------------------------------------\t\t\n";
        cout<<"\t\t��1:���ѧ����Ϣ!��";
        cout<<"\t\t\t\t\t��2:��ѧ�Ų鿴ѧ����Ϣ!��\n\n";
        cout<<"\t\t��3:������Ų鿴ѧ����Ϣ!��";
        cout<<"\t\t\t\t��4:�������鿴ѧ����Ϣ!��\n\n";
        cout<<"\t\t��5:���༶�鿴ѧ����Ϣ!��";
        cout<<"\t\t\t\t��6:��ʾȫ��ѧ����Ϣ!��\n\n";
        cout<<"\t\t��7:��ѧ���޸�ѧ����Ϣ!��";
        cout<<"\t\t\t\t��8:�������޸�ѧ����Ϣ!��\n\n";
		cout<<"\t\t��9:�������޸�ѧ����Ϣ!��";
		cout<<"\t\t\t\t��10:��ѧ��ɾ��ѧ����Ϣ!��\n\n";
		cout<<"\t\t��11:������ɾ��ѧ����Ϣ!��";
		cout<<"\t\t\t\t��12:������ɾ��ѧ����Ϣ!��\n\n";
        cout<<"\t\t��13:���ѧ����Ϣ!��\n";
        cout<<"\t\t--------------------------------------------------------------------------------\t\t\n";
		cout<<"\t\t--------------------------------------------------------------------------------\t\t\n";
        cout<<"������ѡ��";
    int choice;
	cin>>choice;
    switch(choice)
	{
	case 1:
		system("cls");
		file3.open("c:\\stu.dat",ios::app|ios::binary);//�������������ļ������д���ļ�ĩβ��������
        input: flags=0;
        cout<<"����ѧ�ţ�";
        cin>>stu_num;
		while (strlen(stu_num)!=10)
		{
			cin.clear();//�������
            rewind(stdin);//���������
            cout << "�������ѧ�Ų���ȷ��������һ��ʮλ����ѧ��" << endl;
            cout << "ѧ��:";
            cin >> stu_num;
		}
        file1.open("c:\\stu.dat",ios::in | ios::binary );//������ʽ���ļ�
        while(!file1.eof())//�ļ�δ����ʱ����ѭ��
		{
            int n;
            file1.read((char *)&s1,sizeof(student));//���ļ��ж�ȡ��Ϣ��s1
            n=file1.gcount();
           if(n==sizeof(student))
		   {
			    if(s1.Getstunum()==stu_num)
				flags=1;
		   }
		}
        file1.clear();
        file1.close();
        cout<<"����������"; cin>>stu_name;
        cout<<"����༶��"; cin>>class_name;
        cout<<"�������᣺"; cin>>house_name;
        s1.Setdata(stu_num,stu_name,class_name,house_name);
        file3.write((char*)&s1,sizeof(s1));
        file3.clear();
        file3.close();
        break;
	case 2: //��ѧ�Ų���
		system("cls");
		cout<<"������ѧ����ѧ�ţ�";
        cin>>stu_num;
        while (strlen(stu_num)!=10)
		{
			cin.clear();
            rewind(stdin);
            cout << "�������ѧ�Ų���ȷ��������һ��ʮλ����ѧ��" << endl;
            cout << "ѧ��:";
            cin >> stu_num;
		}
        file1.open("c:\\stu.dat",ios::in | ios::binary );//������ʽ���ļ�
        while(!file1.eof())
		{
			int n;
            file1.read((char *)&s1,sizeof(student));
            n=file1.gcount();
			if(n==sizeof(student))
			{
				if(strcmp(s1.Getstunum(),stu_num)==0) //��ʾѧ����Ϣ
				{
					s1.Show();
                    flags=1;
				}
			}
		}
        file1.clear();
        file1.close();
        if (flags==0)
			cout << "û����ѧ��Ϊ��"<< stu_num <<"��ѧ����¼!" << endl;
            flags=0;
            break;
 case 3: //������Ų���
	 system("cls");
	 cout<<"�����������:";
     cin>>house_name;
     file1.open("c:\\stu.dat",ios::in | ios::binary );//������ʽ���ļ�
     while(!file1.eof())
	 {
		 int n;
         file1.read((char *)&s1,sizeof(student));
         n=file1.gcount();
         if(n==sizeof(student))
		 {
			 if(strcmp(s1.Gethousename(),house_name)==0)
			 {
				 s1.Show();
                 flags=1;
			 }
		 }
	 }
     file1.clear();
     file1.close();
     if (flags==0)
		 cout << "û���ҵ�����Ϊ:"<< house_name <<"��ѧ����¼!" << endl;
     flags=0;
     break;
 case 4: //����������
	 system("cls");
	 cout<<"������ѧ������:";
     cin>>stu_name;
     file1.open("c:\\stu.dat",ios::in | ios::binary );//������ʽ���ļ�
     while(!file1.eof())
	 {
		 int n;
         file1.read((char *)&s1,sizeof(student));
         n=file1.gcount();
         if(n==sizeof(student))
		 {
			 if(strcmp(s1. Getstuname(),stu_name)==0)
			 {
				 s1.Show();
                 flags=1;
			 }
		 }
	 }
    file1.clear();
     file1.close();
	 if (flags==0)
		 cout << "û���ҵ�����Ϊ:"<< stu_name <<"��ѧ����¼!" << endl;
     flags=0;
     break;
 case 5: //���༶����
	 system("cls");
	 cout<<"������༶����:";
     cin>>class_name;
	 file1.open("c:\\stu.dat",ios::in | ios::binary );//������ʽ���ļ�
     while(!file1.eof())
	 {
		 int n;
         file1.read((char *)&s1,sizeof(student));
         n=file1.gcount();
         if(n==sizeof(student))
		 {
			 if(strcmp(s1. Getclassname(),class_name)==0)
			 {
				 s1.Show();
				 flags=1;
			 }
		 }
	 }
     file1.clear();
     file1.close();
	 if (flags==0)
		 cout << "û���ҵ��ð༶Ϊ:"<< class_name <<"��ѧ����¼!" << endl;
	 flags=0;
     break;
 case 6: //��ʾȫ��ѧ����Ϣ
	 system("cls");
	 file1.open("c:\\stu.dat",ios::in | ios::binary);//������ʽ���ļ�
	 while(!file1.eof())
	 {
		 int n;
		 file1.read((char *)&s1,sizeof(student));
         n=file1.gcount();
		 if(n==sizeof(student))
		 {
			 s1.Show();
			 flags=1;
		 }
	 }
	file1.clear();
     file1.close();
	 if (flags==0)
		 cout << "�ļ�û�м�¼!" << endl;
	 flags=0;
	 break;
 case 7://�޸�ѧ����Ϣ��ѧ��
	 system("cls");
	 flags=0;
	 cout<<"������Ҫ�޸�ѧ����ѧ��:";
     cin>>stu_num;
     while (strlen(stu_num)!=10)
	 {
		 cin.clear();
		 rewind(stdin);
		 cout << "�������ѧ�Ų���ȷ��������һ��ʮλ����ѧ��" << endl;
         cout << "ѧ��:";
         cin >> stu_num;
	 }
	 file1.open("c:\\stu.dat", ios::in );//������ʽ���ļ�
     while(!file1.eof())
	 {
		 int n;
		 file1.read((char *)&s1,sizeof(student));
         n=file1.gcount();
		 if(n==sizeof(student))
		 {
			 if(strcmp(s1.Getstunum(),stu_num)==0)
			 {
				 file3.open("c:\\stu.dat", ios::out);
				 cout<<"����ѧ�ţ�"; cin>>stu_num;
                 cout<<"����������"; cin>>stu_name;
                 cout<<"����༶��"; cin>>class_name;
                 cout<<"�������᣺"; cin>>house_name;
                 s1.Setdata(stu_num,stu_name,class_name,house_name);
                 file3.write((char*)&s1,sizeof(s1));
                 file3.close();
				 flags=1;
			 }
		 }
	 }
	 file1.clear();
     file1.close();
	 if (flags==0)
	 {
		 cout << "û�д�ѧ����¼�����ܽ����޸ģ�" << endl;
		 break;
	 }
	 break;
 case 8://�������޸�
	 system("cls");
	 flags=0;
	 cout<<"������Ҫ�޸�ѧ��������:";
     cin>>stu_name;
	 file1.open("c:\\stu.dat", ios::binary | ios::in |ios::out);//������ʽ���ļ�
     while(!file1.eof())
	 {
		 int n;
		 file1.read((char *)&s1,sizeof(student));
         n=file1.gcount();
		 if(n==sizeof(student))
		 {
			 if(strcmp(s1.Getstuname(),stu_name)==0)
			 {
				 file3.open("c:\\stu.dat",ios::in|ios::out|ios::binary);
				 cout<<"����ѧ�ţ�"; cin>>stu_num;
                 cout<<"����������"; cin>>stu_name;
                 cout<<"����༶��"; cin>>class_name;
                 cout<<"�������᣺"; cin>>house_name;
                 s1.Setdata(stu_num,stu_name,class_name,house_name);
                 file3.write((char*)&s1,sizeof(s1));
                 file3.close();
				 flags=1;
			 }
		 }
	 }
	 file1.clear();
     file1.close();
	 if (flags==0)
	 {
		 cout << "û�д�ѧ����¼�����ܽ����޸ģ�" << endl;
		 break;
	 }
	 break;
 case 9://�������޸�
	 system("cls");
	 flags=0;
	  cout<<"�����������:";
     cin>>house_name;
     file1.open("c:\\stu.dat",ios::in | ios::binary );//������ʽ���ļ�
     while(!file1.eof())
	 {
		 int n;
         file1.read((char *)&s1,sizeof(student));
         n=file1.gcount();
         if(n==sizeof(student))
		 {
			 if(strcmp(s1.Gethousename(),house_name)==0)
			 {
				 s1.Show();
                 flags=1;
			 }
		 }
	 }
     file1.clear();
     file1.close();
     if (flags==0)
		 cout << "û���ҵ�����Ϊ:"<< house_name <<"��ѧ����¼!" << endl;
     flags=0;
	 flags=0;
	 cout<<"������Ҫ�޸�ѧ��������:";
     cin>>stu_name;
	 file1.open("c:\\stu.dat", ios::binary | ios::in |ios::out);//������ʽ���ļ�
     while(!file1.eof())
	 {
		 int n;
		 file1.read((char *)&s1,sizeof(student));
         n=file1.gcount();
		 if(n==sizeof(student))
		 {
			 if(strcmp(s1.Getstuname(),stu_name)==0)
			 {
				 file3.open("c:\\stu.dat",ios::in|ios::out|ios::binary);
				 cout<<"����ѧ�ţ�"; cin>>stu_num;
                 cout<<"����������"; cin>>stu_name;
                 cout<<"����༶��"; cin>>class_name;
                 cout<<"�������᣺"; cin>>house_name;
                 s1.Setdata(stu_num,stu_name,class_name,house_name);
                 file3.write((char*)&s1,sizeof(s1));
                 file3.close();
				 flags=1;
			 }
		 }
	 }
	 file1.clear();
     file1.close();
	 if (flags==0)
	 {
		 cout << "û�д�ѧ����¼�����ܽ����޸ģ�" << endl;
		 break;
	 }
	 break;
 case 10://ɾ��ѧ����Ϣ��ѧ
	 system("cls");
	 {
		 int h=0;
		  cout<<"������Ҫɾ��ѧ����ѧ��:";
     cin>>stu_num;
     while (strlen(stu_num)!=10)
	 {
		 cin.clear();
		 rewind(stdin);
		 cout << "�������ѧ�Ų���ȷ��������һ��ʮλ����ѧ��" << endl;
         cout << "ѧ��:";
         cin >> stu_num;
	 }
		 file1.open("c:\\stu.dat",ios::in | ios::binary);//������ʽ����
	 while(!file1.eof())
	 {
		 int n;

		 file1.read((char *)&s1,sizeof(student));
         n=file1.gcount();
		 if(n==sizeof(student))
		 {

			 h++;
			 stu[h]=s1;
			 if(strcmp(stu[h].stu_num,stu_num)==0)
			 {
				 h--;
			 }
			 flags=1;
		 }
	 }
	 file3.open("c:\\stu.dat",ios::trunc);
	 file3.close();
	 file3.open("c:\\stu.dat",ios::in|ios::out|ios::binary);
	 for(int f=1;f<=h;f++)
	 {file3.write((char*)&stu[f],sizeof(stu[f]));
	 stu[f].~student();}
	 file3.close();
	 cout<<"ɾ���ɹ���"<<endl;
	 break;
	 }
 case 11://ɾ��ѧ����Ϣ������
	 system("cls");
	  {
		 int h=0;
		  cout<<"������Ҫɾ��ѧ��������:";
     cin>>stu_name;
		 file1.open("c:\\stu.dat",ios::in | ios::binary);//������ʽ����
	 while(!file1.eof())
	 {
		 int n;

		 file1.read((char *)&s1,sizeof(student));
         n=file1.gcount();
		 if(n==sizeof(student))
		 {

			 h++;
			 stu[h]=s1;
			 if(strcmp(stu[h].stu_name,stu_name)==0)
			 {
				 h--;
			 }
			 flags=1;
		 }
	 }
	 file3.open("c:\\stu.dat",ios::trunc);
	 file3.close();
	 file3.open("c:\\stu.dat",ios::in|ios::out|ios::binary);
	 for(int f=1;f<=h;f++)
	 {file3.write((char*)&stu[f],sizeof(stu[f]));
	 stu[f].~student();}
	 file3.close();
	 cout<<"ɾ���ɹ���"<<endl;
	 break;
	 }
 case 12://ɾ��ѧ����Ϣ������
	 system("cls");
	 cout<<"�����������:";
     cin>>house_name;
     file1.open("c:\\stu.dat",ios::in | ios::binary );//������ʽ���ļ�
     while(!file1.eof())
	 {
		 int n;
         file1.read((char *)&s1,sizeof(student));
         n=file1.gcount();
         if(n==sizeof(student))
		 {
			 if(strcmp(s1.Gethousename(),house_name)==0)
			 {
				 s1.Show();
                 flags=1;
			 }
		 }
	 }
     file1.clear();
     file1.close();
	  {
		 int h=0;
		  cout<<"������Ҫɾ��ѧ����ѧ��:";
     cin>>stu_num;
     while (strlen(stu_num)!=10)
	 {
		 cin.clear();
		 rewind(stdin);
		 cout << "�������ѧ�Ų���ȷ��������һ��ʮλ����ѧ��" << endl;
         cout << "ѧ��:";
         cin >> stu_num;
	 }
		 file1.open("c:\\stu.dat",ios::in | ios::binary);//������ʽ����
	 while(!file1.eof())
	 {
		 int n;

		 file1.read((char *)&s1,sizeof(student));
         n=file1.gcount();
		 if(n==sizeof(student))
		 {

			 h++;
			 stu[h]=s1;
			 if(strcmp(stu[h].stu_num,stu_num)==0)
			 {
				 h--;
			 }
			 flags=1;
		 }
	 }
	 file3.open("c:\\stu.dat",ios::trunc);
	 file3.close();
	 file3.open("c:\\stu.dat",ios::in|ios::out|ios::binary);
	 for(int f=1;f<=h;f++)
	 {file3.write((char*)&stu[f],sizeof(stu[f]));
	 stu[f].~student();}
	 file3.close();
	 cout<<"ɾ���ɹ���"<<endl;
	 break;
	 }
 case 13://����ļ�
	 system("cls");
	 file3.open("c:\\stu.dat",ios::trunc);
	 break;
 default: flag = 'n';
	 break;
}
}
cout << "лл����ʹ��!" << endl;

}
