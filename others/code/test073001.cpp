#include<bits/stdc++.h>
using namespace std;
struct NODE{
	int a,b;
	NODE(){
		
	}
	NODE(int _a,int _b){
		a = _a;
		b = _b;
	}
};
struct CMP{
	bool operator ()(NODE a,NODE b){
		return a.b>b.b;
	}
};

priority_queue<NODE, vector<NODE>, CMP> q ;
int main(){
	q.push(NODE(1,2));
	q.push(NODE(2,3));
	q.push(NODE(4,1));
	cout<<q.top().b; 
}
