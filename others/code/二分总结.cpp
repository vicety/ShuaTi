#include<bits/stdc++.h>
using namespace std;
//int ans[210];
int ans[8] = {1,2,2,4,5,5,5,6};
int find_exact(int x){ // 事实上不会出现 l = r-1 除非是初始情况 
	int l = 0, r = 7;
	if(ans[l]>x || ans[r]<x) return -1;
	while(l<r){
		int mid = l+r>>1;
		cout<<mid<<endl;
		if(ans[mid] < x) l = mid+1; // 因为要找确定值，mid都确定不是了，就没必要从mid开始 
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
		int mid = l+r+1>>1; // 向上取整 
		cout<<l<<" "<<r<<" "<<mid<<endl;
		if(ans[mid] < x) l = mid;
		else r = mid-1; // 即使相等也应该尽量向左移动，使某一次r<=l而跳出 
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
	return l+1; // 事实上只要+1 
}
int higher(int x){
	int l = 0, r = 7;
		if(ans[l]>x) return 0;
		if(ans[r]<x) return r;
		while(l<r){
			int mid = l+r>>1; // 向上取整 
			cout<<l<<" "<<r<<" "<<mid<<endl;
			if(ans[mid] <= x) l = mid+1;
			else r = mid; // 即使相等也应该尽量向左移动，使某一次r<=l而跳出 
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
