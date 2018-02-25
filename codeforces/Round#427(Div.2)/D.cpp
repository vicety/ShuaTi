#include<bits/stdc++.h>
using namespace std;
int dp[5010][5010];
string str;
int ans[5010];
void getdp(int l,int r){ //used when r-l+1>=3
	if(str[l] == str[r]) dp[l][r] = dp[l+1][r-1];
}
int getk(int l,int r){
	if(!dp[l][r]) return 0;
	if(r == l) return 1;
	if(r == l+1) return 2;
	
		/*int res = getk(l,(l+r-1)/2);
		if(res) return res+1;
		else return 0; */
	return getk(l,(l+r-1)/2)+1;
}
int main(){
	cin>>str;
	int len = str.length();
	for(int i = 0;i<len;i++){
		dp[i][i] = 1;
	}
	for(int i = 0;i<len-1;i++){
		if(str[i] == str[i+1]) dp[i][i+1] = 1;
	}
	for(int i = 2;i<len;i++){
		for(int j = 0;j+i<len;j++){
			getdp(j,j+i);
		}
	}
	/*for(int i = 0;i<7;i++)
	{
		for(int j = 0;j<7;j++) printf("%d ",dp[i][j]);
		printf("\n");
	 } */
	for(int i = 0;i<len;i++){
		for(int j = 0;j+i<len;j++){
			//int add = getk(j,j+i);
			//if(add){
			//	cout<<j<<" "<<j+i<<endl;
			ans[getk(j,j+i)]+=1;
			//}
		}
	}
	//printf("%d\n",ans[0]);
	for(int i = len-1;i>=1;i--) ans[i] += ans[i+1];
	for(int i = 1;i<=len;i++){
		printf("%d%c",ans[i],i == len?'\n':' ');
	}
	return 0;
}
