
 #include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)

using namespace std;

typedef long long unsigned llu;
typedef pair<int, int> ii;
typedef vector<int> vi;

void clearBuffer() {
	char c;
	while((c = getchar()) != EOF && c != '\n');
}

main() {
	int n, k;
	bool cond = true;
	int s[60];
	fr(i, 0, 60) s[i] = 0;
	char b;
	cin >> n >> k;
	clearBuffer();
	fr(i, 0, n) {
		b = getchar();
		++s[b-'a'];
	}
	fr(i, 0, 60) {
		if(s[i] && (s[i] > k)) cond = false;
	}
	if(cond) puts("YES");
	else puts("NO");
}
