#include<bits/stdc++.h>
using namespace std;
const int maxn  = 600000;
inline int read(){
	int x = 0,f= 1; char ch = getchar();
	while(ch<'0' || ch>'9') {if(ch == '-') f=-1;ch = getchar();}
	while(ch>='0'&& ch<='9') {x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
struct ST{
	int x,l,r;
}st[maxn<<2];
int s[25];
int n,m;
void build(int x,int l,int r){
	if((st[x].l = l) == (st[x].r = r)) return;
	int mid = (st[x].l+st[x].r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
}
void insert(int x,int k){
	if(st[x].l == st[x].r) {st[x].x = 1;return;}
	int mid = st[x].l + st[x].r >> 1;
	insert(x<<1|(k>mid),k);
	st[x].x = st[x<<1].x+st[x<<1|1].x;
}
int query(int x,int k){
	if(st[x].l == st[x].r) return 0;
	int y = x<<1|s[k];
	if(st[y].x == st[y].r-st[y].l+1) return query(y^1,k-1)+(1<<k);
	else return query(y,k-1);
}
int main(){
	n = read(); m = read(); build(1,0,524287);
	for(int i = 0;i<n;i++) insert(1,read());
	while(m--){
		int q = read();
		for(int i = 18;i>=0;i--) if(q&(1<<i)) s[i]^=1;
		printf("%d\n",query(1,18));
	}
	return 0;
}

