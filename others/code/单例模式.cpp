#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
class Log {
public:
	static Log& Instance() {
		static Log newLog; //ȷ����ֻ�����һ��newLog 
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
		
		//��ֹ��ֵ
	};
	static list<string> m_data;
};
int main() {
	//Log &singalinstance = Log::Instance();
	//Log &trysecond = Log::Instance();
}
