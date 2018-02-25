#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') f = -1;ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0';ch = getchar(); }
	return x*f;
}
struct E {
	int x, y, t;
	E() {}
	E(int a, int b, int c) {
		x = a, y = b, t = c;
	}
}e[250100];
int sz[505][505];
int n, m, k, q;
int mo[505][505];
bool check(int t) {
	memset(sz, 0, sizeof(sz));
	memset(mo, 0, sizeof(mo));
	for (int i = 0;i<q;i++) {
		if (e[i].t <= t)mo[e[i].x][e[i].y] = 1;
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			sz[i][j] = sz[i - 1][j] + sz[i][j - 1] - sz[i - 1][j - 1] + mo[i][j];
		}
	}
	for (int i = k;i <= n;i++) {
		for (int j = k;j <= m;j++) {
			if (sz[i][j] - sz[i - k][j] - sz[i][j - k] + sz[i - k][j - k] == k*k) return true;
		}
	}
	return false;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 0;i<q;i++) {
		int a = read(), b = read(), c = read();
		e[i] = E(a, b, c);
	}
	if (!check(1e9 + 10)) return 0 * printf("-1");
	int l = 0, r = 1e9 + 10;
	while (l<r) {
		int mid = l + r >> 1;
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if (check(mid)) r = mid;
		else l = mid+1;
	}
	cout << l << endl;
}
