//HDU1166 敌兵布阵 
#include<cstdio>
#include<iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int maxn = 50010;
int sum[maxn<<2]; // sum 的下标 1-n并不是指数组1-n，我们也不需要这个性质 
void pushup(int rt){
	sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt){ // build 不会存在范围超出 
	if(l == r){
		cin>>sum[rt];
		return;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt){
	if(L<=l && r<=R){
		return sum[rt];
	}
	int m = (l+r)>>1;
	if (L > m) return query(L, R, rson);
	if (R <= m) return query(L,R,lson);
	return query(L, R, lson) + query(L, R, rson);
}

void update(int p,int add,int l,int r,int rt){
	if(l == r){
		sum[rt] += add;
		return;
	}
	int m = (l+r)>>1;
	if(p<=m) update(p,add,lson);
	else update(p,add,rson);
	pushup(rt);
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	int cas = 0;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		build(1,n,1);
		char s[10];
		cout<<"Case "<<(++cas)<<":"<<endl;
		while(cin>>s){
			if(s[0] == 'E') break;
			if(s[0] == 'A'){
				int a,b;
				cin>>a>>b;
				update(a,b,1,n,1);
			}
			else if(s[0] == 'S'){
				int a,b;
				cin>>a>>b;
				update(a,-1*b,1,n,1);
			}
			else{
				int a,b;
				cin>>a>>b;
				cout<<query(a,b,1,n,1)<<endl;
			}
		}
	}
	return 0;
}
