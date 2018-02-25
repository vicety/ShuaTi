//http://blog.csdn.net/mengxiang000000/article/details/51437842
#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;
const int maxn = 40100;
struct EDGE{
	int to,next,len;
	EDGE(){
		
	} 
	EDGE(int _to,int _next,int _len){
		to = _to;
		next = _next;
		len = _len;
	}
}e[maxn<<1];
struct QEDGE{
	int from,to,next,lca;
	QEDGE(){
		
	}
	QEDGE(int _from,int _to,int _next){
		from = _from;
		lca = -1;
		to = _to;
		next = _next;
	}
}q[maxn<<1];
int cnt,qcnt,head[maxn],qhead[maxn],n,m;
void add(int u,int v,int len){  //���cnt���㿪ʼ ��һ��head�ᱻ��Ϊ0�����memset -1 
	e[cnt] = EDGE(v,head[u],len);
	head[u] = cnt++;
}
void addq(int u,int v){
	q[qcnt] = QEDGE(u,v,qhead[u]);
	qhead[u] = qcnt++;
}
int vis[maxn],fa[maxn];
int dir[maxn],prob[maxn][2];
int find(int x){
	return fa[x] == x? x:find(fa[x]);  //fa[x] = 
}
void unite(int u,int v){ 
	//ur����vr 
	int ur = find(u);
	int vr = find(v);
	if(ur == vr) return;
	fa[ur] = vr;
}
void LCA(int x){
	//fa[x] = x;
	vis[x] = 1;
	for(int i = head[x];i!=-1;i = e[i].next){
		int to = e[i].to;
		//if(to == faa) continue;
		if(!vis[to]){
			dir[to] = dir[x]+e[i].len;
			//cout<<to<<" to|dir "<<dir[to]<<endl;
			LCA(to);
			unite(to,x);
		}
	}
	//�Ѿ�ȷ��x���������������ǰ׺�ڵ�ı��  ��Ȼx�ĸ���û����� 
	for(int i = qhead[x];i!=-1;i = q[i].next){
		int to = q[i].to;
		if(vis[to]){
			//cout<<"here\n";
			q[i].lca = find(to);  // �Լ������Ĳ�������������� 
			q[i^1].lca = q[i].lca; //�����1��ʼ �ͻ���q[0].lca == balabala ��Ȼ���� 
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		cnt = 0;
		qcnt = 0;
		for(int i = 1;i<=n;i++){
			fa[i] = i;
		}
		memset(vis,0,sizeof(vis));
		memset(head,-1,sizeof(head));  //��һ�γ�ʼ��Ҫ����head��ʼֵΪ0������ 
		memset(qhead,-1,sizeof(qhead));
		memset(dir,0,sizeof(dir));
		for(int i = 0;i<n-1;i++){
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w); 
			add(x,y,w);
			add(y,x,w);
		}
		//cout<<e[0].to<<" to|len e[0] "<<e[0].len<<endl;
		for(int i = 0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			addq(y,x);
			addq(x,y);
		}
		//for(int i = 0;i<=1;i++) cout<<q[i].from<<" from|to "<<q[i].to<<" to|lca "<<q[i].lca<<endl;
		LCA(1);
		
		for(int i = 0;i<m;i++){
			int tmp = i*2, u = q[tmp].from, v = q[tmp].to,lca = q[tmp].lca;
			//cout<<u<<" "<<v<<" "<<lca<<endl;
			//cout<<dir[u]<<" "<<dir[v]<<" "<<dir[lca]<<endl; 
			printf("%d\n",dir[u]+dir[v]-2*dir[lca]);
		}
	}
	return 0;
}
