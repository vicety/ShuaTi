#include<cstdio>
using namespace std;
int dp[12][105][105],n,q,c,t,x1,y1,x2,y2,x,y,s,ans;
inline int getBright(int init,int t){
	return (init+t)%(c+1);
}
int main(){
	scanf("%d%d%d",&n,&q,&c);
	for(int i = 0;i<n;i++){
		scanf("%d%d%d",&x,&y,&s);
		for(int j = 0;j<=c;j++) dp[j][x][y] += getBright(s,j);
	}
	for(int i = 0;i<q;i++){
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		t%=(c+1);
		ans = 0;
		for(int j = x1;j<=x2;j++){
			for(int k = y1;k<=y2;k++){
				ans+=dp[t][j][k];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

