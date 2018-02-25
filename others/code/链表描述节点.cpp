//codeforces 717E 
#include<bits/stdc++.h> 
#define N 200005
using namespace std;
struct EDGE{
	int to,next;
}e[N<<1];
int head[N],cnt;
int n,a[N];
void add(int u,int v)//重点在这个函数 
{
	e[++cnt] = (EDGE){v,head[u]}; // 下一个e，传入v和head作为EDGE的to和next， 
	head[u] = cnt; //第一次为节点u传入head时为0，下一次就是这次的cnt，也就是说下一次的next可以作为e的下标访问到这一次的e[cnt].to 
} // 而这里不断更新head，最后一次的head使可以通过head反向访问u，u中的next存储的是上一次的head 
int ans[N<<1],top;
void dfs(int x,int fa)
{
	ans[++top] = x;
	a[x]*=-1;
	for(int i = head[x];i;i = e[i].next){ //类似链表的访问方法 
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v,x);
		ans[++top] = x;
		a[x]*=-1;
	}
	if(a[x] == -1){
		if(x!=1){
			ans[++top] = fa;
			a[fa]*=-1;
			ans[++top] = x;
			a[x] = 1;
		}
		else
		{
			ans[++top] = e[head[1]].to;
			ans[++top] = 1;
			ans[++top] = e[head[1]].to; 
		}
	}
}
int main()
{
	scanf("%d",&n);
	bool ex = 0;
	for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        if(a[i]==-1)
            ex=1;
    }
    for(int i=1,u,v;i<n;++i){
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    if(!ex)printf("1");
    else{
        a[1]*=-1;
        dfs(1,0);
        for(int i=1;i<=top;++i)
            printf("%d ",ans[i]); 
    }
    return 0;
}
