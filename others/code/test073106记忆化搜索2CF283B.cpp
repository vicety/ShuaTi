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
	if(!f[k][i]){  // ����������ʱ�ǳɹ��ģ���δ����¼ֵ 
		int y = i+(k?a[i]:-a[i]);
		if(y>n||y<=1) d= 0;
		else d = dfs(y,k^1); // d�ɹ�Ϊ���� ����Ϊ0
		f[k][i] = d+a[i]; //��ǰ�Ƶ� // f ���� y  // ���۳ɲ��ɹ� �����ճɹ���¼f 
		if(y>=1 && y<=n && b[k^1][y]) b[k][i] = -1; //�����״̬�Ƶ��õ��Ľ���Ϊ���� ��״̬�಻�� 
	}
	//����������Ѿ�ȷ���ǳɹ��ģ��Ͳ�������һ��dfs
	vis[k][i] = 0; //�����Ƿ�ɹ��� �����
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
