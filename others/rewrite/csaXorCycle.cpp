#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m;
vector<pair<int,long long> > node[100010];
int vis[100010],a,b;
long long val[100010];
long long _len;
vector<long long> base;
void add(long long x){
	for(int i = 0;i<base.size();i++){
		x = min(x,x^base[i]);
	}
	if(x) base.push_back(x);
}
void dfs(int x,int fa){
	for(int i = 0;i<node[x].size();i++){
		int to = node[x][i].first;
		long long len = node[x][i].second;
		if(to == fa) continue;
		if(!vis[to]){
			vis[to] = 1;
			val[to] = val[x]^len;
			dfs(to,x);
		}
		else{
			add(val[to]^len^val[x]);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		cin>>a>>b>>_len;
		node[a].push_back(make_pair(b,(long long)_len));
		node[b].push_back(make_pair(a,(long long)_len));
	}
	dfs(1,-1);
	long long ans = 0;
	for(int i = 0;i<base.size();i++){
		ans = max(ans,ans^base[i]);
	}
	cout<<ans<<endl;
	return 0;
}
