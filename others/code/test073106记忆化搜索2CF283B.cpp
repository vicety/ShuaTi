#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 200010;
typedef long long LL;
LL a[maxn],f[2][maxn],n,b[2][maxn],vis[2][maxn];
LL dfs(int i,int k,LL d = 0){
	if(vis[k][i]){
		b[k][i] = -1;
		return f[k][i] = 0;
	}
	vis[k][i] = 1;
	if(!f[k][i]){  // 如果这个点暂时是成功的，还未被纪录值 
		int y = i+(k?a[i]:-a[i]);
		if(y>n||y<=1) d= 0;
		else d = dfs(y,k^1); // d成功为非零 否则为0
		f[k][i] = d+a[i]; //向前推导 // f 即是 y  // 无论成不成功 都按照成功纪录f 
		if(y>=1 && y<=n && b[k^1][y]) b[k][i] = -1; //如果子状态推导得到的结论为不行 则本状态亦不行 
	}
	//否则这个点已经确定是成功的，就不用再跑一遍dfs
	vis[k][i] = 0; //无论是否成功， 向后退
	return f[k][i]; 
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	scanf("%d",&n);
	for(int i = 2;i<=n;i++) scanf("%I64d",&a[i]);
	//for(int i = 1;i<=n;i++) dp[i][0] = dp[i][1] = -LINF;
	b[0][1] = b[1][1] = -1;
	for(int i = 2;i<=n;i++){
		dfs(i,0); dfs(i,1);
	}
	for(int i = 1;i<=n-1;i++){
		if(b[0][1+i]) puts("-1");
		else printf("%I64d\n",i+f[0][1+i]);
	}
	return 0;
} 
