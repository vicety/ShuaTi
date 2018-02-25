#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 205;
int mark[maxn], match[maxn];
int n, m, num, to;
vector<int> e[maxn];
bool dfs(int st){
	for(int i = 0;i<e[st].size();i++){
		int to = e[st][i];
		if(!mark[to]){
			// 防止无限递归， 已经用于腾出位置的则不必考虑 
			mark[to] = 1;
			if(!match[to] || dfs(match[to])){
				match[to] = st;
				return true;
			}
		}
	}
	return false;
}
int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>num;
		for(int j = 1;j<=num;j++){
			cin>>to;
			e[i].push_back(to);
		}
	}
	int ans = 0;
	for(int i = 1;i<=m;i++){
		memset(mark,0,sizeof(mark));
		if(dfs(i)) ans++;
	}
	cout<<ans<<endl;
	return 0;
} 
