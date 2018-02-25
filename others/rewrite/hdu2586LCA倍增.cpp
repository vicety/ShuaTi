#include<bits/stdc++.h>
using namespace std;
const int maxn = 40010;
int n, m, T, head[maxn], dep[maxn], cnt, dis[maxn][19], anc[maxn][19];
struct EDGE{
    int to, nxt, len;
    EDGE(){}
    EDGE(int a, int b, int c){
        to = a, nxt = b, len = c;
    }
}e[maxn<<1];
void add(int u, int v, int len){
    e[++cnt] = EDGE(v, head[u], len);
    head[u] = cnt;
}

void dfs(int now, int fa, int len){
    dep[now] = dep[fa]+1, anc[now][0] = fa, dis[now][0] = len;
    for(int i = 1;i<=18;i++) anc[now][i] = anc[anc[now][i-1]][i-1], dis[now][i] = dis[now][i-1] + dis[anc[now][i-1]][i-1];
    for(int i = head[now];i;i = e[i].nxt){
        int to = e[i].to;
        if(to == fa) continue;
        dfs(to, now, e[i].len);
    }
}

int lca(int a, int b){
    int ans = 0;
    if(dep[a] < dep[b]) swap(a,b);
    for(int i = 18;i>=0;i--) if(dep[anc[a][i]] >= dep[b]) ans+=dis[a][i],  a = anc[a][i];
    if(a == b) return ans;
    for(int i = 18;i>=0;i--) if(anc[a][i] != anc[b][i]){
        ans += dis[a][i], a = anc[a][i];
        ans += dis[b][i], b = anc[b][i];
    }
    ans += dis[a][0];
    ans += dis[b][0];
    return ans;
}

inline int read() {
    int x=0;char c=getchar();
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x;
}

void init(){
    memset(head, 0, sizeof(head));
    cnt = 0;
    memset(dep,0,sizeof(dep));
    memset(dis, 0, sizeof(dis));
    memset(anc, 0, sizeof(anc));
}

int main(){
    T = read();
    while(T--){
        init();
        n = read(); m = read();
        int st, ed, len;
        for(int i = 0;i<n-1;i++){
            st = read(); ed = read(); len = read();
            add(st, ed, len);
            add(ed, st, len);
        }
        dfs(1, 0, 0);
        for(int i = 0;i<m;i++){
            st = read(); ed = read();
            printf("%d\n", lca(st, ed));
        }
    }
    return 0;
}
