#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int M = 300005;

int E;
int to[M << 1];
int no[M << 1];
int nxt[M << 1];
int head[N];

void init_graph() {
  E = 0;
  memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int id) {
  to[E] = v;
  no[E] = id;
  nxt[E] = head[u];
  head[u] = E++;
}

int n, m;
int d[N], id[N];
bool use[N], vis[N];

//int fa[N], siz[N];

void dfs(int v, int fa) {
  vis[v] = true;
  for (int i = head[v]; ~i; i = nxt[i]) {
    int u = to[i];
    if (u != fa && !vis[u]) {
      id[u] = no[i];
      dfs(u, v);
      if (d[u]) {
        use[id[u]] = true;
        d[v] ^= 1;
      }
    }
  }
}

int main() {
  init_graph();

  scanf("%d%d", &n, &m);
  int one = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d[i]);
    if (d[i] == 1) one++;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v, i);
    add_edge(v, u, i);
  }

  if (one & 1) {
    for (int i = 1; i <= n; i++) if (d[i] == -1) { d[i] = 1; one++; break; }
    if (one & 1) { puts("-1"); return 0;}
  }
  for (int i = 1; i <= n; i++) if (d[i] == -1) d[i] = 0;

  dfs(1, -1);
  int ans = 0;
  for (int i = 1; i <= m; i++) if (use[i]) ans++;
  printf("%d\n", ans);
  for (int i = 1; i <= m; i++) {
    if (use[i]) printf("%d ", i);
  }
  puts("");

  return 0;
}
