#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,string> dict;
map<string,string>::iterator it;
string s,ss,sss;
int main()
{
	ios::sync_with_stdio(false);
	while(getline(cin,s))
	{
		if(s.find(' ')!=string::npos)
		{
			int t = s.find(' ');
			ss = s.substr(0,t);
			sss = s.substr(t+1,s.size()-1);
			dict[sss] = ss;
		}
		else if(s.size()>=1)
		{
			it = dict.find(s);
			if(it!=dict.end()) cout<<it->second<<endl;
			else cout<<"eh"<<endl;
		}
	}
	return 0;
} 
