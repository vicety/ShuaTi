#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 2521
using namespace std;
int t,dis[N],x,y,z,n,m,s,tot,head[N];
bool vis[N],flag;
struct Edge
{
    int to,next,ds;
}edge[N*2];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();        
    }
    while(ch<='9'&&ch>='0')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void add(int from,int to,int dis)
{
    tot++;
    edge[tot].ds=dis;
    edge[tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot;
}
void begin()
{
    memset(dis,0,sizeof(dis));
    memset(vis,false,sizeof(vis));
    memset(head,0,sizeof(head));
    tot=flag=0;
}
void spfa(int s)
{
    vis[s]=true;
//    if(flag) return ;
    for(int i=head[s];i;i=edge[i].next)
    {
        if(dis[s]+edge[i].ds<dis[edge[i].to])
        {
            if(vis[edge[i].to])
            {
                flag=true;
                break;
            }
            dis[edge[i].to]=dis[s]+edge[i].ds;
            spfa(edge[i].to);
        }
    }
    vis[s]=false;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read(),s=read();
        begin();
        for(int i=1;i<=m;i++)
        {
            x=read(),y=read(),z=read();
            add(x,y,z);
            add(y,x,z);
        }
        for(int i=1;i<=s;i++)
        {
            x=read(),y=read(),z=read();
            add(x,y,-z);
        }
        // 图不一定连通 
        for(int i=1;i<=n;i++)
        {
            spfa(i);
            if(flag) break;
        }
        //spfa(1);
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
