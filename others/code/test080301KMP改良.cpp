#include<bits/stdc++.h>
using namespace std;
int next[1000],i,j,len,lenb;
char stra[1000],strb[1000];
void getnext(){
	i = 0,j = -1,len = strlen(strb);
	//cout<<len<<endl;
	next[0] = -1;
	while(i<len){
		if(j == -1||strb[i] == strb[j]){
			if(strb[++i] == strb[++j]) next[i] = next[j];
			else next[i] = j;
			//next[++i] = ++j;
		}
		else j = next[j];
	}
}
int KMP(){
	i = -1,j = -1,len = strlen(stra),lenb = strlen(strb);
	while(i<len&&j<lenb){
		if(j == -1||stra[i] == strb[j]){
			++i,++j;
		}
		else j = next[j];
		if(j == lenb) return i-j;
	}
	return 0;
}
int main(){
	scanf("%s %s",stra,strb);
	//printf("%s",strb+1);
	getnext();
	//cout<<next[4]<<endl;
	lenb = strlen(strb);
	for(int k = 0;k<=lenb;k++) cout<<next[k]<<endl;
	cout<<KMP()<<endl;
	return 0;
} 
