#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int mp[210][210],n,m;
int st,ed,len;
void reset(){
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			mp[i][j] = 0x3f3f3f3f;
		}
	}
	for(int i = 0;i<n;i++){
		mp[i][i] = 0;
	}
}
void floyd(){
	for(int k = 0;k<n;k++){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				mp[i][j] = min(mp[i][j],mp[i][k] + mp[k][j]);
				mp[j][i] = min(mp[j][i],mp[j][k] + mp[k][i]);
			}
		}
	}
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		reset();
		for(int i = 0;i<m;i++){
			scanf("%d%d%d",&st,&ed,&len);
			mp[st][ed] = min(mp[st][ed],len);
			mp[ed][st] = min(mp[ed][st],len);
		}
		floyd();
		scanf("%d%d",&st,&ed);
		if(mp[st][ed] != 0x3f3f3f3f)printf("%d\n",mp[st][ed]);
		else printf("-1\n");
	}
	
	return 0;
}
