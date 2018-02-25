#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[105];
int main()
{
    cin>>n>>k;
    int c1=n*2,c2=n,c3=0;
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
    for(int i=1;i<=k;i++)
    {
        int w=a[i]/4;
        if(c2>=w)
        {
            c2-=w;
            a[i]-=w*4;
        }
    }
    c1+=c2;
    c3+=c2;
    for(int i=1;i<=k;i++)
    {
        if(a[i])
        {
            if(a[i]&1)
            {
                if(c3) c3--;
                else c1--;
            }
            int w=a[i]/2;
            if(c1>=w) c1-=w;
            else c3-=2;
            if(c3<0)  //ÕâÀïGGÁË
            {
                puts("NO");
                return 0;
            }
        }
        //cout<<c1<<endl;
    }
    puts("YES");
    return 0;
}
