#include <iostream>
#include<string>
using namespace std;
class A { 
public: 
    void f(int i){cout<<"��A"<<endl;}; 
};
class B: public A { 
public:
    virtual void f(int i){cout<<"��B"<<endl;}
};
class C: public B {
public: 
    void f(int i){cout<<"��C"<<endl;}
};
//һ����ĳ����Ա��������Ϊ�麯�������ڼ̳���ϵ�о���ԶΪ�麯���� 
class D: public C{
public:
    void f (int){cout<<"��D"<<endl;}
};
int main(){
    A *pA,a;
    B *pB, b;    C c;    D d;
    pA=&a;    pA->f(1);		//����A::f
    pB=&b;    pB->f(1);		//����A::f
    pB=&c;    pB->f(1);		//����A::f
    pB=&d;    pB->f(1);		//����A::f
    system("pause");
    return 0;
}
