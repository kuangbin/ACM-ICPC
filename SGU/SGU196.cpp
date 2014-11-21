/* ***********************************************
Author        :kuangbin
Created Time  :2014/11/21 22:57:16
File Name     :E:\2014ACM\SGU\SGU196.cpp
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
int du[10010];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
	while(scanf("%d%d",&n,&m) == 2){
		memset(du,0,sizeof(du));
		int u,v;
		while(m--){
			scanf("%d%d",&u,&v);
			du[u]++;
			du[v]++;
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
			ans += du[i]*du[i];
		printf("%d\n",ans);
	}
    return 0;
}
