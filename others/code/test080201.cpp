#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int ans,pos,cnt,tmp,rear;
char str[5020];
int main(){
	while(scanf("%s",str)>0){
		ans = 0;
		pos = 0;
		tmp = 0;
		int len = strlen(str);
		for(int i = 0;i<len;i++){
			char ch = str[i];
			if(ch == 'b') pos = 1;
			else if(ch == 'e' && pos == 1) pos = 2;
			else if(ch == 'a' && pos == 2) pos = 3;
			else if(ch == 'r' && pos == 3) pos = 4;
			else pos = 0;
			if(pos == 4){
				pos = 0;
				tmp+=i-2-tmp;
			}
			ans+=tmp;
		}
		printf("%d",ans);
	}
} 
