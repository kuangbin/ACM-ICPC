/* ***********************************************
Author        :kuangbin
Created Time  :2014/11/8 20:19:07
File Name     :BC18\C.cpp
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
struct Edge{
	int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
void init(){
	tot = 0;
	memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
struct Node{
	int u,pre,dis;
	Node(int _u = 0,int _pre = 0,int _dis = 0){
		u = _u;
		pre = _pre;
		dis = _dis;
	}
};
queue<Node>q;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
	int n,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		k *= 2;
		init();
		int u,v;
		for(int i = 1;i < n;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		while(!q.empty())q.pop();
		for(int i = 1;i <= n;i++)
			q.push(Node(i,i,0));
		int cnt = 0;
		long long ans = 0;
		if(k == 0){
			printf("0\n");
			continue;
		}
		while(!q.empty()){
			Node tmp = q.front();
			q.pop();
			u = tmp.u;
			for(int i = head[u];i != -1;i = edge[i].next){
				v = edge[i].to;
				if(v == tmp.pre)continue;
				ans += tmp.dis+1;
				cnt++;
				if(cnt >= k)break;
				q.push(Node(v,u,tmp.dis+1));
			}
			if(cnt >= k)break;
		}
		printf("%I64d\n",ans/2);
	}
    return 0;
}
