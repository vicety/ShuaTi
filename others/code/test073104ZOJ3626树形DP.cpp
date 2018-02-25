#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define REP(I,N) for(int I = 0;I<N;I++)
#define REP1(I,N) for(int I = 1;I<=N;I++)
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(x,y)
#define CLR(A,X) memset(A,X,sizeof(A))
#define PB(X) push_back(X)
struct EDGE{
	int to,next,time;
}e[105];
int head[105],cnt;
void add(int u,int v,int t){
	e[++cnt] = (EDGE){v,head[u],t};
	head[u] = cnt;
}
int v[105];
int n,s,m;
int t1,t2,t3;
int mmax,curt,curv,allv;
int dp[105][105];
void solve(int st,int fa){
	dp[st][0] = v[st];
	for(int i = head[st];i;i = e[i].next){
		int to = e[i].to;
		int time = e[i].time;
		if(to == fa) continue;
		solve(to,st);
		for(int j = m/2;j>=time;j--){
			for(int w = 0;w<=j-time;w++){
				dp[st][j] = max(dp[st][j],dp[to][w]+dp[st][j-time-w]);
			}
		}
	}
}
int main(){
	while(~scanf("%d",&n)){
		memset(head,0,sizeof(head));
		memset(dp,0,sizeof(dp));
		cnt = 0; 
		mmax = -1;
		curt = 0;
		REP1(i,n) scanf("%d",&v[i]);
		REP1(i,n-1){
			scanf("%d%d%d",&t1,&t2,&t3);
			add(t1,t2,t3);
			add(t2,t1,t3);
		}
		scanf("%d%d",&s,&m);
		curv = 0;
		solve(s,-1);
		int ans = 0;
		for(int i = 0;i<=m/2;i++){
			ans = max(ans,dp[s][i]);
		}
		//ans = dp[s][m/2];
		printf("%d\n",ans);
	}
	return 0;
}
