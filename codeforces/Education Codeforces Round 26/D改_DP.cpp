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
				// �� j �� 5 �� ȡ k ���� 
				// dp[j][k]�ǲ�ȡ��һ�εĽ����ά��ԭ��
				// ������ȡ�����Ϊ����ԭ����һ����+��һ��2�ĸ��� 
				dp[j][k] = max(dp[j][k],dp[j-x][k-1]+y);
			}
		}
	}
	//  5 �� 2 ȡ��Сֵ �� ans ȡ���ֵ 
	for(int i = 1;i<=s;i++) ans = max(ans,min(i,dp[i][m]));
	cout<<ans;
	return 0; 
}
