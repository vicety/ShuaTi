/*
Every number can be represented as a1^b1*a2^b2*a3^b3...
ʹ�������ı������������� ��prime * time
������߼������ѭ����time���ڲ�ѭ����ÿ��prime 
��time�е�������prime���غ�ʱ����Ȼprime * time�Ľ��������������prime���Ը����time�õ�����Ϊ�����prime��Ψһ�� 
��time�е�������prime��һ���غ�ʱ����������Ҳ���ڹ��ˣ�������ʹ�ý�������prime��
Ҳ����˵������x = a^n1*b^n2*c^n3...���������֣�ֻ����[a^(n1-1)*b^n2*c^n3] * a��ʱ�����һ�Σ�
���������[a^n1*b^(n2-1)*c^n3] * b������������������a < b < c��,��Ϊ x����С������a��
�� [a^n1*b^(n2-1)*c^n3]ʱ�ǲ������������bȥ���й��˵� 
 
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
