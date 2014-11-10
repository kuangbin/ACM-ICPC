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
	void input(){
		scanf("%lf%lf%lf",&x,&y,&r);
	}
	bool check(Circle b){
		double d = hypot(x-b.x,y-b.y);
		return d < r + b.r - eps;
	}
}circle[MAXN];
circle p0;
double rad(Circle a,Circle b){
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
	}
    return 0;
}
