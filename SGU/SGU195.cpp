/* ***********************************************
Author        :kuangbin
Created Time  :2014/11/28 18:42:49
File Name     :E:\2014ACM\SGU\SGU195.cpp
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
const int MAXN = 500010;
int fa[MAXN];
bool vis[MAXN];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	while(scanf("%d",&n) == 1){
		fa[1] = 1;
		for(int i = 2;i <= n;i++){
			scanf("%d",&fa[i]);
		}
		vector<int>ans;
		memset(vis,false,sizeof(vis));
		for(int i = n;i > 1;i--){
			int u = i;
			if(vis[u] || vis[fa[u]])continue;
			ans.push_back(u);
			vis[u] = true;
			vis[fa[u]] = true;
		}
		sort(ans.begin(),ans.end());
		int sz = ans.size();
		printf("%d\n",sz*1000);
		for(int i = 0;i < sz;i++){
			printf("%d",ans[i]);
			if(i < sz-1)printf(" ");
			else printf("\n");
		}
	}
    return 0;
}
