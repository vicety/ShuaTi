#include<bits/stdc++.h>
using namespace std;
int p[1010], k[2010], dp[1010][2010];
int des,n,key;
int solve(){
	for(int i = 1;i<=n;i++){
		dp[i][i] = max(dp[i-1][i-1], abs(p[i]-k[i])+abs(k[i]-des));
		for(int j = i+1;j<=key;j++){
			dp[i][j] = min(dp[i][j-1], max(dp[i-1][j-1], abs(p[i]-k[j])+abs(k[j]-des)));
		}
	}
	return dp[n][key];
}
int main(){
	scanf("%d%d%d",&n,&key,&des);
	for(int i = 0;i<n;i++) scanf("%d",p+i+1);
	for(int i = 0;i<key;i++) scanf("%d",k+i+1);
	sort(p+1,p+n+1);
	sort(k+1,k+1+key);
	printf("%d",solve());
	return 0;
}
