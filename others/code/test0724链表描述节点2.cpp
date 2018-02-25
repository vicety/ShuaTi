//在做HDU1181 的时候发现这个如果有重复的边输入会很难受。。。
//也就是说maxn要大来防这一手 
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define REP(I,N) for(int I = 0;I<N;I++)
#define REP1(I,N) for(int I = 1;I<=N;I++)
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(x,y)
#define CLR(A,X) memset(A,X,sizeof(A))
#define PB(X) push_back(X)
#define long long LL
#define maxn 520
struct EDGE{
	int to,next;
	double time;
	EDGE(int a,int b,int c){
		to = a;
		next = b;
		time = (double)c;
	}
	EDGE(){} 
}e[maxn<<1];
int head[maxn],cnt,test,second;
double ans;
int last;
bool one;
double node[maxn];
int n,m,a,b,l;
void add(int u,int v,int w){
	e[++cnt] = EDGE(v,head[u],w);
	head[u] = cnt;
}
void dfs(int x,int fa){
	for(int i = head[x];i;i = e[i].next){
		if(e[i].to == fa) continue;
		if(node[x]+e[i].time<node[e[i].to]){
			node[e[i].to] = node[x]+e[i].time;
			dfs(e[i].to,x);
		}
	}
}
int main(){
	while(scanf("%d %d",&n,&m),n||m){
		cnt = 1;
		memset(head,0,sizeof(head)); // yao?
		REP1(i,m){
			scanf("%d%d%d",&a,&b,&l);
			add(a,b,l);
			add(b,a,l);
		}
		printf("System #%d\n",++test);
		for(int i = 2;i<maxn;i++) node[i] = INF;
		dfs(1,0);
		ans = -1;
		one = true;
		REP1(i,n){
			if(node[i]>ans){
				ans = node[i];
				last = i;
			}
		}
		for(int i = 2;i<=cnt;i++){
			double time = (node[e[i].to]+node[e[i^1].to]+e[i].time)/2.0;
			if(time>ans){
				ans = time;
				one = false;
				last = e[i].to;
				second = e[i^1].to;
			}
		}
		printf("The last domino falls after %.1f seconds, ", ans);
        if(one)printf("at key domino %d.\n", last);
        else{
            if(last>second)swap(last,second);
            printf("between key dominoes %d and %d.\n", last, second);
		}
		puts(" ");
	}
	return 0;
}
