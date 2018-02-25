#include"Singleton.h"
#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

Log& Log::Instance(){
	static Log newLog; //确保了只会出现一个newLog 
		return newLog;
}
Log::Log(){
	cout << "constructing" << endl;
}
Log::Log(Log const&){
	//禁止赋值
}
Log& Log::operator =(const Log&){
	//禁止赋值
};
int main() {
	Log &singalinstance = Log::Instance();
	//Log &trysecond = Log::Instance();
}
