#include<bits/stdc++.h>
using namespace std;
int f(int a){
	int ans = 1;
	for(int i = 1;i<=a;i++) ans*=i;
	return ans;
}
int main(){
	int a,b;
	cin>>a>>b;
	return 0*printf("%d",f(min(a,b)));
} 
