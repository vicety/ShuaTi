#include<bits/stdc++.h>
using namespace std;
int s,v1,v2,t1,t2; 
int main(){
	cin>>s>>v1>>v2>>t1>>t2;
	int first = 2*t1+s*v1;
	int second = 2*t2+s*v2;
	if(first<second) cout<<"First";
	else if(first == second) cout<<"Friendship";
	else cout<<"Second";
	return 0;
}
