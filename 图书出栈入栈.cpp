#include <iostream>
#include <malloc.h>
#define MAXLEN 50
#define N 5;
typedef int datatype;
using namespace std;

typedef struct
{
	datatype List[MAXLEN];
	int len;
}Seqlist;
struct book
{
    string num[N];
    string name[20];
    string author[20];
    string press[20];
    float  price;
};
class books
{
private:
    book b1[N];
public:
    void inset();
    void print();
};
