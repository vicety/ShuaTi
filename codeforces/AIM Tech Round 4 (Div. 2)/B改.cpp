#include <bits/stdc++.h>
#define maxn 100010
#define inf 0x3f3f3f3f
#define REP(i,x,y) for(int i=x;i<(y);i++)
#define RREP(i,x,y) for(int i=x;i>(y);i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m,ma[55][55];
ll ans=0;
int main()
{
    scanf("%d %d",&n,&m);
    int cnt1=0,cnt2=0;
    REP(i,1,n+1) REP(j,1,m+1) scanf("%d",&ma[i][j]);
    REP(i,1,n+1) {
        cnt1=cnt2=0;
        REP(j,1,m+1) {
            if(ma[i][j]) cnt1++;
            else cnt2++;
        }
        ans+=(1LL<<cnt1)-1;
        ans+=(1LL<<cnt2)-1;
    }
    //cout<<ans<<endl;
    REP(i,1,m+1) {
        cnt1=cnt2=0;
        REP(j,1,n+1) {
            if(ma[j][i]) cnt1++;
            else cnt2++;
        }
        ans+=(1LL<<cnt1)-1-cnt1;
        ans+=(1LL<<cnt2)-1-cnt2;
    }
    cout<<ans<<endl;
}
