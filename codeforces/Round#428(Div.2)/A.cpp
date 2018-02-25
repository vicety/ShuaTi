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
int n,k,save;
int a[105];
int main(){
	cin>>n>>k;
	for(int i = 0;i<n;i++)  cin>>a[i];
	for(int i = 0;i<n;i++){
		save+=a[i];
		k-=min(8,save);
		save-=min(8,save);
		//if(a[i]>8) save+=a[i]-8;
		if(k<=0){
			cout<<i+1;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
