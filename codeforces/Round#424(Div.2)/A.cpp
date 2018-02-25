#include<bits/stdc++.h>
using namespace std;
int arr[105],n;
int main(){
	cin>>n;
	for(int i = 0;i<n;i++) cin>>arr[i];
	//if(n<=2) return 0*printf("YES");
	int p = 0;
	while(arr[p] < arr[p+1] && p<n-1) p++;
	while(arr[p] == arr[p+1] && p<n-1) p++;
	while(arr[p] > arr[p+1] && p<n-1) p++;
	if(p == n-1) return 0*printf("YES");
	printf("NO");
	return 0;
} 