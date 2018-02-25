// HDU 2680 优先队列也是可以在某点break的。。。 思维江化 
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 1010;
const int maxm = 20010;
const int INF = 0x3f3f3f3f;
int n,m,s,q,p,t,cnt,wsize;
//int w[maxn];
struct EDGE{
	int to,next,value;
	EDGE(){}
	EDGE(int u,int v,int w){
		to = u;
		next = v;
		value = w;
	}
}e[maxm];
struct NODE{
	int ind,value;
	NODE(){}
	NODE(int a,int b){
		ind = a;
		value = b;
	}
};
struct CMP{
	bool operator()(const NODE& a,const NODE& b){
		return a.value>b.value; //小在上 
	}
};
priority_queue<NODE, vector<NODE>,CMP >qu; //全部获得 
int head[maxm<<1];
int vis[maxn];
int dis[maxn];
void add(int u,int v,int w){
	e[++cnt] = EDGE(v,head[u],w);
	head[u] = cnt;
}

void dij(){
	dis[s] = 0;
	qu.push(NODE(s,0));
	while(!qu.empty()){
		int st = qu.top().ind;
		qu.pop();
		if(vis[st]) continue;
		vis[st] = true;
		for(int i = head[st];i;i = e[i].next){
			int to = e[i].to;
			if(!vis[to]){
				if(dis[st]+e[i].value<dis[to]){
					dis[to] = dis[st]+e[i].value;
					qu.push(NODE(to,dis[to]));
				}
			}
		}
	}
}
int main(){
	while(~scanf("%d%d%d",&n,&m,&s)){
		for(int i = 0;i<maxn;i++){
			dis[i] = INF;
			vis[i] = false;
		}
		memset(head,0,sizeof(head));
		cnt = 0;
		for(int i = 1;i<=m;i++){
			scanf("%d%d%d",&p,&q,&t);
			if(p == q) continue;
			add(q,p,t); // 注意是单向边。。。 
		}
		dij();
		scanf("%d",&wsize);
		int index = -1;
		int minn = INF;
		for(int i = 0;i<wsize;i++){
			scanf("%d",&index);
			minn = min(minn,dis[index]);
		}
		if(minn!=INF)printf("%d\n",minn);
		else printf("-1\n");
	}
	return 0;
} 
