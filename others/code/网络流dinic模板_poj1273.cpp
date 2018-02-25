#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 205;
const int INF = 0x3f3f3f3f;
struct EDGE{
	int to, next, cap, flow;
	EDGE(){}
	EDGE(int a, int b, int c, int d){
		to = a, next = b, cap = c, flow = d;;
	}
}e[410];
int head[205], cnt, lv[205],m ,n;
void add(int from, int to, int cap){
	e[++cnt] = EDGE(to, head[from], cap, 0);
	head[from] = cnt;
	e[++cnt] = EDGE(from, head[to], 0, 0);
	head[to] = cnt;
}
int bfs(){
	queue<int> q;
	q.push(1);
	memset(lv,0,sizeof(lv));
	lv[1] = 1;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		for(int i = head[front];i;i = e[i].next){
			int to = e[i].to;
			if(!lv[to] && e[i].cap-e[i].flow){
				lv[to] = lv[front]+1;
				q.push(to);
			}
		}
	}
	return lv[m];
}
int dfs(int now, int a){
	int flow = 0,f;
	if(now == m) return a;
	for(int i = head[now];i;i = e[i].next){
		int to = e[i].to;
		if(lv[to] == lv[now]+1 && (f = dfs(to,min(a,e[i].cap-e[i].flow)))){
			e[i].flow += f;
			e[i^1].flow -= f;
			flow += f;
			a -= f;
			if(!a) break;
		}
	}
	return flow;
} 
int dinic(){
	int ans = 0;
	while(bfs()){
		ans += dfs(1,INF);
	}
	return ans;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		cnt = 1;
		memset(head,0,sizeof(head));
		for(int i = 1;i<=n;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		printf("%d\n",dinic());	
	}
	return 0;	
}