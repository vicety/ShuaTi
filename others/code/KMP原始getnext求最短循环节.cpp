//HUST1010
//注意！ 只是kmp的思想 
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char strb[1000010];
int nextval[1000010];
// 0 
/*void getnext(){
	int i = 1,j = 0,len = strlen(str+1);
	nextval[1] = 0;
	while(i<=len){
		if(j == 0||str[i] == str[j]){
		//	++i,++j;
			nextval[++i] = ++j;
		}
		else j = nextval[j];
	}
}*/

/*void getnext(){
	nextval[0] = -1;
	for(int i = 0,j = -1;str[i];i++,j++){
		while(j>=0 && str[i]!=str[j]) j = nextval[j];
		nextval[i+1] = (str[i+1] == str[j+1]?nextval[j+1]:j+1);
	}
}*/

void getnext(){
	int i = 0,j = -1,len = strlen(strb);
	//cout<<len<<endl;
	nextval[0] = -1;
	while(i<len){
		if(j == -1||strb[i] == strb[j]){
			if(strb[++i] == strb[++j]) nextval[i] = nextval[j];
			else nextval[i] = j;
			//next[++i] = ++j;
		}
		else j = nextval[j];
	}
}
//然而这个并不是原始的，改良的第n项用来作为答案 
int main(){
	while(~scanf("%s",strb)){
		getnext();
		int len = strlen(strb);
		//for(int i = 0;i<=len;i++) cout<<nextval[i]<<endl;
		printf("%d\n",len-nextval[len]);
	}
	return 0;
}
