#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int maxn = 100100;
const LL inf = 2e17; 
int n;
LL now[maxn], req[maxn];
struct NODE {
	int fa;
	vector<int> son;
	LL val; // val need from fa
}node[maxn];
void add(int from, int to, int val) {
	node[from].son.push_back(to);
	node[to].fa = from;
	node[to].val = val;
}
int main() {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) scanf("%I64d", &now[i]);
	for (int i = 1;i <= n;i++) scanf("%I64d", &req[i]);
	for (int i = 1;i <= n - 1;i++) {
		int from, val;
		scanf("%d%I64d", &from, &val);
		add(from, i + 1, val);
	}
	//for(int i = 1;i<=n)node[1].fa = -1;
	for (int i = 1;i <= n;i++) {
		if (node[i].son.empty()) {
			int nownode = i;
			while (node[nownode].fa != 0) {
				int fa = node[nownode].fa;
				//cout << i << " | " << fa << endl;
				if (req[nownode] >= now[nownode]) now[fa] -= node[nownode].val*(req[nownode] - now[nownode]);
				else now[fa] += now[nownode] - req[nownode];
				now[nownode] = req[nownode];
				nownode = fa;
				if(now[fa] > inf || now[fa] < -inf){
					cout<<"NO"<<endl;
					return 0;
				}
			}
			//cout << now[1] << endl;
		}
	}
	int rt;
	for (int i = 1;i <= n;i++) if (node[i].fa == 0) {
		rt = i;
		break;
	}
	cout << (now[rt] >= req[rt] ? "YES" : "NO") << endl;

	return 0;
}
