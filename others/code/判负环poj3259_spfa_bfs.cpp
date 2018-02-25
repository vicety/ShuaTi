#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 509;
const int MAX = 0x3f3f3f3f;
struct Edge
{
    int u, v, r, next;
}edge[N*N+200];

int d[N];
int h[N];
bool vis[N];
int cnt[N];

bool spfa(int n)
{
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    for(int i=1; i<=n; i++)
        d[i] = MAX;
    d[1] = 0;
    vis[1] = 1;
    cnt[1]++;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int x = q.front();
        vis[x] = 0;
        q.pop();
        for(int i = h[x]; i!=-1; i = edge[i].next)
        {
            int v = edge[i].v;
            int to = edge[i].r + d[edge[i].u];
            if(d[v] > to)
            {
                d[v] = to;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                    if(++cnt[v] > n)
                        return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m, w;
        memset(h, -1, sizeof(h));
        scanf("%d%d%d", &n, &m, &w);
        for(int i=0; i<m; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edge[i].next = h[a];
            edge[i].u = a;
            edge[i].v = b;
            edge[i].r = c;
            h[a] = i;
            edge[i+m].next = h[b];
            edge[i+m].u = b;
            edge[i+m].v = a;
            edge[i+m].r = c;
            h[b] = i+m;
        }
        for(int i=0; i<w; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edge[2*m+i].next = h[a];
            edge[2*m+i].u = a;
            edge[2*m+i].v = b;
            edge[2*m+i].r = -c;
            h[a] = 2*m+i;
        }
        if(spfa(n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
