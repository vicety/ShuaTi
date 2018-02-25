#include<bits/stdc++.h>
using namespace std;
int arr[1000100],n,sum,even,odd;
int main(){
	cin>>n;
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
		if(arr[i]%2) odd++;
		else even++;
		sum+=arr[i];
	} 
	if(sum%2 || odd) return 0*printf("First");
	else return 0*printf("Second");
	return 0;
}
