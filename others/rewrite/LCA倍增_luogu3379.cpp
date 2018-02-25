<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
const int maxn = 500100;
const int maxdep = log2(500100)+1;
inline int read(){
	int x = 0,f= 1; char ch = getchar();
	while(ch<'0' || ch>'9') {if(ch == '-') f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9') {x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

struct EDGE{
	int to, nxt;
	EDGE(){}
	EDGE(int a, int b){
		to = a, nxt = b;
	}
}e[maxn<<1];
int head[maxn], cnt, dep[maxn], fa[maxn][26], n, m, r;

void add(int u, int v){
	e[++cnt] = EDGE(v, head[u]);
	head[u] = cnt;
}

void dfs(int d, int now){
	dep[now] = d;
	for(int i = head[now];i;i = e[i].nxt){
		int to = e[i].to;
		if(!dep[to]) fa[to][0] = now,dfs(d+1, to);
	}
}

int LCA(int a, int b){
	// assum depa > depb
	if(dep[a] < dep[b]) swap(a,b);
	while(dep[a] != dep[b]){
		for(int j = maxdep;j>=0;j--){
			if(dep[a]-(1<<j) >= dep[b]) a = fa[a][j];
		}
	}
	if(a!=b){
		for(int j = maxdep;j>=0;j--){
			if(fa[a][j] != fa[b][j]) a = fa[a][j], b = fa[b][j]; 
		}
		a = fa[a][0];
	}
	return a;
}

int main(){
	cin>>n>>m>>r; 
	int st,ed;
	for(int i = 0;i<n-1;i++){
		st = read(), ed = read();
		add(st, ed);
		add(ed, st);
	}
	dfs(1, r);
	//cout<<"here\n";
	for(int j = 1;j<=maxdep;j++){
		for(int i = 1;i<=n;i++){
			fa[i][j] = fa[fa[i][j-1]][j-1];
		}
	}
	for(int i = 0;i<m;i++){
		st = read(), ed = read();
		printf("%d\n", LCA(st,ed));
	}
	return 0;
}

=======
#include<bits/stdc++.h>
using namespace std;
const int maxn = 500100;
const int maxdep = log2(500100)+1;
inline int read(){
	int x = 0,f= 1; char ch = getchar();
	while(ch<'0' || ch>'9') {if(ch == '-') f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9') {x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

struct EDGE{
	int to, nxt;
	EDGE(){}
	EDGE(int a, int b){
		to = a, nxt = b;
	}
}e[maxn<<1];
int head[maxn], cnt, dep[maxn], fa[maxn][26], n, m, r;

void add(int u, int v){
	e[++cnt] = EDGE(v, head[u]);
	head[u] = cnt;
}

void dfs(int d, int now){
	dep[now] = d;
	for(int i = head[now];i;i = e[i].nxt){
		int to = e[i].to;
		if(!dep[to]) fa[to][0] = now,dfs(d+1, to);
	}
}

int LCA(int a, int b){
	// assum depa > depb
	if(dep[a] < dep[b]) swap(a,b);
	while(dep[a] != dep[b]){
		for(int j = maxdep;j>=0;j--){
			if(dep[a]-(1<<j) >= dep[b]) a = fa[a][j];
		}
	}
	if(a!=b){
		for(int j = maxdep;j>=0;j--){
			if(fa[a][j] != fa[b][j]) a = fa[a][j], b = fa[b][j]; 
		}
		a = fa[a][0];
	}
	return a;
}

int main(){
	cin>>n>>m>>r; 
	int st,ed;
	for(int i = 0;i<n-1;i++){
		st = read(), ed = read();
		add(st, ed);
		add(ed, st);
	}
	dfs(1, r);
	//cout<<"here\n";
	for(int j = 1;j<=maxdep;j++){
		for(int i = 1;i<=n;i++){
			fa[i][j] = fa[fa[i][j-1]][j-1];
		}
	}
	for(int i = 0;i<m;i++){
		st = read(), ed = read();
		printf("%d\n", LCA(st,ed));
	}
	return 0;
}

>>>>>>> 1a56048d47b2e3994563d3eb931fec10c5db6184
