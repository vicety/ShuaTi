#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 110,maxm = 50010,inf = 0x3f3f3f3f;
int s,t,len = 1,g[maxn];
struct EDGE{
	int to,cap,next;
}e[maxm];
int p[maxn],q[maxn],d[maxn];
void add(int u,int v,int w){
	e[++len] = (EDGE){v,w,g[u]},g[u] = len;
	e[++len] = (EDGE){u,0,g[v]},g[v] = len;
}
bool bfs(){
	int l = 1,r = 1,x,i;
	memset(d,0,sizeof(d));
	d[s] = 1,q[1] = s;
	while(l<=r){
		x = q[l++];
		for(i = g[x];i;i = e[i].next)
			if(e[i].cap && !d[e[i].to]) // 选取非零未被访问点 
				d[e[i].to] = d[x] + 1,q[++r] = e[i].to; //d 应该就是层次 r为队列中数量 l为bfs过的数量 
	}
	return d[t];
}
int dfs(int x,int y){
	if(x == t||y == 0) return y;
	int flow = 0;
	for(int &i = p[x];i;i = e[i].next){
		if(!e[i].cap || d[e[i].to]!= d[x]+1) continue; // 选取下一层的点 cap暂时还没懂
		int f = dfs(e[i].to,min(y,e[i].cap));
		flow+=f,y-=f;
		e[i].cap-=f,e[i^1].cap +=f;
		if(!y) break; 
	}
	return flow;
} 
int dinic(){
	int maxflow = 0;
	while(bfs()){
		//printf("here\n"); 
		memcpy(p,g,sizeof(g)); 
		maxflow+=dfs(s,inf);
	}
	return maxflow;
}

int Case,n,m,sum;
// 大概是 start terminate 
int main(){
	scanf("%d",&Case);
	for(int tt = 1;tt<=Case;tt++){
		sum = 0; len = 1;
		memset(g,0,sizeof(g));
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&m),t = n+m+1;
		for(int j,i = 1;i<=n;i++){
			scanf("%d",&j),add(s,i,j),sum+=j;
		}
		for(int j,i = 1;i<=m;i++){
			scanf("%d",&j),add(n+i,t,j);
		}
		for(int k,j,i = 1;i<=n;i++){
			scanf("%d",&k);
			while(k--){
				scanf("%d",&j);
				add(i,n+j+1,inf);
			}
		}
		for(int k,i = 1;i<=m;i++){
			for(int j = 1;j<=m;j++){
				scanf("%d",&k);
				if(k) add(n+i,n+j,inf);
			}
		}
		printf("%d\n",sum-dinic());
	}
	return 0;
} 
