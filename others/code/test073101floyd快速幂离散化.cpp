#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
int n,t,s,e;
const int maxn = 1005;
int num[maxn];
int N;
int cnt = 0;
struct MATRIX{
	int a[105][105];
	MATRIX operator *(MATRIX &r){
		MATRIX t;
		memset(t.a,INF,sizeof(t.a));
		for(int i = 1;i<=N;i++){
			for(int j = 1;j<=N;j++){
				for(int k = 1;k<=N;k++){
					t.a[i][j] = min(t.a[i][j],a[i][k]+r.a[k][j]);
				}
			}
		}
		return t;
	}
}st,ans;
void qpow(MATRIX m,int n){
	MATRIX q = m;
	ans = m;
	while(n){
		if(n&1) ans=ans*q;
		q=q*q;
		n>>=1;
	}
}
int main(){
	scanf("%d%d%d%d",&n,&t,&s,&e);
	memset(st.a,INF,sizeof(st.a));
	memset(num,0,sizeof(num));
	cnt = 0;
	for(int i = 1;i<=t;i++){
		int u,v,w;
		scanf("%d%d%d",&w,&u,&v);
		if(num[u]!=0) u = num[u];
		else u = num[u] = ++cnt;
		if(num[v]!=0) v = num[v];
		else v = num[v] = ++cnt;
		st.a[u][v] = w;
		st.a[v][u] = w;		
	}
	N = cnt;
	qpow(st,n-1);
	if(ans.a[num[s]][num[e]] != INF) printf("%d\n",ans.a[num[s]][num[e]]);
	else printf("-1\n");
	return 0;
}
