/* ***********************************************
Author        :kuangbin
Created Time  :2014/11/4 11:37:23
File Name     :E:\2014ACM\SGU\SGU199.cpp
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
const int MAXN = 100010;
int dp[MAXN];
int c[MAXN];
int cnt;
int lowbit(int x){
	return x&(-x);
}
void add(int x,int id){
	int i = x;
	while(i <= cnt){
		if(dp[id] > dp[c[i]])
			c[i] = id;
		i += lowbit(i);
	}
}
int query(int i){
	int ret = 0;
	while(i > 0){
		if(dp[c[i]] > dp[ret])ret = i;
		i -=lowbit(i);
	}
	return ret;
}
struct Node{
	int x,y;
	int index;
	bool operator <(const Node &b)const{
		return x < b.x || (x == b.x && y < b.y);
	}
}node[MAXN];
int yy[MAXN];
int pre[MAXN];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d",&n) == 1){
		cnt = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d%d",&node[i].x,&node[i].y);
			node[i].index = i;
			yy[++cnt] = node[i].y;
		}
		sort(node+1,node+n+1);
		sort(yy+1,yy+cnt+1);
		cnt = unique(yy+1,yy+cnt+1) - yy - 1;
		map<int,int>mp;
		for(int i = 1;i <= cnt;i++)mp[yy[i]] = i;
		for(int i = 1;i <= n;i++)
			node[i].y = mp[node[i].y];
		memset(c,0,sizeof(c));
		memset(dp,0,sizeof(dp));
		int id = 1;
		for(int i = 1;i <= n;i++){
			while(node[id].x != node[i].x){
				add(node[id].y,id);
				id++;
			}
			int tmp = query(node[i].y-1);
			dp[i] = dp[tmp] + 1;
			pre[i] = tmp;
		}
		int now = 0;
		for(int i = 1;i <= n;i++)
			if(dp[i] > dp[now])
				now = i;
		vector<int>ans;
		while(now){
			ans.push_back(node[now].index);
			now = pre[now];
		}
		reverse(ans.begin(),ans.end());
		int sz = ans.size();
		printf("%d\n",sz);
		for(int i = 0;i < sz;i++){
			printf("%d",ans[i]);
			if(i < sz-1)printf(" ");
			else printf("\n");
		}
	}
    return 0;
}
