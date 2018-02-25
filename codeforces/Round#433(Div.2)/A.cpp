#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b%a == 0?a:gcd(b%a,a);
}
int n;
int main(){
	cin>>n;
	int x,y;
	double nmax = -1;
	for(int i = 1;i<=n/2;i++){
		//cout<<gcd(i, n-i)<<endl;
		if(gcd(i,n-i) == 1){
			if((double)i/(double)(n-i) > nmax){
				nmax = (double)i/(double)(n-i);
				x = i, y = n-i;
			}
		}
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}