#include<bits/stdc++.h> 
using namespace std;
#define REP(I,N) for(int I = 0;I<N;I++)
#define REP1(I,N) for(int I = 1;I<=N;I++)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define MP(X,Y) make_pair(x,y)
#define CLR(A,X) memset(A,X,sizeof(A))
#define PB(X) push_back(X)
typedef long long LL;
int head[100100],cnt,n,x,y;
double sum,res;
double path;
struct EDGE{
	int to,next;
}e[200100];
void add(int u,int v){
	e[++cnt] = (EDGE){v,head[u]};
	head[u] = cnt;
}
void dfs(int x,int fa,int len,double rate){
	int cntt = 0;
	for(int i = head[x];i;i = e[i].next){
		int to = e[i].to;
		if(to == fa) continue;
		cntt++;
	}
	if(cntt == 0){
		res+=len*rate;
		return;
	}
	rate/=cntt;
	for(int i = head[x];i;i = e[i].next){
		int to = e[i].to;
		if(to == fa) continue;
		else{
			dfs(to,x,len+1,rate);
		}
	}

}

int main(){
	cin>>n;
	for(int i = 0;i<n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,-1,0,1);
	cout<<setprecision(9)<<res<<endl;
	//printf("%.9lf",res);
	return 0;
}
