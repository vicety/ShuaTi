#include<iostream>
using namespace std;
class A{
	public:
		A(){
			a = -1;
		}
		explicit A(int _a){  //���� explicit �����һ�����޷�����ͨ�� 
			a = _a;
		}
		explicit A(const A& b){
			a = b.a;
		}
		void print(){
			cout<<a<<endl;
		}
	private:
		int a;
};
int main(){
	A a;
	A b = 12; //  �ȼ��� A tmp(12); A b = tmp; 
	b.print();
}
