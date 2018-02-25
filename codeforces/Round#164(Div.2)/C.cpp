#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	printf("%d\n",min(m,n)+1);
	if(n>=m){
		for(int i = 0;i<=m;i++){
			printf("%d %d\n",i,m-i);
		}
	}
	else{
		for(int i = 0;i<=n;i++){
			printf("%d %d\n",i,n-i);
		}
	}
	return 0;
}
