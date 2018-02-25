//http://118.190.20.162/view.page?gpid=T50
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map> 
#include<cstring>
#include<string>
#include<set>
using namespace std;
map<string, int> peopleToIndex;
map<string, int> roleToIndex;
map<string, int> authorityToIndex;
map<string,int> authorityToMax;
set<string> rolestr;
struct PEOPLE {
	int authority[105];
}people[105];
struct ROLE {
	int authority[105];
}role[105];
int pcnt, rcnt, icnt, p, r, u, q, tmp, lv, mark;
string str, str2;
void init() {
	for (int i = 0;i<105;i++) {
		for (int j = 0;j<105;j++) {
			people[i].authority[j] = -1;
			role[i].authority[j] = -1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	cin >> p;
	for (int i = 0;i<p;i++) {
		cin >> str;
		if (str.find(":") != string::npos) {
			lv = str2[str2.length() - 1] - '0';
			str = str.substr(0,str.find(":"));
		}
		else lv = -1;
		authorityToMax[str] = lv;
		rolestr.insert(str);
		authorityToIndex[str] = icnt++;
	}
	cin >> r;
	for (int i = 0;i<r;i++) {
		cin >> str >> tmp;
		roleToIndex[str] = rcnt;
		for (int j = 0;j<tmp;j++) {
			cin >> str2;
			if (str2.find(":") != string::npos) {
				lv = str2[str2.length() - 1] - '0';
				str2 = str2.substr(0,str2.find(":"));
			}
			else {
				lv = 0;
			}
			role[rcnt].authority[authorityToIndex[str2]] = lv;
		}
		rcnt++;
	}
	cin >> u;
	for (int i = 0;i<u;i++) {
		cin >> str >> tmp;
		peopleToIndex[str] = pcnt;
		for (int j = 0;j<tmp;j++) {
			cin >> str2;
			int roleIndex = roleToIndex[str2];
			for (int k = 0;k<105;k++) {
				if (role[roleIndex].authority[k] != -1) {
					people[pcnt].authority[k] = max(people[pcnt].authority[k], role[roleIndex].authority[k]);
				}
			}
		}
		pcnt++;
	}
	cin >> q;

	for (int i = 0;i<q;i++) {
		mark = 0;
		cin >> str >> str2;
		if (str2.find(":") != string::npos) {
			lv = str2[str2.length() - 1] - '0';
			str2 = str2.substr(0,str2.find(":"));
			
		}
		else {
			lv = 0;
			mark = 1;
		}
		if (rolestr.find(str2) == rolestr.end()) {
			cout << "false\n";
			continue;
		}
		int curlv = people[peopleToIndex[str]].authority[authorityToIndex[str2]];
		if (mark) {
			if (curlv == -1) cout << "false\n";
			else if(authorityToMax[str2] == -1) cout<<"true\n";
			else cout << curlv << endl;
			continue;
		}
		if (curlv < lv) {
			cout << "false\n";
			continue;
		}
		cout << "true\n";;
	}
	return 0;
}

