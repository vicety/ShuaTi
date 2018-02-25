#include<bits/stdc++.h>
using namespace std;
vector<int> v[200200];
int gcd(int a ,int b){
	if(b == 0) return a;
	else return gcd(b,a%b);
}
int num[200200],n;
int vis[200200];
int from,to;
int u[200200],nu[200200];
void dfs(int x){
	vis[x] = 1;
	for(int i = 0;i<v[x].size();i++){
		int to = v[x][i];
		if(vis[to]) continue;
		u[to] = max(gcd(u[x],num[to]),gcd(nu[x],0)),nu[to] = gcd(nu[x],num[to]);
		dfs(to);
	}
}
int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d",&num[i]);
	for(int i = 0;i<n-1;i++){
		scanf("%d%d",&from,&to);
		v[from].push_back(to);
		v[to].push_back(from);
	} 
	u[1] = 0,nu[1] = num[1],vis[1] = 1;
	//for(int i = 0;i<v[1].size();i++) dfs(v[1][i],1);
	dfs(1);
	printf("%d\n",num[1]);
	for(int i = 2;i<=n;i++) printf("%d\n",max(u[i],nu[i]));
	return 0;
} 
