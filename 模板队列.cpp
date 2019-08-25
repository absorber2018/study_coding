#include <malloc.h>
#include<iostream>
#define MAX 10
using namespace std;

struct student
{
int data;
char name[10];
};
void  input(student *s) {
cin >>s->data>>s->name;
}
void output(student s) {
cout << s.data << " " << s.name << endl;
}

template<class T>
class Queue {
private:
T stu[MAX];
int head;
int rear;
int count;
public:
void creat() {
head = 0;
rear = 0;
count = 0;
}
void inqueue(){
T t;
input(&t);
if (rear + 1 % MAX == head)
{
cout << "" << endl;
exit(0);
}
else {
rear = (rear + 1) % MAX;
stu[rear] = t;
count++;
}
}

void outqueue() {
int i = 1, n = 4;
T t;
while (n)
{
if (count == 0)
{
cout << "" << endl;
exit(0);
}
head = (head + 1) % MAX;
t = (stu[head]);
output(t);
i++;
n--;
count--;
}
}

void show() {
int m, i;
m = (head + 1) % MAX;
for (i = 1; i <= count; i++)
{
output(stu[m]);
m = (m + 1) % MAX;
}
}

};

int main()
{
Queue<student> s;
s.creat();
for (int i = 0; i < 7; i++)
{
s.inqueue();
}
cout<<"Finish service:"<<endl;
s.outqueue();
cout<<"Waiting service:"<<endl;
s.show();
return 0;
}
