#include<bits/stdc++.h>
/*
9 8
1 0 1 0 -1 0 1 0 1 
1 2
2 3
4 5
5 3
3 6
6 7
3 8
8 9
*/
using namespace std;
#define MAXN	300005
struct edge {int dest, num; };
int n, m, f[MAXN];
int cnt, ans[MAXN];
int root, d[MAXN];
vector <edge> a[MAXN];
void work(int pos, int fa) {
	for (unsigned i = 0; i < a[pos].size(); i++) {
		if (a[pos][i].dest == fa) continue;
		work(a[pos][i].dest, pos);
		if (d[a[pos][i].dest] == 1) {
			ans[++cnt] = a[pos][i].num;
			//d[a[pos][i].dest] ^= 1;
			if (d[pos] != -1) d[pos] ^= 1;
		}
	}
}
// 并查集去环 否则还要加个vis数组 
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
		f[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (F(x) == F(y)) continue;
		f[F(x)] = F(y);
		a[x].push_back((edge) {y, i});
		a[y].push_back((edge) {x, i});
	}
	root = 1;
	for (int i = 1; i <= n; i++)
		if (d[i] == -1) {
			root = i;
			break;
		}
	work(root, 0);
	if (d[root] == 1) printf("-1\n");
	else {
		printf("%d\n", cnt);
		for (int i = 1; i <= cnt; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}
/*
void dfs(int u)
{
    vis[u] = 1;
    if(a[u] == 1) b[u] = 1;
    for(int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if(vis[v]) continue;
        dfs(v);
        if(b[v] & 1) ans.push_back(e[u][i]);
        b[u] += b[v];
    }
}
*/
// a是d数组，b相当于异或 
