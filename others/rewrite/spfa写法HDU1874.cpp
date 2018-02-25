#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,st,ed,le;
struct EDGE{
	EDGE(int a,int b,int c){
		to = a;
		next = b;
		len = c;
	}
	EDGE(){}
	int to,next,len;
}e[1010];
int head[2020],cnt,vis[210],dis[210];
void add(int u,int v,int len){
	e[cnt] = EDGE(v,head[u],len);
	head[u] = cnt++;
}
bool spfa_dfs(int x){
	vis[x] = 1;
	for(int i = head[x];i!=-1;i = e[i].next){
		int to = e[i].to;
		if(dis[x]+e[i].len<dis[to]){
			dis[to] = dis[x]+e[i].len;
			if(!vis[to]){
				if(spfa_dfs(to)) return 1;
			}
			else return 1;
		}
	}
	vis[x] = 0;
	return 0;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		cnt = 0;
		for(int i = 0;i<n;i++){
			dis[i] = 0x3f3f3f3f;
			head[i] = -1;
		}
		memset(vis,0,sizeof(vis));
		for(int i = 0;i<m;i++){
			scanf("%d%d%d",&st,&ed,&le);
			add(st,ed,le);
			add(ed,st,le);
		}
		scanf("%d%d",&st,&ed);
		dis[st] = 0;
		spfa_dfs(st);
		printf("%d\n",dis[ed] == 0x3f3f3f3f?-1:dis[ed]);
	}
	return 0;
}
