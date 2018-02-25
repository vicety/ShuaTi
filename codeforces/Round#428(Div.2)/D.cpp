#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e6+5;
const int mo=1e9+7;
typedef long long ll;
const double eps=1e-5;
int n,m,k;
ll a[N],mx,b[N],ans;
inline ll mul(ll a,int b)
{
    ll ret=1;
    while (b)
    {
        if (b&1)ret=1ll*ret*a%mo;
        a=1ll*a*a%mo;
        b>>=1;
    }
    return ret%mo;
}
inline void pre()
{
    scanf("%d",&n);
    fo(i,1,n)
    {
        scanf("%I64d",&a[i]);
        mx=max(mx,a[i]);
        for(ll j=1;j*j<=a[i];j++)
        {
            if (a[i]%j==0)
            {
                b[j]++;
                if (j!=a[i]/j)b[a[i]/j]++;
            }
        }
    }
}
inline void solve()
{
    fo(i,2,mx)if (b[i])b[i]=(1ll*mul(2,b[i]-1)*b[i])%mo;
    fd(i,mx,2)
    {
        int j=2*i;
        while (j<=mx)
        {
            b[i]=(b[i]-b[j]+mo)%mo; //完全不包括 2 的组合 如 (4,8) (4,6,8) 才想起来gcd是最大公约数。。。 
            j+=i;
        }
        ans=(ans+1ll*b[i]*i)%mo;
    }
    printf("%I64d\n",ans);
}
int main()
{
    ans=0;
    pre();
    solve();
    return 0;
}
