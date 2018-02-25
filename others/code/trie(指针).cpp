//HDU1251
#include<cstring>
#include<cstdio> 
#include<cstdlib>
#include<iostream>
using namespace std;
char tmp;
int toInt(char c){
	return (int)(c-'a');
}
struct NODE{
	int cnt;
	NODE* next[26];
	//bool exist;
	NODE(){
		for(int i = 0;i<26;i++) next[i] = NULL;
		cnt = 0;
	}
	~NODE(){
		for(int i = 0;i<26;i++){
			if(next[i]){
				delete next[i];
				next[i] = NULL;
			} 
		}
	}
};
NODE* root = new NODE;
NODE* cur;
void trie_insert(char* c){
	char* p = c;
	cur = root;
	while(*p){
		tmp = *p;
		if(cur->next[toInt(tmp)] == NULL){
			cur->next[toInt(tmp)] = new NODE;
		}
		p++;
		cur = cur->next[toInt(tmp)];
		(cur->cnt)++;
		//if(!(*p)) cur->exist = true; 
	}
}
int trie_search(char* c){
	char* p = c;
	cur = root;
	while(*p){
		if(cur->next[toInt(*p)] == NULL) return 0;
		cur = cur->next[toInt(*p)];
		p++;
	}
	return cur->cnt;
}
void trie_delete(char *c){
	char* p = c;
	cur = root;
	while(*p){
		tmp = *p;
		//if(cur->next[toInt(tmp) == NULL]) abort();
		p++;
		//cur = cur->next[toInt(tmp)];
		if(--(cur->next[toInt(tmp)]->cnt) == 0){
			cout<<"delete "<<tmp<<endl;
			delete cur->next[toInt(tmp)];
			cur->next[toInt(tmp)] = NULL;
			return;
		}
		cur = cur->next[toInt(tmp)];
	}
}
int main(){
	char str[20];
	while(gets(str),strcmp(str,"")){
		trie_insert(str);
	}
	while(gets(str),strcmp(str,"")) trie_delete(str);
	while(gets(str)!=NULL) printf("%d\n",trie_search(str)); 
	return 0;
} 
