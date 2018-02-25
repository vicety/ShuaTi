#include<bits/stdc++.h>
using namespace std;
const int maxn = 50010;
int st,ran[maxn],next[maxn],x,n,val[maxn];
void query(int i){
	printf("? %d\n",i);
	fflush(stdout);
	scanf("%d%d",&val[i],&next[i]);
}
void solve(){
	scanf("%d%d%d",&n,&st,&x);
	srand(time(0));
	for(int i = 0;i<n;i++){
		ran[i] = i+1;
	}
	random_shuffle(ran,ran+n);
	query(st);
	for(int i = 0;i<1000 && i<n;i++){
		query(ran[i]);
		if(val[ran[i]]>val[st] && val[ran[i]]<=x) st = ran[i];
	}
	while(val[st]<x){
		st = next[st];
		if(st == -1) break;
		if(!next[st]) query(st);
	}
	printf("! %d\n", (st == -1) ? -1 : val[st]);
	fflush(stdout);
}
int main(){
	solve();
	return 0;
}
