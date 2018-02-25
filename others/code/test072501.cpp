#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100001
#define inf 0x3f3f3f3f
using namespace std;
struct edge{
    int to,next;
    double w;
}e[N<<1];
int head[N],cnt;
void add(int u,int v,int w){
    e[++cnt]=(edge){v,head[u],(double)w};
    head[u]=cnt;
}
int n,m;
int test;
bool one;
int last, second;
double idx[N];
double ans;
void dfs(int x,int fa){
    for(int i=head[x];i;i=e[i].next){
        int v=e[i].to;
        if(v==fa)continue;
        if(idx[x]+e[i].w<idx[v]){
            idx[v]=idx[x]+e[i].w;
            dfs(v,x);
        }
    }
}
int main(){
    while(scanf("%d%d",&n,&m),n||m){
        cnt=1;
        memset(head,0,sizeof head);
        for(int i=1,a,b,l;i<=m;++i){
            scanf("%d%d%d",&a,&b,&l);
            add(a,b,l);add(b,a,l);
        }
        printf("System #%d\n",++test);
        for(int i=2;i<=n;++i)idx[i]=1000000000.0;
        dfs(1,0);
        ans=-1;
        one=true;
        for(int i=1;i<=n;++i){
            if(idx[i]>ans){
                ans=idx[i];
                last=i;
            }
        }
        for(int i=2;i<=cnt;++i){
            double time=(idx[e[i].to]+idx[e[i^1].to]+e[i].w)*1./2;
            if(time>ans){
                ans=time;
                one=false;
                last=e[i].to;second=e[i^1].to;
            }
        }
        printf("The last domino falls after %.1f seconds, ", ans);
        if(one)printf("at key domino %d.\n", last);
        else{
            if(last>second)swap(last,second);
            printf("between key dominoes %d and %d.\n", last, second);
        }
        puts("");
    }
    return 0;
}
