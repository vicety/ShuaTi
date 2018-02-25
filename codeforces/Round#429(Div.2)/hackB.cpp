#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int n, a;
bool win;

int main()
{
    scanf("%d", &n);
    REP(i,1,n) {
        scanf("%d", &a);
        if (a % 2) {
            printf("First");
            return 0;
        }
    }
    printf("Second");
    return 0;
}
