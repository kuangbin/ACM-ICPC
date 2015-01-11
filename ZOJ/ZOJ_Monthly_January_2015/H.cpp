/* ***********************************************
Author        :kuangbin
Created Time  :2015/1/11 12:51:27
File Name     :ZOJ\H.cpp
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
char str[25][25];

int n,m;
int dp[25][25][21110];

struct Node{
	int x,y,s;
	Node(){}
	Node(int _x,int _y,int _s){
		x = _x;
		y = _y;
		s = _s;
	}
};
int Move[][2]={
	{0,1},{1,0},{0,-1},{-1,0}
};
struct Trie{
	int next[21110][26];
	bool end[21110];
	int fail[20010];
	int root,L;
	int newnode(){
		for(int i = 0;i < 26;i++)
			next[L][i] = -1;
		end[L] = false;
		return L++;
	}
	void init(){
		L = 0;
		root = newnode();
	}
	void insert(char s[]){
		int len = strlen(s);
		int now = root;
		for(int i = 0;i < len;i++){
			int id = s[i] - 'A';
			if(next[now][id] == -1)
				next[now][id] = newnode();
			now = next[now][id];
		}
		end[now] = true;
	}
	void build(){
		queue<int>Q;
		fail[root] = root;
		for(int i = 0;i < 26;i++)
			if(next[root][i] == -1)
				next[root][i] = root;
			else {
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		while(!Q.empty()){
			int now = Q.front();
			Q.pop();
			end[now] |= end[fail[now]];
			for(int i = 0;i < 26;i++)
				if(next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else {
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
		}
	}
	int solve(){
		queue<Node>q;
		memset(dp,-1,sizeof(dp));
		int sx,sy;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++){
				if(str[i][j] == '@'){
					sx = i;
					sy = j;
					str[i][j] = '.';
					dp[sx][sy][0] = 0;
					q.push(Node(sx,sy,0));
				}
			}
		while(!q.empty()){
			Node tmp = q.front();
			q.pop();
			int x = tmp.x;
			int y = tmp.y;
			int s = tmp.s;
			if(end[s])return dp[x][y][s];
			for(int i = 0;i < 4;i++){
				int nx = x+Move[i][0];
				int ny = y+Move[i][1];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
				if(str[nx][ny] == '#')continue;
				if(str[nx][ny] == '.'){
					if(dp[nx][ny][s] == -1){
						dp[nx][ny][s] = dp[x][y][s]+1;
						q.push(Node(nx,ny,s));
					}
				}
				else {
					int id = str[nx][ny]-'A';
					int now = s;
					while(dp[nx][ny][next[now][id]] == -1){
						now = next[now][id];
						if(dp[nx][ny][now] == -1){
							dp[nx][ny][now] = dp[x][y][s]+1;
							q.push(Node(nx,ny,now));
						}
					}
				}
			}
		}
		return -1;
	}
}tree;
char ss[11000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n <= 0 || n > 20)while(1);
		while(m <= 0 || m > 20)while(1);
		for(int i = 0;i < n;i++)
			scanf("%s",str[i]);
		tree.init();
		int k;
		scanf("%d",&k);
		//gets(ss);
		while(k--){
			scanf("%s",ss);
			//gets(ss);
			tree.insert(ss);
		}
		tree.build();
		printf("%d\n",tree.solve());
	}
    return 0;
}
