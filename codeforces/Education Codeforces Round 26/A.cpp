#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,temp,ans;
string str;
int main(){
	cin>>n;
	while(cin>>str){
		temp = 0;
		for(int i = 0;i<str.length();i++){
			if(str[i]-'A'>=0&&str[i]-'Z'<=0) temp++;
		}
		ans = max(ans,temp);
	}
	
	cout<<ans;
	return 0;
} 
