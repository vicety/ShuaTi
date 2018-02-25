#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
class Log {
public:
	static Log& Instance() {
		static Log newLog; //确保了只会出现一个newLog 
		return newLog;
	}
	//virtual void Write(char const *logline);
	//virtual bool SaveTo(char const* filename);
private:
	Log () {
		cout << "constructing" << endl;
	}
	Log (Log const&) {

	};
	Log & operator = (const Log&) {
		
		//禁止赋值
	};
	static list<string> m_data;
};
int main() {
	//Log &singalinstance = Log::Instance();
	//Log &trysecond = Log::Instance();
}
