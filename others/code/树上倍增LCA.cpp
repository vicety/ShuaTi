<<<<<<< HEAD
//luogu 3379
#include<cstdio>
#include<cmath>
#include<utility>
#include<iostream>
using namespace std;
const int N = 500010, OP = log2(500000)+1;
int dpt[N][26];
int dep[N];

inline int read(){
	int x = 0,f= 1; char ch = getchar();
	while(ch<'0' || ch>'9') {if(ch == '-') f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9') {x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

int head[N], to[N*2], nextt[N*2], cnt = 1;

inline void ins(int a, int b){
	nextt[cnt] = head[a], head[a] = cnt, to[cnt] =b, cnt++;
}

void dfs(int p, int x){
//	cout<<"here\n";
	dep[x] = p; // 深度  
	for(int u = head[x];u;u = nextt[u]){
		int _to = to[u];
		if(!dep[_to]){
			dpt[_to][0] = x; // 父亲 
			dfs(p+1, to[u]);
		}
	}
}

//int LCA(int a, int b){
//	if(dep[a] < dep[b]) swap(a,b); //默认a深度大 
//	for(int j = OP; j >= 0; j--){
//		if(dep[a] - (1<<j) >= dep[b]) a = dpt[a][j];
//	}
//	if(a!=b){
//		for(int j = OP; j>=0 ; j--){
//			if(dpt[a][j] != dpt[b][j]) a = dpt[a][j], b = dpt[b][j];
//		}
//	}
//	return dpt[a][0];
//}

int LCA(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    for(int j=OP;j>=0;j--)
        if(dep[a]-(1<<j)>=dep[b])a=dpt[a][j];
    if(a!=b){
        for(int j=OP;j>=0;j--)
            if(dpt[a][j]!=dpt[b][j])a=dpt[a][j],b=dpt[b][j];
        a=dpt[a][0];
    }
    return a;
}

int main(){
	int n,q,r,a,b;
	cin>>n>>q>>r;
	for(int i = 0;i<n-1;i++){
		a = read(), b = read();
		ins(a,b), ins(b,a);
	}	
	dfs(1,r);
	//for(int i = 0;i<=10;i++) cout<<"dep "<<i<<" "<<dep[i]<<endl;
	for(int j = 1;j<=OP;j++){
		for(int i = 1;i<=n;i++){
			dpt[i][j] = dpt[dpt[i][j-1]][j-1];
		}
	}
	for(int i = 1;i<=5;i++)for(int j = 0;j<3;j++) cout<<i<<" "<<j<<" "<<dpt[i][j]<<endl;
	for(int i = 0;i<q;i++){
		a = read(), b = read();
		printf("%d\n", LCA(a,b));
	}
	cout<<dpt[4][0]<<" aa "<<endl;
	return 0;
}

=======
//luogu 3379
#include<cstdio>
#include<cmath>
#include<utility>
#include<iostream>
using namespace std;
const int N = 500010, OP = log2(500000)+1;
int dpt[N][26];
int dep[N];

inline int read(){
	int x = 0,f= 1; char ch = getchar();
	while(ch<'0' || ch>'9') {if(ch == '-') f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9') {x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

int head[N], to[N*2], nextt[N*2], cnt = 1;

inline void ins(int a, int b){
	nextt[cnt] = head[a], head[a] = cnt, to[cnt] =b, cnt++;
}

void dfs(int p, int x){
//	cout<<"here\n";
	dep[x] = p; // 深度  
	for(int u = head[x];u;u = nextt[u]){
		int _to = to[u];
		if(!dep[_to]){
			dpt[_to][0] = x; // 父亲 
			dfs(p+1, to[u]);
		}
	}
}

//int LCA(int a, int b){
//	if(dep[a] < dep[b]) swap(a,b); //默认a深度大 
//	for(int j = OP; j >= 0; j--){
//		if(dep[a] - (1<<j) >= dep[b]) a = dpt[a][j];
//	}
//	if(a!=b){
//		for(int j = OP; j>=0 ; j--){
//			if(dpt[a][j] != dpt[b][j]) a = dpt[a][j], b = dpt[b][j];
//		}
//	}
//	return dpt[a][0];
//}

int LCA(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    for(int j=OP;j>=0;j--)
        if(dep[a]-(1<<j)>=dep[b])a=dpt[a][j];
    if(a!=b){
        for(int j=OP;j>=0;j--)
            if(dpt[a][j]!=dpt[b][j])a=dpt[a][j],b=dpt[b][j];
        a=dpt[a][0];
    }
    return a;
}

int main(){
	int n,q,r,a,b;
	cin>>n>>q>>r;
	for(int i = 0;i<n-1;i++){
		a = read(), b = read();
		ins(a,b), ins(b,a);
	}	
	dfs(1,r);
	//for(int i = 0;i<=10;i++) cout<<"dep "<<i<<" "<<dep[i]<<endl;
	for(int j = 1;j<=OP;j++){
		for(int i = 1;i<=n;i++){
			dpt[i][j] = dpt[dpt[i][j-1]][j-1];
		}
	}
	for(int i = 1;i<=5;i++)for(int j = 0;j<3;j++) cout<<i<<" "<<j<<" "<<dpt[i][j]<<endl;
	for(int i = 0;i<q;i++){
		a = read(), b = read();
		printf("%d\n", LCA(a,b));
	}
	cout<<dpt[4][0]<<" aa "<<endl;
	return 0;
}

>>>>>>> 1a56048d47b2e3994563d3eb931fec10c5db6184
