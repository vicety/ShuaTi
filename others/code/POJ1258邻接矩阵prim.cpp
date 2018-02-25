#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int g[maxn][maxn];
int n;
int ans;
bool vis[maxn];
int in;
int indi,indj,val;
void prim(){
	while(in!=n-1){
		val = INF;
		for(int i = 1;i<=n;i++){
			if(vis[i]){
				for(int j = 1;j<=n;j++){
					if(!vis[j] && g[i][j]!=0 && g[i][j]<val){
						indi = i; indj = j; val = g[i][j];
					}
				}
			}
		}
		vis[indj] = true;
		in++;
		ans+=val;
		//printf("val: %d\n",val);
	}
}
int main(){
	while(~scanf("%d",&n)){
		memset(vis,false,sizeof(vis));
		in = 0;
		ans = 0;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++)
				scanf("%d",&g[i][j]);
		}
		vis[1] = true;
		prim();
		printf("%d\n",ans);
	}
	return 0;
}
