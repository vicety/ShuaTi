#include<bits/stdc++.h>
using namespace std;
string str;
int k,cnt,vis[30];
int main(){
	cin>>str>>k;
	int len = str.length();
	if(len<k) return 0*printf("impossible\n");
	else{
		for(int i = 0;i<len;i++){
			if(!vis[(int)(str[i]-'a')]){
				vis[(int)(str[i]-'a')] = 1;
				cnt++;
			} 
		}
		return 0*printf("%d\n",k-cnt>=0?k-cnt:0);
	}
}
