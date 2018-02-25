#include<bits/stdc++.h>
using namespace std;
int k;
int arr[100100],ans,cnt;
string str;
int toInt(char c){
	return c-'0';
}
int main(){
	cin>>k>>str;
	for(int i = 0;i<str.length();i++){
		ans+=toInt(str[i]);
		arr[i] =9-toInt(str[i]);
	}
	if(ans>=k) cout<<"0";
	else{
		sort(arr,arr+str.length());
		for(int i = str.length()-1;i>=0;i--){
			ans+=arr[i];
			cnt++;
			if(ans>=k) break;;	
		}
		cout<<cnt;
	}
	return 0;
}
