#include<iostream>
#include<string>
#include<utility>
#include<cstring>
using namespace std;
class Big_num_sum
{
	public:
		Big_num_sum(string _a,string _b)
		{
			a = _a;
			b = _b;
		}
		string bigsum()//simple v
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
			//memset(res,0,sizeof(res));
			//memset(rec,0,sizeof(rec));
			for(int i = 0;i<len;i++)
			{
				rec[len-1-i] = speadd(a[len-1-i],b[len-1-i]).first;
				res[len-i] = speadd(a[len-1-i],b[len-1-i]).second;
				if(i == 0)cout<<rec[len-i];
			}
			cout<<endl;
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
			
	private:
		int toInt(const char c) {return (int)(c-'0');}
		int toChar(int i){return (char(i+'0'));}
		pair<int,int> speadd(const char a,const char b) {return make_pair((toInt(a)+toInt(b))/10,(toInt(a)+toInt(b))%10);}
		int temp;	
		string a;
		string b;
};



int main()
{
	string a,b;
	cin>>a>>b;
	Big_num_sum c(a,b);
	cout<<c.bigsum();
	return 0;
 } 
