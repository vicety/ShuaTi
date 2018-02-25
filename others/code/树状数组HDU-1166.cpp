#include<cstdio>
using namespace std;
#define REP(I,N) for(int I = 0;I<N;I++)
#define REP1(I,N) for(int I = 1;I<=N;I++)
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(x,y)
#define CLR(A,X) memset(A,X,sizeof(A))
#define PB(X) push_back(X)
#define long long LL
#define maxn 50050
int cas,n,x,y;
char str[10];
int c[maxn];
int lowbit(int x){
	return x&(-x);
}
int ask(int i){
	int res = 0;
	while(i>0){
		res+=c[i];
		i-=lowbit(i);
	}
	return res;
}
void add(int i,int x){
	while(i<=n){
		c[i]+=x;
		i+=lowbit(i);
	}
}

int main(){
	scanf("%d",&cas);
	REP1(j,cas){
		printf("Case %d:\n",j);
		scanf("%d",&n);
		REP1(i,n){
			scanf("%d",&x);
			add(i,x);
		}
		while(scanf("%s",str)&&str[0]!='E'){
			scanf("%d %d",&x,&y);
			if(str[0] == 'Q') printf("%d\n",ask(y)-ask(x-1));
			else if(str[0] == 'A') add(x,y);
			else add(x,-1*y);
		}
		REP1(i,n) c[i] = 0;
	}
	return 0;
}
