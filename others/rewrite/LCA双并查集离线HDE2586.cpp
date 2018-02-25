#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 40010; 
int head[maxn],cnt,qcnt,qhead[maxn],t,n,m,dir[maxn];
int vis[maxn],fa[maxn];
struct EDGE{
	int to,next,len;
	EDGE(){
		
	}
	EDGE(int _to,int _next,int _len){
		to = _to,next = _next,len = _len;
	}
}e[maxn<<1];
struct QEDGE{
	int from,to,lca,next;
	QEDGE(){
	}
	QEDGE(int _from,int _to,int _next){
		from = _from;
		lca = -1;
		to = _to;
		next = _next;
	}
}q[maxn<<1]; 
void add(int u,int v,int len){
	e[cnt] = EDGE(v,head[u],len);
	head[u] = cnt++;
}
void qadd(int u,int v){
	q[qcnt] = QEDGE(u,v,qhead[u]);
	qhead[u] = qcnt++;
}
int find(int x){
	return fa[x] == x?x:find(fa[x]);
}
void merge(int u,int v){
	//合并顺序问题
	int uf = find(u);
	int vf = find(v);
	if(uf == vf) return;
	fa[uf] = vf; 
}
void LCA(int x,int fa){
	vis[x] = 1;
	for(int i = head[x];i!=-1;i = e[i].next){
		int to = e[i].to;
		if(fa == to) continue;
		dir[to] = dir[x] + e[i].len;
		LCA(to,x);
		merge(to,x);
	}
	for(int i = qhead[x];i!=-1;i = q[i].next){
		int to = q[i].to;
		if(vis[to]){
			q[i].lca = find(to); 
			q[i^1].lca = q[i].lca; 
		}
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		cnt = 0;
		qcnt = 0;
		for(int i = 1;i<=n;i++) fa[i] = i;
		memset(head,-1,sizeof(head));
		memset(qhead,-1,sizeof(qhead));
		memset(vis,0,sizeof(vis));
		for(int i = 1;i<=n-1;i++){
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			add(x,y,w);
			add(y,x,w);
		}
		for(int i = 1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			qadd(x,y);
			qadd(y,x);
		}
		LCA(1,-1);
		for(int i = 0;i<m;i++){
			int tmp = i*2,from = q[tmp].from,to = q[tmp].to,lca = q[tmp].lca;
			printf("%d\n",dir[from]+dir[to]-2*dir[lca]);
		}
	}
	return 0;
}
