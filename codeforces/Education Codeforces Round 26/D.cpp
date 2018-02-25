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
int n,k;
set<int>s;
LL arr[210];
struct TWO{
	int ind;
	int two;
	bool friend operator<(TWO a,TWO b){
		return a.two>b.two;
	}
}two[210];
struct FIVE{
	int ind;
	int five;
	bool friend operator<(FIVE a,FIVE b){
		return a.five>b.five;
	}
}five[210];
int ttwo[210];
int ffive[210];
int main(){
	cin>>n>>k;
	REP(i,n){
		cin>>arr[i];
	}
	REP(i,n){
		LL tmp = arr[i];
		int add = 0;
		while(tmp%5 == 0){
			add++;
			tmp/=5;
		}
		five[i].five = add;
		five[i].ind = i;
		ffive[i] = add;
		add = 0;
		tmp = arr[i];
		while(tmp%2 == 0){
			add++;
			tmp/=2;
		}
		two[i].two = add;
		two[i].ind = i;
		ttwo[i] = add;
	}
	sort(two,two+n);
	sort(five,five+n);
	//cout<<"here";
	int w = 0,f = 0,wcnt = 0,fcnt = 0;
	while(k>0){
		if(w>=f){
			while(s.find(five[fcnt].ind) != s.end()) fcnt++;
			f+=five[fcnt].five,w+=ttwo[five[fcnt].ind];
			s.insert(five[fcnt].ind);
			fcnt++;
			k--;
		}
		else{
			while(s.find(two[wcnt].ind) != s.end()) wcnt++;
			w+=two[wcnt++].two,f+=ffive[two[wcnt].ind];
			s.insert(two[wcnt].ind);
			wcnt++;
			k--;
		}
	}
	cout<<min(f,w);
	return 0;
}
