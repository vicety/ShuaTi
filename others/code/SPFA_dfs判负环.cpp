// luogu 3385 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x = 0,f= 1; char ch = getchar();
	while(ch<'0' || ch>'9') {if(ch == '-') f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9') {x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
int T,n,m,st,ed,le,flag;
struct EDGE{
	int to,next,len;
	EDGE(){}
	EDGE(int a,int b,int c){
		to = a, next = b, len = c;
	}
}e[400100];
int head[200100],dis[200100],cnt,vis[200100];
void init(){
	memset(head,0,sizeof(head));
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	cnt = 0;
	flag = 0;
}
void add(int u, int v, int w){
	e[++cnt] = EDGE(v,head[u],w);
	head[u] = cnt;
}
void spfa_dfs(int st){
	//cout<<st<<endl;
	if(flag) return;
	vis[st] = 1;
	for(int i = head[st];i;i = e[i].next){
		int to = e[i].to;
		if(dis[st]+e[i].len<dis[to]){
			dis[to] = dis[st]+e[i].len;
			if(vis[to]){
				flag = 1;
				return;
			}
			else spfa_dfs(to);	
		}
	}
	vis[st] = 0;
}
int main(){
	T = read();
	while(T--){
		init();
		n = read(); m = read();
		for(int i = 0;i<m;i++){
			st = read(); ed = read(); le = read();
			add(st,ed,le);
			if(le>=0) add(ed,st,le);
		}
		for(int i = 1;i<=n;i++){
			if(flag) break;
			spfa_dfs(i);
		}
		if(flag) printf("YE5\n");
		else printf("N0\n");
	}
	return 0;
} 