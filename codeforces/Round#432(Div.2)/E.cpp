#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
unordered_map<int,int> ttmp;
int n,tmp,y;
int grund(int x){
	if(ttmp.count(x)) return ttmp[x];
	unordered_set<int> s;
	for(int i = 1;i<=30;i++){
		y = (x>>i) | (x&((1<<(i-1))-1));
		if(y!=x) s.insert(grund(y));
	}
	
	int ans = 0;
	while(s.count(ans)) ans++;
	return ttmp[x] = ans;
}
int main(){
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>tmp;
		for(int j = 2;j*j<=tmp;j++){
			if(tmp%j == 0){
				int cnt = 0;
				while(tmp%j == 0){
					tmp/=j;
					cnt++;
				}
				mp[j] |= (1<<cnt-1);
			}
		}
		if(tmp>1) mp[tmp] |= 1;		
	}
	int ans = 0;
	ttmp[0] = 0;
	for(auto t : mp){
		ans^=grund(t.second);
	}
	cout<<(ans?"Mojtaba":"Arpa")<<endl;
	return 0;
}
