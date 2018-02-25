#include<bits/stdc++.h>
using namespace std;
int arr[28],n,k;
string str;
int main(){
	cin>>n>>k;
	cin>>str;
	int ave = n/k;
	for(int i = 0;i<str.length();i++){
		arr[(int)(str[i]-'a')]++;
	}
	for(int i = 0;i<26;i++){
		if(arr[i] > k )return 0*printf("NO");
	}
	printf("YES");
	return 0;
} 
