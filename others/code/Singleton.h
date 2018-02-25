#ifndef SINGLETON_H
#define SINGLETON_H

#include<iostream>
#include<algorithm>
#include<list>
using namespace std;



class Log {
	public:
		static Log& Instance();
	private:
		Log ();
		Log (Log const&);
		Log & operator = (const Log&);
		static list<string> m_data;
};


#endif 
