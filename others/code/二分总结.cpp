#include<bits/stdc++.h>
using namespace std;
//int ans[210];
int ans[8] = {1,2,2,4,5,5,5,6};
int find_exact(int x){ // ��ʵ�ϲ������ l = r-1 �����ǳ�ʼ��� 
	int l = 0, r = 7;
	if(ans[l]>x || ans[r]<x) return -1;
	while(l<r){
		int mid = l+r>>1;
		cout<<mid<<endl;
		if(ans[mid] < x) l = mid+1; // ��ΪҪ��ȷ��ֵ��mid��ȷ�������ˣ���û��Ҫ��mid��ʼ 
		else if(ans[mid] > x) r = mid-1;
		else return mid;
	}
	return -1; 
}
// first lower than x
int lower(int x){
	int l = 0, r = 7;
	if(ans[l]>x) return 0;
	if(ans[r]<x) return r;
	while(l<r){
		int mid = l+r+1>>1; // ����ȡ�� 
		cout<<l<<" "<<r<<" "<<mid<<endl;
		if(ans[mid] < x) l = mid;
		else r = mid-1; // ��ʹ���ҲӦ�þ��������ƶ���ʹĳһ��r<=l������ 
	}
	return l; 
}
// first equal to x if exists else first lower than x
int lower_bound_low(int x){
	int l = 0, r = 7;
	if(ans[l]>x) return 0;
	if(ans[r]<x) return r;
	while(l<r){
		int mid = l+r+1>>1; 
		cout<<l<<" "<<r<<" "<<mid<<endl;
		if(ans[mid] < x) l = mid;
		else r = mid-1; 
	}
	return l+1; // ��ʵ��ֻҪ+1 
}
int higher(int x){
	int l = 0, r = 7;
		if(ans[l]>x) return 0;
		if(ans[r]<x) return r;
		while(l<r){
			int mid = l+r>>1; // ����ȡ�� 
			cout<<l<<" "<<r<<" "<<mid<<endl;
			if(ans[mid] <= x) l = mid+1;
			else r = mid; // ��ʹ���ҲӦ�þ��������ƶ���ʹĳһ��r<=l������ 
		}
		return l; 	
}
int main(){
//	for(int i = 0;i<50;i++){
//		ans[i] = i;
//	}
//	for(int i = 50;i<180;i++){
//		ans[i] = i+1;
//	}
	
	cout<<higher(2)<<endl;;
	cout<<lower_bound(ans,ans+8,2)-ans<<endl;
//	cout<<lower(55);
	return 0;
}
