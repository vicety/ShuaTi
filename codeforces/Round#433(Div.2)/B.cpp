#include<bits/stdc++.h>
using namespace std;
long long n ,k;
int main(){
	cin>>n>>k;
	cout<<((k == 0 || k == n)?0:1)<<" "<<min(k*3,n)-k<<endl;
	return 0;
}