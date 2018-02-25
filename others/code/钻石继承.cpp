//dev c++ 好像会抽。。。 用vs运行没问题 
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
class D:public B,public C{  //仅当D为最终类时才不用virtual 否则从D派生的类仍然会存在不同的A的版本 
	public:
		D(){
			cout<<"c d";
		}
}; 
int main(){
	D d;
} 
