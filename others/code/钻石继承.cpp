//dev c++ �����顣���� ��vs����û���� 
#include<iostream>
using namespace std;
class A{
	public:
		A(){
			cout<<"c a";
		}
	
};
class B:virtual public A{
	public:
		B(){
			cout<<"c b";
		}
}; 
class C:virtual public A{
	public:
		C(){
			cout<<"c c";
		}
}; 
class D:public B,public C{  //����DΪ������ʱ�Ų���virtual �����D����������Ȼ����ڲ�ͬ��A�İ汾 
	public:
		D(){
			cout<<"c d";
		}
}; 
int main(){
	D d;
} 
