#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h> //POJ没有 
using namespace std;
#define REP(I,N) for(int I = 0;I<N;I++)
#define REP1(I,N) for(int I = 1;I<=N;I++)
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define MP(X,Y) make_pair(x,y)
#define CLR(A,X) memset(A,X,sizeof(A))
#define PB(X) push_back(X)
typedef long long LL;
#define maxn 520
//priority_queue 是 push 
sync_with_stdio(false); // 输入加速 
cin.tie(0); 
priority_queue<int,vector<int>,greater<int> > q; // 小在上 
if(typeid(a) == typeid(int)) // #include<typeinfo.h> 
freopen("C:/Users/HCY/Desktop/input.txt", "r", stdin);


//double 最多至小数后15位 printf("%.15lf",res); cout<<setprecision(15)<<res<<endl; 
