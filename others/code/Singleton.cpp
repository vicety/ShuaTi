#include"Singleton.h"
#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

Log& Log::Instance(){
	static Log newLog; //ȷ����ֻ�����һ��newLog 
		return newLog;
}
Log::Log(){
	cout << "constructing" << endl;
}
Log::Log(Log const&){
	//��ֹ��ֵ
}
Log& Log::operator =(const Log&){
	//��ֹ��ֵ
};
int main() {
	Log &singalinstance = Log::Instance();
	//Log &trysecond = Log::Instance();
}
