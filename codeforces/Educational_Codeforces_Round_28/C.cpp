#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map> 
#include<cstring>
#include<string>
#include<set>
using namespace std;
int ansl, ansm, ansr, n, tl, tm, tr;
long long arr[5010];
long long sum[5010];
long long s1, s2;
#define S(l,r) (sum[r]-sum[l])
int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> arr[i];
	for (int i = 1;i <= n;i++) sum[i] = sum[i - 1] + arr[i];
	long long ans = -1e17;

	for (int i = 0;i <= n;i++) {
		s1 = -1e17, s2 = -1e17;
		for (int j = 0;j <= i;j++) {
			if (S(0, j) - S(j, i) > s1) s1 = S(0, j) - S(j, i), tl = j;
		}
		for (int j = i;j <= n;j++) {
			if (S(i, j) - S(j, n) > s2) s2 = S(i, j) - S(j, n), tr = j;
		}
		if (s1 + s2>ans) ans = s1 + s2, ansl = tl, ansm = i, ansr = tr;
	}
	printf("%d %d %d", ansl, ansm, ansr);
	return 0;
}

