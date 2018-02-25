#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; scanf("%d", &n);
    vector<int> a(n);
    for(int i=0; i<n; ++i) scanf("%d", &a[i]);
    
    int odd = count_if(a.begin(), a.end(), [](int i)->bool{return i%2==1;});
    int even = n-odd;
    
    string ans;
    if (odd%2==1) {
        ans = "First";
    } else if (odd==0) {
        ans = "Second";
    } else {
        ans = "First";
    }
    
    cout<<ans<<'\n';
    
    return 0;
}
