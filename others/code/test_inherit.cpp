#include<iostream>
using namespace std;
class A{
	public:
		virtual void show() = 0;
		A(){
			cout<<"constructing A\n";
		}
};
class Ab_B{
	public:
		Ab_B(){
			cout<<"constructing B\n";
		}
};
class Ab_C{
	public:
		Ab_C(){
			cout<<"constructing C\n";
		}
};
class E{
	public:
		E(){
			cout<<"constructing E\n";
		}
	
};
class D: public A,public Ab_B,public Ab_C{ //按参数表顺序创建 
	public:
		virtual void show() = 0;
		D(){
			cout<<"constructing D\n";
		}
	private:
		E e; //先创建类内对象 
};
class F:public D{
	public:
		virtual void show(){
			cout<<"This is F\n";
		}
		F(){
			cout<<"constructing F\n";
		}
};
class G:public F{
	public:
		void show(){
			cout<<"This is G\n";
		}
		G(){
			cout<<"constructing G\n";
		}
};
int main(){
	G g;
}
