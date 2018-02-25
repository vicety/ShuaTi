#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int c[1<<21];
ll  s[1<<21];
ll x, y; int p;
bool isPrime(int n){
	int mmax = sqrt(n);
	for(int i = 2;i<=mmax;i++){
		if(n%i == 0) return false;
	}
	return true;
}
int main()
{

    scanf("%d%I64d%I64d",&n,&x,&y);
    p = (x + y - 1)/y;
    for(int i = 0; i <n ;++i){
        int w;
        scanf("%d",&w);
        c[w]++;
        s[w] += w;
    }

    for(int i = 1; i< (1<<21); ++i)
    {
        c[i] += c[i-1];
        s[i] += s[i-1];
    }

    ll ans = n * x;
    for(int i = 2; i <= 1000000; i++)
    {
        ll t = 0;
        for(int j = i; j <= 1000000 + i && t < ans; j += i)
        {
            int k = max( j - i, j - p);
            ll h = (c[j] - c[k])*(ll)j - (s[j] - s[k]);
            t += h * y;
            t += (c[k] - c[j-i])*x;
        }
        ans = min(ans, t);
    }
    printf("%I64d\n", ans);

    return 0;
}
