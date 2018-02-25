//codeforces 717E 
#include<bits/stdc++.h> 
#define N 200005
using namespace std;
struct EDGE{
	int to,next;
}e[N<<1];
int head[N],cnt;
int n,a[N];
void add(int u,int v)//�ص���������� 
{
	e[++cnt] = (EDGE){v,head[u]}; // ��һ��e������v��head��ΪEDGE��to��next�� 
	head[u] = cnt; //��һ��Ϊ�ڵ�u����headʱΪ0����һ�ξ�����ε�cnt��Ҳ����˵��һ�ε�next������Ϊe���±���ʵ���һ�ε�e[cnt].to 
} // �����ﲻ�ϸ���head�����һ�ε�headʹ����ͨ��head�������u��u�е�next�洢������һ�ε�head 
int ans[N<<1],top;
void dfs(int x,int fa)
{
	ans[++top] = x;
	a[x]*=-1;
	for(int i = head[x];i;i = e[i].next){ //��������ķ��ʷ��� 
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
