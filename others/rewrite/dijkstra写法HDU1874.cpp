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
void dijkstra(int now){
	int flag = 0;
	while(true){
		vis[now] = 1;
		for(int i = head[now];i!=-1;i = e[i].next){
			int to = e[i].to;
			dis[to] = min(dis[to],dis[now]+e[i].len);
		}
		//if(flag) break;
		int mmin = 0x3f3f3f3f;
		int ind = -1;
		for(int i = 0;i<n;i++){
			if(!vis[i]){
				if(dis[i]<mmin){
					mmin = dis[i];
					ind = i;
				}
			}
		}
		if(ind == -1) break;
		else now = ind; 
	}
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
		dijkstra(st);
		printf("%d\n",dis[ed] == 0x3f3f3f3f?-1:dis[ed]);
	}
	return 0;
}
