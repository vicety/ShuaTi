#include<iostream>
#include<string>
#include<utility>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
class Big_num_sum
{
	public:
		string bigsum(string a,string b)//simple v
		{
			if(a == "0")return b;
			if(b == "0")return a;
			int lena = a.length();
			int lenb = b.length();
			if(lena>=lenb)
			{
				string tempstr = "";
				int temparr[lena];
				for(int i = 0;i<lena-lenb;i++) temparr[i] = 0;
				for(int i = 0;i<lenb;i++) temparr[i+lena-lenb] = toInt(b[i]);
				for(int i = 0;i<lena;i++) tempstr+=toChar(temparr[i]);
				b = tempstr;
				//cout<<"b convert to "<<b<<endl;
			} 
			else
			{
				string tempstr = "";
				int temparr[lenb];
				for(int i = 0;i<lenb-lena;i++) temparr[i] = 0;
				for(int i = 0;i<lena;i++) temparr[i+lenb-lena] = toInt(a[i]);
				for(int i = 0;i<lenb;i++) tempstr+=toChar(temparr[i]);
				a = tempstr;
				//cout<<"a convert to "<<a<<endl;
			} 
			int len = b.length();
			//cout<<"a and b "<<a<<" "<<b<<endl;
			int* res = new int[len+1];
			int* rec = new int[len+1];
			int* rec2 = new int[len+1];
			for(int i = 0;i<=len;i++) res[i] = rec[i] = 0;
			for(int i = 0;i<len;i++)
			{
				rec[len-1-i] = speadd(a[len-1-i],b[len-1-i]).first;
				res[len-i] = speadd(a[len-1-i],b[len-1-i]).second;
			}
			for(int i = 0;i<=len;i++) res[i]+=rec[i];
			for(int i = len;i>=1;i--)
			{
				if(res[i] == 10)
				{
					res[i] = 0;
					res[i-1]++;
				}
			}
			string ans = "";
			for(int i = 0;i<=len;i++) ans+=toChar(res[i]);
			return !toInt(ans[0])?ans.substr(1):ans;
		}
	protected:
		int toInt(const char c) {return (int)(c-'0');}	
	private:
		int toChar(int i){return (char(i+'0'));}
		pair<int,int> speadd(const char a,const char b) {return make_pair((toInt(a)+toInt(b))/10,(toInt(a)+toInt(b))%10);}
};

class Big_num_mul:public Big_num_sum
{
	public:
		/*Big_num_mul(string _a,string _b)
		{
			a = _a;
			b = _b;
		}*/
		string bigmul(string a,string b)
		{
			if(a == "0"||b == "0") return "0";
			int lena = a.length();
			int lenb = b.length();
			string ans = "0";
			for(int i = 0;i<lenb;i++)
			{
				int placeb = lenb-1-i;
				string res = "0";
				for(int i = 0;i<toInt(b[placeb]);i++) res = bigsum(res,a);
				res = addzero(res,i);
				//cout<<"res "<<res<<endl; 
				ans = bigsum(ans,res);
			}
			return ans;
		}
		string quick_big_pow(int _a,int b)
		{
			char temp[60];
			string a,now,res = "1";
			sprintf(temp,"%d",_a);
			now = a = temp;
			while(b)
			{
				if(b%2) res = bigmul(res,now);
				now = bigmul(now,now);
				b>>=1;
			}
			return res;
		}	
	private:
		string addzero(string str,int n)
		{
			for(int i = 1;i<=n;i++) str+="0";
			return str;
		}
		/*string a;
		string b;*/
};
bool isPrime(int n)
{
	//1既不是质数也不是合数 
	if(n == 1||n == 2) return true;
	for(int i = 2;i<=sqrt(n);i++) if(n%i == 0) return false;
	return true;
}

int main()
{
	/*string a,b;
	cin>>a>>b;
	Big_num_mul c(a,b);
	//cout<<c.bigmul(a,b);
	cout<<c.quick_big_pow(47,47);*/
	vector<int> v;
	int n;
	cin>>n;
	for(int i = 1;i<=min(n,50);i++)
	{
		if(n%i == 0&&isPrime(i))v.push_back(i); 
	}
	Big_num_mul bsm;
	string ans = "0";
	for(int i = 0;i<v.size();i++) ans = bsm.bigsum(ans,bsm.quick_big_pow(v[i],v[i]));
	cout<<ans;
	return 0;
 } 
