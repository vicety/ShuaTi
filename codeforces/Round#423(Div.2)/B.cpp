#include<bits/stdc++.h>
using namespace std;
int n,m, lm = 105, um = 105, rm, dm;
char c;
int g[105][105];
int main(){
	cin>>n>>m;
	int cnt = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>c;
			if(c =='B'){
				g[i][j] = 1, cnt++;
				um = min(i,um);
				dm = max(i,dm);
				lm = min(j,lm);
				rm = max(j,rm);
			}
		}
	}
	//cout<<um<<" "<<dm<<" "<<lm<<" "<<rm<<endl;
	if(!cnt) return 0*printf("1\n"); 
	if(dm-um+1 >= rm-lm+1){
		if(m<dm-um+1) cout<<-1<<endl;
		else cout<<(dm-um+1)*(dm-um+1)-cnt;
	}
	if(dm-um+1 < rm-lm+1){
		if(n<rm-lm+1) cout<<-1<<endl;
		else cout<<(rm-lm+1)*(rm-lm+1)-cnt;
	}
	return 0;
}
