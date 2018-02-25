#include<bits/stdc++.h>
using namespace std;
int n;
double ans;
struct S{
	int len;
	double p;
}s[50100];
double exlen[50100];
bool cmp(S a,S b){
	return a.len*a.p-a.len*a.p*b.p>b.len*b.p-b.len*b.p*a.p;
}
int len[5010],p[5010];
int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d%lf",&s[i].len,&s[i].p);
		s[i].p*=0.01;
	}
	sort(s,s+n,cmp);
	/*for(int i = 0;i<3;i++){
		cout<<s[i].len<<" "<<s[i].p<<endl;
	}*/
	exlen[0] = s[0].len*s[0].p;
	for(int i = 1;i<n;i++){
		exlen[i] = exlen[i-1]+s[i].len*s[i].p;
	}
	//for(int i = 0;i<n;i++) cout<<exlen[i]<<endl;
	for(int i = n-1;i>=1;i--){
		ans+=s[i].len+(1.0-s[i].p)*exlen[i-1];
	}
	ans+=s[0].len;
	printf("%.15lf\n",ans);
	return 0;
}
