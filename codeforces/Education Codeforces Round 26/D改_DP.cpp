#include<iostream>
#include<algorithm>
#include<utility>
#include<cstring>
using namespace std;
typedef long long LL;
int dp[12010][240];
LL tmp;
int n,f,t,s,ans,m,x,y;
int main(){
	cin>>n>>m;
	memset(dp,0x80,sizeof dp);
	dp[0][0] = 0;
	for(int i = 1;i<=n;i++){
		x = 0,y = 0;
		cin>>tmp;
	/*	while(!(tmp%5)) f++,tmp/=5;
		while(!(tmp%2)) t++,tmp/=2;*/
		for(; !(tmp%5); tmp/=5) ++x;
		for(; !(tmp%2); tmp/=2) ++y;
		s += x;
		for(int k = min(i,m);k>=1;k--){
			for(int j = s;j>=x;j--){
				// 用 j 个 5 ， 取 k 个数 
				// dp[j][k]是不取这一次的结果，维持原样
				// 后者是取，结果为（还原到上一步）+这一步2的个数 
				dp[j][k] = max(dp[j][k],dp[j-x][k-1]+y);
			}
		}
	}
	//  5 和 2 取最小值 和 ans 取最大值 
	for(int i = 1;i<=s;i++) ans = max(ans,min(i,dp[i][m]));
	cout<<ans;
	return 0; 
}
