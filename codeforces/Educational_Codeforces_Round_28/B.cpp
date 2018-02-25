#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x = 0,f= 1; char ch = getchar();
	while(ch<'0' || ch>'9') {if(ch == '-') f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9') {x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
long long n,k,m,solved;
long long t[50];
int main(){
	n = read(), k = read(), m = read();
	for(int i = 0;i<k;i++){
		t[i] = read();
	}
	long long all = 0;
	long long ans = 0;
	long long tmp,rest;
	for(int i = 0;i<k;i++) all+= t[i];
	sort(t,t+k);
	for(int i = 0;i<=n;i++){
		if(all*i > m) break;
		rest = m;
		rest -= all*i;
		tmp = (k+1) * i;
		for(int j = 0;j<k;j++){
			if(rest == 0) break;
			if((n-i)*t[j] <= rest){
				rest -= (n-i)*t[j];
				tmp += (n-i);
			}
			else{
				tmp += rest/t[j];
				rest = 0;
			}
		}
		ans = max(ans,tmp);
	}
	printf("%I64d\n",ans);
	return 0;
} 
