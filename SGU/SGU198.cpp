/* ***********************************************
Author        :kuangbin
Created Time  :2014/11/10 20:16:21
File Name     :D:\github\ACM-ICPC\SGU\SGU198.cpp
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
const double eps = 1e-8;
const int MAXN = 310;
struct Circle{
	double x,y,r;
	Circle(double _x = 0,double _y = 0,double _r = 0){
		x = _x; y = _y; r = _r;
	}
	void input(){
		scanf("%lf%lf%lf",&x,&y,&r);
	}
	bool check(Circle b){
		double d = hypot(x-b.x,y-b.y);
		return d < r + b.r - eps;
	}
	Circle operator -(const Circle &b)const{
		return Circle(x-b.x,y-b.y,0);
	}
	double operator *(const Circle &b)const{
		return x*b.x + y*b.y;
	}
	double operator ^(const Circle &b)const{
		return x*b.y - y*b.x;
	}
}circle[MAXN];
Circle p0;
double rad(Circle a,Circle b){
	return atan2((a-p0)^(b-p0),(a-p0)*(b-p0));
}

struct Edge{
	int to,next;
	double w;
}edge[MAXN*MAXN];
int head[MAXN],tot;
void init(){
	tot = 0;
	memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v,double w){
	edge[tot].to = v;
	edge[tot].w = w;
	edge[tot].next = head[u];
	head[u] = tot++;
}
double dist[MAXN];
bool vis[MAXN];
int cnt[MAXN];
bool SPFA(int n){
	for(int i = 0;i < n;i++){
		dist[i] = 0.0;
		vis[i] = false;
		cnt[i] = 0;
	}
	queue<int>q;
	for(int i = 0;i < n;i++){
		vis[i] = true;
		q.push(i);
		cnt[i]++;
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u];i != -1;i = edge[i].next){
			int v = edge[i].to;
			double w = edge[i].w;
			if(dist[u] + w < dist[v] - eps){
				dist[v] = dist[u] + w;
				if(!vis[v]){
					vis[v] = true;
					cnt[v]++;
					q.push(v);
					if(cnt[v] > n)return false;
				}
			}
		}
	}
	return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	while(scanf("%d",&n) == 1){
		for(int i = 0;i < n;i++)
			circle[i].input();
		p0.input();
		for(int i = 0;i < n;i++)
			circle[i].r += p0.r;
		init();
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				if(i != j){
					if(circle[i].check(circle[j]))
						addedge(i,j,rad(circle[i],circle[j]));
				}
		if(SPFA(n))printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}
