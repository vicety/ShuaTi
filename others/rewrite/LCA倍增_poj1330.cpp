<<<<<<< HEAD
// poj 1330 
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 10010;
const int maxf = 16;
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
int head[maxn], cnt, dep[maxn], fa[maxn][26], cas, st, ed, n, rt, inm[maxn];

void add(int u, int v){
	e[++cnt] = EDGE(v, head[u]);
	head[u] = cnt;
}

void dfs(int d, int now){
	dep[now] = d;
	for(int i = head[now];i;i = e[i].nxt){
		int to = e[i].to;
		if(!dep[to]) fa[to][0] = now, dfs(d+1, to);
	}
}

int LCA(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	for(int j = maxf; j>=0; j--){
		if(dep[a] - (1<<j) >= dep[b]) a = fa[a][j];
	}
	if(a != b){
		for(int j = maxf; j>= 0; j--){
			if(fa[a][j] != fa[b][j]) a = fa[a][j], b = fa[b][j];
		}
		a = fa[a][0];
	}
	return a;
}

void init(){
        for(int i = 0;i<maxn;i++) inm[i] = 1;
	cnt = 0;
	memset(head, 0, sizeof(head));
	memset(fa, 0 ,sizeof(fa));
	memset(dep, 0 ,sizeof(dep));
}

int main(){
	cas = read();
	while(cas--){
		init();
		n = read();
		for(int i = 0;i<n-1;i++){
			st = read(), ed = read();
			add(st, ed), add(ed, st);
                        inm[ed] = 0;
		}
		for(int i = 1;i<=n;i++){
                        if(inm[i]){
				rt = i;
				break;
			} 
		}
		dfs(1, rt);
		//cout<<rt<<" "<<"here"<<endl;
		for(int j = 1; j <= maxf; j++){
			for(int i = 1;i<=n;i++){
				fa[i][j] = fa[fa[i][j-1]][j-1];
			}
		}
		st = read(), ed = read();
		printf("%d\n", LCA(st, ed));
	}
	return 0;
}
=======
// poj 1330 
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 10010;
const int maxf = 16;
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
int head[maxn], cnt, dep[maxn], fa[maxn][26], cas, st, ed, n, rt, vis[maxn];

void add(int u, int v){
	e[++cnt] = EDGE(v, head[u]);
	head[u] = cnt;
}

void dfs(int d, int now){
	dep[now] = d;
	for(int i = head[now];i;i = e[i].nxt){
		int to = e[i].to;
		if(!dep[to]) fa[to][0] = now, dfs(d+1, to);
	}
}

int LCA(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	for(int j = maxf; j>=0; j--){
		if(dep[a] - (1<<j) >= dep[b]) a = fa[a][j];
	}
	if(a != b){
		for(int j = maxf; j>= 0; j--){
			if(fa[a][j] != fa[b][j]) a = fa[a][j], b = fa[b][j];
		}
		a = fa[a][0];
	}
	return a;
}

void init(){
	for(int i = 0;i<maxn;i++) vis[i] = 1;
	cnt = 0;
	memset(head, 0, sizeof(head));
	memset(fa, 0 ,sizeof(fa));
	memset(dep, 0 ,sizeof(dep));
}

int main(){
	cas = read();
	while(cas--){
		init();
		n = read();
		for(int i = 0;i<n-1;i++){
			st = read(), ed = read();
			add(st, ed), add(ed, st);
			vis[ed] = 0;
		}
		for(int i = 1;i<=n;i++){
			if(vis[i]){
				rt = i;
				break;
			} 
		}
		dfs(1, rt);
		//cout<<rt<<" "<<"here"<<endl;
		for(int j = 1; j <= maxf; j++){
			for(int i = 1;i<=n;i++){
				fa[i][j] = fa[fa[i][j-1]][j-1];
			}
		}
		st = read(), ed = read();
		printf("%d\n", LCA(st, ed));
	}
	return 0;
}
>>>>>>> 1a56048d47b2e3994563d3eb931fec10c5db6184
