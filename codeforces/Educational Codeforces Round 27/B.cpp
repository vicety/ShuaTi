//  « A Ã‚ –¥¥Ì¡À 
#include<bits/stdc++.h>
using namespace std;
int n;
int tmp[210];
int main(){
	scanf("%d",&n);
	for(int i = 0;i<2*n;i++){
		scanf("%d",&tmp[i]);
	}
	sort(tmp,tmp+n*2);
	if(tmp[n-1] < tmp[n]) printf("YES");
	else printf("NO");
}
