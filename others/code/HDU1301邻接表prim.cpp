#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
struct EDGE{
	int to,next,val;
	EDGE(){}
	EDGE(int a,int b,int c){
		to = a;
		next = b;
		val = c;
	}
}e[80];
int head[80],cnt,vis[30],n,ind,ans;
char ch;
int len,line,to;
vector<int>v;
void add(int u,int v,int w){
	e[++cnt] = EDGE(v,head[u],w);
	head[u] = cnt;
}
void prim(){
	while(v.size()<n){
		int val = INF;
		for(int i = 0;i<v.size();i++){
			for(int j = head[v[i]];j;j = e[j].next){
				to = e[j].to;
				//cout<<"to "<<to<<endl;
				if(vis[to]) continue;
				if(e[j].val<val){
					val = e[j].val;
					ind = to;
				}
			}
		}
		//cout<<"ind "<<ind<<endl;
		vis[ind] = 1;
		v.push_back(ind);
		ans+=val;
		//cout<<val<<endl;
	} 
}
int main(){
	while(scanf("%d",&n),n){
		ans = 0,cnt = 0;
		memset(head,0,sizeof(head));
		memset(vis,0,sizeof(vis));
		v.clear();
		for(int i = 0;i<n-1;i++){
			scanf(" %c%d",&ch,&line);
			int st = (int)(ch-'A');
			for(int j = 0;j<line;j++){
				scanf(" %c%d",&ch,&len);
				to = (int)(ch-'A');
				add(st,to,len);
				add(to,st,len);
			}
		}
		v.push_back(0);
		vis[0] = 1;
		prim();
		printf("%d\n",ans);
	}
}

// EDGE head cnt add vis不连通  v纪录已经加入的点  v要push一个 
