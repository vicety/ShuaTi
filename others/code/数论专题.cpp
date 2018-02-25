LL gcd(LL a LL b){
	if(b == 0) return a;
	else return gcd(b,a%b);
}



//一般素数筛 nloglogn 
bool prime[maxn]; //默认true 大概还要再写一次 
for(int i = 3;i<=sqrt(n);i+=2){
	if(Prime[i]){
		for(int j = i+i;j<=n;j+=i){
			prime[j] = false; 
		}
	}
}

//线性筛
//http://www.cnblogs.com/zhuohan123/p/3233011.html 说得很好 
void getlist(int listsize)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i])
        {
             prime[++primesize]=i;
             phi[i]=i-1;
         }
         for(int j=1;j<=primesize&&i*prime[j]<=listsize;j++)
         {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)
             {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
}


//HDU 4143
//y^2-x^2 == n == (y-x)*(y+x) 枚举因子
//y-x = i;  x+y = n/i; 
//i越大  x越大  如果存在 更新覆盖即可 
for(int i = sqrt(n);i>0;i--)
if(n%i == 0){
	if((n/i-i)%2 == 0 && (n/i-i)/2>0) // 完全平方
		x = (n/i-i)/2;
		break;	
}
printf("%d\n",x);
return 0;

//HDU1568
//大数前4位 （当然通过通项公式得到） 还是非常实用的 
//log 10
