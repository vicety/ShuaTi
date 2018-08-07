/*
Every number can be represented as a1^b1*a2^b2*a3^b3...
使用素数的倍数来过滤数字 即prime * time
代码的逻辑是外层循环是time，内层循环是每个prime 
当time中的因数与prime不重合时，显然prime * time的结果不可能由其他prime乘以更大的time得到，因为这里的prime是唯一的 
当time中的因数与prime有一个重合时，把这次情况也用于过滤，但不再使用接下来的prime，
也就是说，对于x = a^n1*b^n2*c^n3...这样的数字，只会在[a^(n1-1)*b^n2*c^n3] * a的时候过滤一次，
而不会出现[a^n1*b^(n2-1)*c^n3] * b这样的情况（这里假设a < b < c）,因为 x的最小因子是a，
在 [a^n1*b^(n2-1)*c^n3]时是不会跳到更大的b去进行过滤的 
 
Note that 1 is not a prime number
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
int sz, q;

bool isPrime[N];  // true -> is Prime
int prime[N];

void init(){
	for(int i = 0; i < N; i++){
		isPrime[i] = true;
	}
	isPrime[1] = false;
}

void getPrime(int size){
	int pos = 0;
	for(int i = 2; i <= size; i++){
		if(isPrime[i]){
			prime[pos++] = i;
		}
		
		for(int j = 0; j < pos && i * prime[j] <= size; j++){
			isPrime[i * prime[j]] = false;
			if(i % prime[j] == 0) break; 
		}
	}
}

int main(){
	cin>>sz>>q;
	
	init();
	getPrime(sz);
	
	int query;
	while(q--){
		cin >> query;
		if(isPrime[query]) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
