#include<bits/stdc++.h>
using namespace std;
struct T{
	int time;
	int th; // 0 st
	int st;
}t[400020];
bool cmp(T a, T b){
	if(a.time != b.time){
		return a.time<b.time;
	}
	else return a.th<b.th;
}
int n,pfirst = -1,psecond = -1,rfirst = -1,rsecond = -1;
int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d%d",&t[i*2].time,&t[(i*2)^1].time);
		t[i*2].th = 0;
		t[(i*2)^1].th = 1;
		t[(i*2)^1].st = t[i*2].time;
	} 
	sort(t,t+2*n,cmp);
	for(int i = 0;i<2*n;i++){
		if(t[i].th == 0){
			if(pfirst == -1 && rfirst != t[i].time){
				pfirst = t[i].time;
			}
			else if(psecond == -1 && rsecond != t[i].time){
				psecond = t[i].time;
			}
			else{
				return 0*printf("NO");
			}
		}
		else{
			int tost = t[i].st;
			if(pfirst == tost){
				pfirst = -1;
				rfirst = t[i].time;
			}
			else if(psecond == tost){
				psecond = -1;
				rsecond = t[i].time;
			}
			else {
				cout<<"error";
			}
		}
	}
	return 0*printf("YES");
}
