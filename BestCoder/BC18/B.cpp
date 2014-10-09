/* ***********************************************
Author        :kuangbin
Created Time  :2014/11/8 19:10:43
File Name     :BC18\B.cpp
 ************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAXN = 200100;
struct Node *null;
struct Node{
	Node *ch[2],*fa;
	int size,cnt;
	long long key;
	inline void setc(Node *p,int d){
		ch[d] = p;
		p->fa = this;
	}
	inline bool d(){
		return fa->ch[1] == this;
	}
	inline void push_up(){
		size = ch[0]->size + ch[1]->size + cnt;
	}
	void clear(long long _key){
		size = cnt = 1;
		key = _key;
		ch[0] = ch[1] = fa = null;
	}
	inline bool isroot(){
		return fa == null || this != fa->ch[0] && this != fa->ch[1];
	}
};
Node pool[MAXN],*tail;
Node *bc[MAXN];
Node *root;
int bc_top;//`内存回收`
void init(){
	tail = pool;
	bc_top = 0;
	null = tail++;
	null->size = null->cnt = 0;
	null->ch[0] = null->ch[1] = null->fa = null;
}
inline void rotate(Node *x){
	Node *f = x->fa, *ff = x->fa->fa;
	int c = x->d(), cc = f->d();
	f->setc(x->ch[!c],c);
	x->setc(f,!c);
	if(ff->ch[cc] == f)ff->setc(x,cc);
	else x->fa = ff;
	f->push_up();
}
inline void splay(Node* &root,Node* x,Node* goal){
	while(x->fa != goal){
		if(x->fa->fa == goal)rotate(x);
		else {
			bool f = x->fa->d();
			x->d() == f ? rotate(x->fa) : rotate(x);
			rotate(x);
		}
	}
	x->push_up();
	if(goal == null)root = x;
}
//`找到r子树里面的最左边那个`
Node* get_left(Node* r){
	Node* x = r;
	while(x->ch[0] != null)x = x->ch[0];
	return x;
}
//`在root的树中删掉x`
void erase(Node* &root,Node* x){
	splay(root,x,null);
	Node* t = root;
	if(t->ch[1] != null){
		root = t->ch[1];
		splay(root,get_left(t->ch[1]),null);
		root->setc(t->ch[0],0);
	}
	else root = root->ch[0];
	bc[bc_top++] = x;
	root->fa = null;
	if(root != null)root->push_up();
}
Node* newNode(long long key){
	Node* p;
	if(bc_top)p = bc[--bc_top];
	else p = tail++;
	p->clear(key);
	return p;
}
//`插入一个值key`
void insert(Node* &root,long long key){
	if(root == null){
		root = newNode(key);
		return;
	}
	Node* now = root;
	Node* pre = root->fa;
	while(now != null){
		if(now->key == key){
			now->cnt++;
			splay(root,now,null);
			return;
		}
		pre = now;
		now = now->ch[key >= now->key];
	}
	Node *x = newNode(key);
	pre->setc(x,key >= pre->key);
	splay(root,x,null);
}
//`删除一个值key`
void erase(Node* &root,long long key){
	Node* now = root;
	while(now->key != key){
		now = now->ch[key >= now->key];
	}
	now->cnt--;
	if(now->cnt == 0)erase(root,now);
	else splay(root,now,null);
}
void Travel(Node* r){
	if(r == null)return;
	Travel(r->ch[0]);
	bc[bc_top++] = r;
	Travel(r->ch[1]);
}
void CLEAR(Node* &root){
	Travel(root);
	root = null;
}
//`查询小于等于val的个数`
int query(Node *root,long long val){
	int ans = 0;
	Node *x = root;
	while(x != null){
		if(val < x->key)x = x->ch[0];
		else{
			ans += x->ch[0]->size + x->cnt;
			x = x->ch[1];
		}
	}
	return ans;
}

vector<long long>vec[1010];
int main()
{
	//freopen("out.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		root = null;
		int n;
		long long k;
		scanf("%d%I64d",&n,&k);
		long long ans = 0;
		for(int i = 0;i < n;i++){
			vec[i].clear();
			int sz ;
			scanf("%d",&sz);
			for(int j = 0;j < sz;j++){
				long long tmp;
				scanf("%I64d",&tmp);
				ans += root->size - query(root,(long long)k-tmp);
				vec[i].push_back(tmp);
			}
			for(int j = 0;j < sz;j++)
				insert(root,vec[i][j]);

		}
		printf("%I64d\n",ans);
	}
	return 0;
}
