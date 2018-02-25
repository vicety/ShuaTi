#include<bits/stdc++.h>
using namespace std;
const int maxn = 300010;
struct EDGE{
	int to,next;
	EDGE(){
		
	}
	EDGE(int a,int b){
		to = a,next = b;
	}
}e[maxn<<1];
int head[maxn],cnt,rec[maxn],fa[maxn],n,m,tx,ty,td,d[maxn],ocnt,pos = -1;
int find(int x){
	return fa[x] == x?x:fa[x] = find(fa[x]);
}
void merge(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx == fy) return;
	fa[fx] = fa[fy];
}
void add(int u,int v){
	e[cnt] = EDGE(v,head[u]);
	head[u] = cnt++;
}
void dfs(int x,int fa){
	//cout<<"dfs at: "<<x<<endl;
	//cout<<head[x]<<" || "<<e[head[x]].next<<" || "<<e[head[x]].to<<endl;
	for(unsigned i = head[x];i!=-1;i = e[i].next){
		int to = e[i].to;
		//cout<<to<<endl;
		if(to == fa) continue;
		//cout<<"to: "<<to<<endl;
		dfs(to,x);
		if(d[to] == 1){
			rec[cnt++] = i/2+1;
			if(d[x] != -1) d[x] ^= 1;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++) fa[i] = i,head[i] = -1;
	for(int i = 1;i<=n;i++){
		scanf("%d",&d[i]);
		if(d[i] == 1) ocnt++;
		if(d[i] == -1) pos = i;
	} 
	for(int i = 0;i<m;i++){
		scanf("%d%d",&tx,&ty);
		if(find(tx) != find(ty)){
			add(tx,ty);
			add(ty,tx);
			merge(tx,ty);
			//cout<<"here\n";
		}
	} 
	cnt = 0;
	if(ocnt%2 && pos == -1) return 0*printf("-1");
	if(pos == -1)dfs(1,-1);
	else dfs(pos,-1);
	printf("%d\n",cnt);
	for(int i = 1;i<=cnt;i++) printf("%d\n",rec[i-1]);
	return 0;
}
