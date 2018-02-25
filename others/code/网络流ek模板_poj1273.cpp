#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 205;
int cap[205][205], pre[205], n, m, a[205];
int bfs(){
	queue<int> q;
	q.push(1);
	memset(a,0,sizeof(a));
	a[1] = INF;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		for(int i = 1;i<=m;i++){
			if(!a[i] && cap[front][i]){
				a[i] = min(a[front], cap[front][i]);
				pre[i] = front;
				q.push(i);
			}
		}
	}
	return a[m];
}
int ek(){
	int ans = 0;
	while(bfs()){
		ans += a[m];
		for(int i = m;i!=1;i = pre[i]){
			cap[pre[i]][i] -= a[m];
			cap[i][pre[i]] += a[m];
		}
	}
	return ans;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(cap,0,sizeof(cap));
		for(int i = 1;i<=n;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			cap[u][v] += w;
		}
		printf("%d\n",ek());	
	}
	return 0;	
}