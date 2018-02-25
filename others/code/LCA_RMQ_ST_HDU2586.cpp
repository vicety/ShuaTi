#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define maxn 100100
#define maxd 18
#define REP(I,N) for(int I = 0;I<N;I++)
#define REP1(I,N) for(int I = 1;I<=N;I++)
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(x,y)
#define CLR(A,X) memset(A,X,sizeof(A))
#define PB(X) push_back(X)
typedef long long LL;
using namespace std;
struct EDGE {
	int next,v,w; // x here y to  w dis 
}e[maxn];
int head[maxn], first[maxn];
bool vis[maxn];
int tot = 0;
int ans = 0;
int dp[maxn][maxd];
int time_stamp[maxn];
int dep[maxn];
int dis[maxn];
void add(int x, int y, int d) {
	e[++tot].v = y; e[tot].w = d;
	e[tot].next = head[x]; head[x] = tot;
}
int t;
void dfs(int st, int de) { //获得每个节点对应时间戳 深度  时间戳对应节点 
	vis[st] = true;
	time_stamp[++t] = st;
	first[st] = t;
	dep[t] = de;
	for (int i = head[st];i;i = e[i].next) {
		if (!vis[e[i].v]) {
			int tmp = e[i].v;
			dis[tmp] = dis[st] + e[i].w;
			dfs(tmp, de + 1);
			time_stamp[++t] = st;
		}
	}
}
void ST(int n) { //获得dp （区间最小深度） 
	for (int i = 1;i <= n;i++) {
		dp[i][0] = i;
	}
	for (int j = 1;(1 << j)<= n;j++) {
		for (int i = 1;i + (1 << j) - 1 <= n;i++) {
			int a = dp[i][j - 1], b = dp[i + (1 << (j - 1))][j - 1];
			dp[i][j] = dep[a] < dep[b] ? a : b;
		}
	}
}
int RMQ(int l, int r) { //返回区间最小dep也就是LCA） 
	int k = 0;
	while ((1 << (k + 1)) <= r - l + 1) k++;
	int a = dp[l][k], b = dp[r - (1 << k)+1][k]; 
	return dep[a] < dep[b] ? a : b;
}
int LCA(int u, int v) { //返回区间最小深度对应时间戳 
	int x = first[u], y = first[v];
	if (x > y) {
		swap(x, y);
	}
	int res = RMQ(x, y);
	return time_stamp[res];
}
int main() {
	int cas;
	scanf("%d", &cas);
	while (cas--) {
		memset(head, 0, sizeof(head)); 
		memset(vis, 0, sizeof(vis));
		memset(dis, 0, sizeof(dis));
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1;i < n;i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			add(a, b, c);
			add(b, a, c);
		}
		dfs(1, 1);
		ST(2 * n - 1);
		for (int i = 0;i < m;i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", dis[x] + dis[y] - 2 * dis[LCA(x, y)]);
		}
	}
	return 0;
}
