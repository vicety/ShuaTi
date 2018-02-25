#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x = 0,f= 1; char ch = getchar();
	while(ch<'0' || ch>'9') {if(ch == '-') f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9') {x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
int arr[105];
int pre[105];
int suf[105];
vector<int> v;
int n,st = -1,ed;
int main(){
	n = read();
	for(int i = 0;i<n;i++){
		arr[i] = read();
		if(i == 0) pre[i] = !arr[i];
		else{
			if(!arr[i])	pre[i] = pre[i-1]+1;	
			else pre[i] = pre[i-1];
		}
		
	}
	for(int i = n-1;i>=0;i--){
		if(i == n-1) suf[i] = arr[i];
		else{
			if(arr[i]) suf[i] = suf[i+1]+1;
			else suf[i] = suf[i+1];
		}
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		ans = max(ans,pre[i]+suf[i]);
	}
	cout<<ans<<endl;
	return 0;
}
