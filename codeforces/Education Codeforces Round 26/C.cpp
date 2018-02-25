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
int a,b,n,ans;
int x[105],y[105];
bool can(int i,int a,int b){
	int mmin = x[i],mmax = y[i];
	if(a<=0 || b<=0) return false;
	if(mmin>mmax) swap(mmin,mmax);
	if(mmax > max(a,b)) return false;
	else if(mmin>min(a,b)) return false;
	else return true;
}
int judge(int i,int j){
	if(!can(i,a,b) || !can(j,a,b)) return 0;
	else{
		int recmax = a,recmin = b;
		if(recmax<recmin) swap(recmax,recmin);
		int mmaxi = x[i], mmini = y[i];
		if(mmaxi<mmini) swap(mmaxi,mmini);
		int mmaxj = x[j], mminj = y[j];
		if(mmaxj<mminj) swap(mmaxj,mminj);
		if(can(j,recmax-mmaxi,recmin)  ){
			//cout<<1<<endl;
			return mmaxi*mmini+mmaxj*mminj;
		} 
		if(can(j,recmax-mmini,recmin) && recmin>=mmaxi){
			//cout<<2<<endl;
			return mmaxi*mmini+mmaxj*mminj;
		} 
		if(can(j,recmax,recmin-mmaxi)){
			//cout<<3<<endl;
			return mmaxi*mmini+mmaxj*mminj;
		} 
		if(can(j,recmax,recmin-mmini)){
			//cout<<4<<endl;
			return mmaxi*mmini+mmaxj*mminj;
		}  
	}
	return 0;
}
/*int judge(int i,int j){
	
}*/
int main(){
	ans = 0;
	scanf("%d%d%d",&n,&a,&b);
	for(int i = 0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(i == j) continue;
			ans = max(ans,judge(i,j));
		}
	}
	cout<<ans;
	return 0;
}
