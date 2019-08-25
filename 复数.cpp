#include <iostream>
using namespace std;
class Complex
{
private:
	float a,b;
public:
	Complex add(Complex c);
    Complex sub(Complex c);
	void  show() const ;
    Complex(float a1=0,float b1=0);
};
Complex::Complex(float a1,float b1)
{
    a=a1;
    b=b1;
}
const Complex fun(Complex c1,char op,Complex c2)
{
  Complex c;
  if(op=='+')
	  c=c1.add(c2);
  if(op=='-')
	  c=c1.sub(c2);
  return c;
}
int main()
{
  Complex c1(3.2),c2(2,4.1),c3(c1),c4;
  float a,b;
  cin>>a>>b;
  Complex c5(a,b);
  fun(c1,'+',c2).show();
  c4=fun(c2,'-',c3);
  c4.show();
  fun(c4,'+',c5).show();
  return 0;
}
Complex Complex::add(Complex c)
{
   Complex r;
   r.a=this->a+c.a;
   r.b=this->b+c.b;
   return r;
}
Complex Complex::sub(Complex c)
{

	Complex r;
	r.a=this->a-c.a;
    r.b=this->b-c.b;
    return r;
}
void  Complex::show()const
{
   cout<<a<<"+"<<b<<"i"<<endl;
}
