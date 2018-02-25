#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
vector<int> v;
struct EDGE{
	int to,next,len;
	EDGE(){
	}
	EDGE(int a,int b,int c){
		to = a,next = b,len = c;
	}
}e[maxn<<1];
int vis[maxn],st,ed,cnt,head[maxn],val[maxn],len;
void add(int u,int v,int len){
	e[++cnt] = EDGE(v,head[u],len);
	head[u] = cnt;
}
void add(int x){
	for(int i = 0;i<(int)v.size();i++){
		x = min(x,x^v[i]);
	}
	if(x) v.push_back(x);
}
void dfs(int x,int now){
	vis[x] = 1;
	for(int i = head[x];i;i = e[i].next){
		int to = e[i].to;
		if(vis[to]) add(val[to]^now^e[i].len);
		else{
			val[to] = now^e[i].len;
			dfs(to,val[to]);
		} 
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0;i<m;i++){
		scanf("%d%d%d",&st,&ed,&len);
		add(st,ed,len);
		add(ed,st,len);
	}
	dfs(1,0);
	for(int i = 0;(int)i<v.size();i++){
		val[n] = min(val[n],val[n]^v[i]);
	}
	return 0*printf("%d",val[n]);
}
