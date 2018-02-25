#include<bits/stdc++.h>
using namespace std;
int n, a, b, c, tmp;
int main(){
	int ans = 0;
	cin>>n>>a>>b;
	for(int i = 1;i<=n;i++){
		cin>>tmp;
		if(tmp == 1){
			if(a) a--;
			else if(b) b--,c++;
			else if(c) c--;
			else ans++; 
		}
		else{
			if(b) b--;
			else ans+=2;
		}
	}
	cout<<ans<<endl;
	return 0; 
}
 
