#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define LINF 0x3f3f3f3f3f3f3f3fLL
int a[200010];
int n;
long long dp[200010][2];
long long dfs(int x,int add){
	if(x<=0||x>n)return 0;
	if(dp[x][add] != -LINF) return dp[x][add];
	dp[x][add] = -1;
	long long res = dfs(x+a[x]*(add?1:-1),!add);
	if(res == -1) return -1;
	return dp[x][add] = res+a[x];
} 
int main(){
	cin>>n;
	for(int i = 2;i<=n;i++) cin>>a[i];
	for(int i = 1;i<=n;i++) dp[i][0] = dp[i][1] = -LINF;
	for(int i = 1;i<=n-1;i++){
		++a[1];
		long long ans = dfs(1+i,0);
		if(ans!=-1) ans+=a[1];
		cout<<ans<<endl;
	}
	return 0;
}
//dfs ->  dfs  -> 直到 碰到以前搜过的 -> 上层所有dfs全部返回-1 
//				  直到 出界  -> 上层所有dfs全部增加当前a[x] 
