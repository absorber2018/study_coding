#include <iostream>
#include <string.h>
#include <fstream>
#include<stdlib.h>
#include <ctime>
using namespace std;
class student
{
public:
    char stu_num[11]; //学号，宿舍号
    char stu_name[40]; //姓名
    char class_name[40]; //班别
    char house_name[20]; //宿舍
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
    char * Getstuname(void) //姓名查找
	{
        return stu_name ;
	}
    char* Getstunum(void) //学号查找
	{
        return stu_num;
	}
    char * Gethousename(void) //宿舍号查找
	{
        return house_name;
	}
    char * Getclassname(void) //按班级查找
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
        cout<<"学号:"<<stu_num<<"\t"<<"姓名:"<<stu_name<<"\t";
        cout<<"班级:"<<class_name<<"\t\t"<<"宿舍:"<<house_name<<"\n";
	}
};


void Register();
int Enter();
int Display()//菜单
{
    cout<<"\t\t--------------------------------------------------------------------------------\t\t\n";
    cout<<"\t\t------------------------------西安理工大学宿舍管理系统--------------------------\t\t\n";
    cout<<"\t\t-------------------------------------登录系统-----------------------------------\t\t\n";
    cout<<"\t\t                                     1)Register注册                             \t\t\n";
    cout<<"\t\t                                     2)Enter登录                                \t\t\n";
    cout<<"\t\t                                     3)Exit退出                                 \t\t\n";
    cout<<"\t\t                              Choice:";

    int choice;//选择菜单
    cin>>choice;

    switch(choice)
    {
case 1://注册
    Register();//call function调用函数
        break;
case 2://登录
    Enter();//call function调头函数
    break;
case 3://退出
    exit(EXIT_FAILURE);
    }
	return 0;

}
void Register()//注册
{
    ofstream outFile;
    outFile.open("web1.txt",ios_base::out|ios_base::app);//把注册的ID、code保存到web1.txt文件当中
    if(!outFile.is_open())//如果没有成功打开文件
    {
        cout<<"很遗憾，连接不上服务器"<<endl;
        cout<<"程序结束"<<endl;
        cin.get();
        exit(EXIT_FAILURE);
    }
    string name;
    string code;
    cout<<"\t\t                            Please Enter members name请输入用户名名称:";
    cin.get();//掉空字符
    getline(cin,name);
    //占位，假设输入的用户名超出长度或太短

    outFile<<name<<endl;//记录注册的资料到web1.txt文件中

    cout<<"\t\t                            Please Enter members code请输入密码:";
    getline(cin,code);
    //占位，假设输入的密码超出长度或太短

    outFile<<code<<endl;//记录注册的资料到web1.txt文件中
    cout<<"注册成功！";
    outFile.close();
    Display();
}
int Enter()//登录
{
    cin.get();
    ifstream inFile;//定义ifstream对象
    inFile.open("web1.txt");//读取web1.txt文件中的注册资料
    if(!inFile.is_open())//如果文件没有成功打开
    {
        cout<<"很遗憾，连接不上服务器"<<endl;
        exit(EXIT_FAILURE);
    }
    string name;
    string code;
    string temp;

    cout<<"\t\t                            Please Enter members name请输入用户名名称:";
    getline(cin,name);

    while(getline(inFile,temp))//匹配用户名
    {
        if(temp==name)//如果匹配用户名成功
        {
            cout<<"\t\t                            Please Enter members code请输入密码:";//请输入密码
            getline(cin,code);//code
            getline(inFile,temp);//匹配code
            if(temp==code)//如果密码正确，登录成功
            {
                cout<<"登录成功"<<endl;
                break;//占位，登录成功应该转到程序主题
            }
            else
            {
                cout<<"密码错误"<<endl;
                Display();//返回！
            }
        }
        else
        {
            cout<<"用户不存在！"<<endl;
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
    char stu_num [11]; //学号
    char stu_name[40]; //姓名
    char class_name[40]; //班级
    char house_name[20]; //宿舍
    time_t t;
    time(&t);
    ifstream file1;//定义一个从文件输入的函数file1
    ofstream file3;//定义一个向文件中输出的函数file3
    char flag = 'y';
	cout<<endl;
    cout<< "\t\t------------------------------西安理工大学宿舍管理系统----------------------------\t\t"<<endl;
	cout<< "\t\t\t 时间:" << ctime(&t);
    while( flag=='y' || flag=='Y')
	{ //由flag控制循环

        cout<<"\t\t--------------------------------------------------------------------------------\t\t\n";
		cout<<"\t\t--------------------------------------------------------------------------------\t\t\n";
        cout<<"\t\t【1:添加学生信息!】";
        cout<<"\t\t\t\t\t【2:按学号查看学生信息!】\n\n";
        cout<<"\t\t【3:按宿舍号查看学生信息!】";
        cout<<"\t\t\t\t【4:按姓名查看学生信息!】\n\n";
        cout<<"\t\t【5:按班级查看学生信息!】";
        cout<<"\t\t\t\t【6:显示全部学生信息!】\n\n";
        cout<<"\t\t【7:按学号修改学生信息!】";
        cout<<"\t\t\t\t【8:按姓名修改学生信息!】\n\n";
		cout<<"\t\t【9:按宿舍修改学生信息!】";
		cout<<"\t\t\t\t【10:按学号删除学生信息!】\n\n";
		cout<<"\t\t【11:按姓名删除学生信息!】";
		cout<<"\t\t\t\t【12:按宿舍删除学生信息!】\n\n";
        cout<<"\t\t【13:清空学生信息!】\n";
        cout<<"\t\t--------------------------------------------------------------------------------\t\t\n";
		cout<<"\t\t--------------------------------------------------------------------------------\t\t\n";
        cout<<"请输入选择：";
    int choice;
	cin>>choice;
    switch(choice)
	{
	case 1:
		system("cls");
		file3.open("c:\\stu.dat",ios::app|ios::binary);//用输出流对象打开文件，输出写在文件末尾，二进制
        input: flags=0;
        cout<<"输入学号：";
        cin>>stu_num;
		while (strlen(stu_num)!=10)
		{
			cin.clear();//清除输入
            rewind(stdin);//清除缓存区
            cout << "你输入的学号不正确，请输入一个十位数的学号" << endl;
            cout << "学号:";
            cin >> stu_num;
		}
        file1.open("c:\\stu.dat",ios::in | ios::binary );//按读方式打开文件
        while(!file1.eof())//文件未结束时继续循环
		{
            int n;
            file1.read((char *)&s1,sizeof(student));//从文件中读取信息到s1
            n=file1.gcount();
           if(n==sizeof(student))
		   {
			    if(s1.Getstunum()==stu_num)
				flags=1;
		   }
		}
        file1.clear();
        file1.close();
        cout<<"输入姓名："; cin>>stu_name;
        cout<<"输入班级："; cin>>class_name;
        cout<<"输入宿舍："; cin>>house_name;
        s1.Setdata(stu_num,stu_name,class_name,house_name);
        file3.write((char*)&s1,sizeof(s1));
        file3.clear();
        file3.close();
        break;
	case 2: //按学号查找
		system("cls");
		cout<<"请输入学生的学号：";
        cin>>stu_num;
        while (strlen(stu_num)!=10)
		{
			cin.clear();
            rewind(stdin);
            cout << "你输入的学号不正确，请输入一个十位数的学号" << endl;
            cout << "学号:";
            cin >> stu_num;
		}
        file1.open("c:\\stu.dat",ios::in | ios::binary );//按读方式打开文件
        while(!file1.eof())
		{
			int n;
            file1.read((char *)&s1,sizeof(student));
            n=file1.gcount();
			if(n==sizeof(student))
			{
				if(strcmp(s1.Getstunum(),stu_num)==0) //显示学生信息
				{
					s1.Show();
                    flags=1;
				}
			}
		}
        file1.clear();
        file1.close();
        if (flags==0)
			cout << "没有找学号为："<< stu_num <<"的学生记录!" << endl;
            flags=0;
            break;
 case 3: //按宿舍号查找
	 system("cls");
	 cout<<"请输入宿舍号:";
     cin>>house_name;
     file1.open("c:\\stu.dat",ios::in | ios::binary );//按读方式打开文件
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
		 cout << "没有找到宿舍为:"<< house_name <<"的学生记录!" << endl;
     flags=0;
     break;
 case 4: //按姓名查找
	 system("cls");
	 cout<<"请输入学生姓名:";
     cin>>stu_name;
     file1.open("c:\\stu.dat",ios::in | ios::binary );//按读方式打开文件
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
		 cout << "没有找到姓名为:"<< stu_name <<"的学生记录!" << endl;
     flags=0;
     break;
 case 5: //按班级查找
	 system("cls");
	 cout<<"请输入班级名称:";
     cin>>class_name;
	 file1.open("c:\\stu.dat",ios::in | ios::binary );//按读方式打开文件
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
		 cout << "没有找到该班级为:"<< class_name <<"的学生记录!" << endl;
	 flags=0;
     break;
 case 6: //显示全部学生信息
	 system("cls");
	 file1.open("c:\\stu.dat",ios::in | ios::binary);//按读方式打开文件
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
		 cout << "文件没有记录!" << endl;
	 flags=0;
	 break;
 case 7://修改学生信息按学号
	 system("cls");
	 flags=0;
	 cout<<"请输入要修改学生的学号:";
     cin>>stu_num;
     while (strlen(stu_num)!=10)
	 {
		 cin.clear();
		 rewind(stdin);
		 cout << "你输入的学号不正确，请输入一个十位数的学号" << endl;
         cout << "学号:";
         cin >> stu_num;
	 }
	 file1.open("c:\\stu.dat", ios::in );//按读方式打开文件
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
				 cout<<"输入学号："; cin>>stu_num;
                 cout<<"输入姓名："; cin>>stu_name;
                 cout<<"输入班级："; cin>>class_name;
                 cout<<"输入宿舍："; cin>>house_name;
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
		 cout << "没有此学生记录，不能进行修改！" << endl;
		 break;
	 }
	 break;
 case 8://按姓名修改
	 system("cls");
	 flags=0;
	 cout<<"请输入要修改学生的姓名:";
     cin>>stu_name;
	 file1.open("c:\\stu.dat", ios::binary | ios::in |ios::out);//按读方式打开文件
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
				 cout<<"输入学号："; cin>>stu_num;
                 cout<<"输入姓名："; cin>>stu_name;
                 cout<<"输入班级："; cin>>class_name;
                 cout<<"输入宿舍："; cin>>house_name;
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
		 cout << "没有此学生记录，不能进行修改！" << endl;
		 break;
	 }
	 break;
 case 9://按宿舍修改
	 system("cls");
	 flags=0;
	  cout<<"请输入宿舍号:";
     cin>>house_name;
     file1.open("c:\\stu.dat",ios::in | ios::binary );//按读方式打开文件
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
		 cout << "没有找到宿舍为:"<< house_name <<"的学生记录!" << endl;
     flags=0;
	 flags=0;
	 cout<<"请输入要修改学生的姓名:";
     cin>>stu_name;
	 file1.open("c:\\stu.dat", ios::binary | ios::in |ios::out);//按读方式打开文件
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
				 cout<<"输入学号："; cin>>stu_num;
                 cout<<"输入姓名："; cin>>stu_name;
                 cout<<"输入班级："; cin>>class_name;
                 cout<<"输入宿舍："; cin>>house_name;
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
		 cout << "没有此学生记录，不能进行修改！" << endl;
		 break;
	 }
	 break;
 case 10://删除学生信息按学
	 system("cls");
	 {
		 int h=0;
		  cout<<"请输入要删除学生的学号:";
     cin>>stu_num;
     while (strlen(stu_num)!=10)
	 {
		 cin.clear();
		 rewind(stdin);
		 cout << "你输入的学号不正确，请输入一个十位数的学号" << endl;
         cout << "学号:";
         cin >> stu_num;
	 }
		 file1.open("c:\\stu.dat",ios::in | ios::binary);//按读方式打开文
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
	 cout<<"删除成功！"<<endl;
	 break;
	 }
 case 11://删除学生信息按姓名
	 system("cls");
	  {
		 int h=0;
		  cout<<"请输入要删除学生的姓名:";
     cin>>stu_name;
		 file1.open("c:\\stu.dat",ios::in | ios::binary);//按读方式打开文
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
	 cout<<"删除成功！"<<endl;
	 break;
	 }
 case 12://删除学生信息按宿舍
	 system("cls");
	 cout<<"请输入宿舍号:";
     cin>>house_name;
     file1.open("c:\\stu.dat",ios::in | ios::binary );//按读方式打开文件
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
		  cout<<"请输入要删除学生的学号:";
     cin>>stu_num;
     while (strlen(stu_num)!=10)
	 {
		 cin.clear();
		 rewind(stdin);
		 cout << "你输入的学号不正确，请输入一个十位数的学号" << endl;
         cout << "学号:";
         cin >> stu_num;
	 }
		 file1.open("c:\\stu.dat",ios::in | ios::binary);//按读方式打开文
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
	 cout<<"删除成功！"<<endl;
	 break;
	 }
 case 13://清空文件
	 system("cls");
	 file3.open("c:\\stu.dat",ios::trunc);
	 break;
 default: flag = 'n';
	 break;
}
}
cout << "谢谢您的使用!" << endl;

}
