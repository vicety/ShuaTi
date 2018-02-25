// B Ìâ 
#include<bits/stdc++.h>
using namespace std;
string str;
int ll[6];
int rl[6];
int num[6],cnt;
int toInt(char c){
	return c-'0';
}
int main(){
	cin>>str;
	for(int i = 0;i<3;i++) num[i] = toInt(str[i]);
	for(int i = 0;i<3;i++) num[5-i] = toInt(str[str.length()-i-1]);
	//for(int i = 0;i<6;i++) cout<<num[i];
	//cout<<endl;
	for(int i = 0;i<3;i++) ll[i] = num[i];
	for(int i = 3;i<6;i++) ll[i] = 9-num[i];
	for(int i = 0;i<3;i++) rl[i] = 9-num[i];
	for(int i = 3;i<6;i++) rl[i] = num[i];
	sort(ll,ll+6);
	sort(rl,rl+6);
	int lsum = num[0]+num[1]+num[2];
	int rsum = num[3]+num[4]+num[5];
	if(lsum == rsum) return 0*printf("0");
	cnt = 0;
	if(lsum>rsum)
	{
		while(lsum>rsum){
			rsum += ll[5-cnt++];
		}
		return 0*printf("%d",cnt);
	}
	else{
		while(rsum>lsum){
			lsum += rl[5-cnt++];
		}
		return 0*printf("%d",cnt);
	}
	return 0;
}
