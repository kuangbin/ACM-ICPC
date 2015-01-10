/* ***********************************************
Author        :kuangbin
Created Time  :2014/12/28 17:20:14
File Name     :E:\2014ACM\SGU\SGU194.cpp
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

const int MAXN = 210;//点数的最大值
const int MAXM = 40010;//边数的最大值
const int INF = 0x3f3f3f3f;
struct Edge{
	int to,next,cap,flow;
}edge[MAXM];//注意是MAXM
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
void init(){
	tol = 0;
	memset(head,-1,sizeof(head));
}
int id[MAXM];
//加边，单向图三个参数，双向图四个参数
void addedge(int u,int v,int w,int rw=0){
	edge[tol].to = v;edge[tol].cap = w;edge[tol].next = head[u];
	edge[tol].flow = 0;head[u] = tol++;
	edge[tol].to = u;edge[tol].cap = rw;edge[tol].next = head[v];
	edge[tol].flow = 0;head[v]=tol++;
}
//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int start,int end,int N){
	memset(gap,0,sizeof(gap));
	memset(dep,0,sizeof(dep));
	memcpy(cur,head,sizeof(head));
	int u = start;
	pre[u] = -1;
	gap[0] = N;
	int ans = 0;
	while(dep[start] < N){
		if(u == end){
            int Min = INF;
            for(int i = pre[u];i != -1; i = pre[edge[i^1].to])
                if(Min > edge[i].cap - edge[i].flow)
                        Min = edge[i].cap - edge[i].flow;
            for(int i = pre[u];i != -1; i = pre[edge[i^1].to]){
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v;
        for(int i = cur[u]; i != -1;i = edge[i].next){
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u]){
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if(flag){
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u]; i != -1;i = edge[i].next)
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min){
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]])return ans;
        dep[u] = Min+1;
        gap[dep[u]]++;
        if(u != start) u = edge[pre[u]^1].to;
	}
	return ans;
}
int up[MAXM],down[MAXN];
int a[MAXN];


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
	while(scanf("%d%d",&n,&m) == 2){
		init();
		memset(a,0,sizeof(a));
		int u,v;
		for(int i = 0;i < m;i++){
			scanf("%d%d%d%d",&u,&v,&down[i],&up[i]);
			a[u] -= down[i];
			a[v] += down[i];
			id[i] = tol;
			addedge(u,v,up[i]-down[i]);
		}
		int sum = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] > 0){
				addedge(0,i,a[i]);
				sum += a[i];
			}
			else if(a[i] < 0){
				addedge(i,n+1,-a[i]);
			}
		}
		if(sap(0,n+1,n+2) < sum)printf("NO\n");
		else {
			printf("YES\n");
			for(int i = 0;i < m;i++){
				printf("%d\n",down[i]+edge[id[i]].flow);
			}
		}
	}
    return 0;
}
