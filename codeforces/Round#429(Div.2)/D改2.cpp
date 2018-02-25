#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> 
#include<cstring>
#include<set>
#include<stack>
#define CLR(X,A) memset(X,A,sizeof(X))
using namespace std;
const int maxn = 300010;
set<int> ans;
set<int>::iterator it;
struct EDGE {
	int to, next;
	int v;
	//bool vis;
	EDGE() {
		v = 0;
		//vis = false;
	}
	EDGE(int _to, int _next) {
		to = _to;
		next = _next;
	}
}e[maxn << 1];
int d[maxn], head[maxn], vis[maxn], cnt, n, m, st, ed, to, dcnt, jmp, flag,tmp;
void add(int u, int v) {
	e[cnt] = EDGE(v, head[u]);
	e[cnt].v = 0;
	head[u] = cnt++;
}

//用vis来记录路径 
void ddfs(int x, int fa) {
	vis[x] = 1;
	for (int i = head[x];i != -1;i = e[i].next) {
		//cout<<"here\n";
		to = e[i].to;
		if (to == fa) continue;
		if (!vis[to]) {
			jmp = 0;
			ddfs(to, x);
			if (jmp) e[i].v = 1;//cout<<"here when x is: "<<x<<"\n";

		}
	}
	if (d[x] == 1) jmp = 1;
}
stack<int> s;
bool dfs(int x, int fa) {
	//cout<<x<<endl;
	vis[x] = true;
	for (int i = head[x];i != -1;i = e[i].next) {
		to = e[i].to;
		if (to == fa) continue;
		if (!vis[to]) {
			s.push(i / 2);
			if (d[to] == -1) return true;
			if (dfs(to, x)) return true;
			s.pop();
		}
	}
	return false;
}
void initlink() {
	for (int i = 1;i <= n;i++) {
		if (d[i] == 1) {
			tmp = i;
			//cout<<"tmp: "<<tmp;
			break;
		}
	}
	ddfs(tmp, -1);
	for (int i = 0;i<2 * m;i++) {
		if (e[i].v) {
			//cout<<i<<endl;
			ans.insert(i / 2);
		}
	}
	//cout<<"size: "<<ans.size()<<endl;
	if (dcnt % 2 == 0) return;
	else {
		for (int i = 1;i <= n;i++) {
			if (d[i] == 1) {
				tmp = i;
				//cout<<"tmp: "<<tmp;
				break;
			}
		}
		CLR(vis, 0);
		dfs(tmp, -1);
		while (!s.empty()) {
			tmp = s.top();
			ans.insert(tmp);
			s.pop();
		}
	}
	//cout<<"size: "<<ans.size()<<endl;
}

int main() {
	CLR(head, -1);
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &d[i]);
		if (d[i] == 1) dcnt++;
		if (d[i] == -1) flag = 1;
	}
	if (dcnt % 2 && !flag) return 0 * printf("-1");
	for (int i = 0;i<m;i++) {
		scanf("%d%d", &st, &ed);
		add(st, ed);
		add(ed, st);
	}
	initlink();
	printf("%d\n", ans.size());
	for (it = ans.begin();it != ans.end();it++) {
		printf("%d\n", (*it) + 1);
	}
}
