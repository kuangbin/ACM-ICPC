/* ***********************************************
Author        :kuangbin
Created Time  :2015/1/21 18:18:18
File Name     :E:\2014ACM\SGU\SGU192.cpp
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
int sgn(double x){
	if(fabs(x) < eps)return 0;
	if(x < 0)return -1;
	else return 1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y){
		x = _x;
		y = _y;
	}
	void input(){
		scanf("%lf%lf",&x,&y);
	}
	Point operator -(const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	double operator ^(const Point &b)const{
		return x*b.y - y*b.x;
	}
	double operator *(const Point &b)const{
		return x*b.x + y*b.y;
	}
};
struct Line{
	Point s,e;
	int type;
	int get_type(char ch){
		if(ch == 'R')return 0;
		else if(ch == 'G')return 1;
		else return 2;
	}
	void input(){
		s.input();
		e.input();
		if(s.x > e.x)swap(s,e);
		char ss[3];
		scanf("%s",ss);
		type = get_type(ss[0]);
	}
	int segcrossseg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		int d3 = sgn((v.e-v.s)^(s-v.s));
		int d4 = sgn((v.e-v.s)^(e-v.s));
		if( (d1^d2) == -2 && (d3^d4) == -2 )return 2;
		return (d1 == 0 && sgn((v.s-s)*(v.s-e)) <=0) ||
			(d2 == 0 && sgn((v.e-s)*(v.e-e)) <= 0) ||
			(d3 == 0 && sgn((s-v.s)*(s-v.e)) <= 0) ||
			(d4 == 0 && sgn((e-v.s)*(e-v.e)) <= 0);
	}
	Point crosspoint(Line v){
		double a1 = (v.e-v.s)^(s-v.s);
		double a2 = (v.e-v.s)^(e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
	}
};
Line line[330];
double x[160000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	while(scanf("%d",&n) == 1){
		int cnt = 0;
		for(int i = 0;i < n;i++){
			line[i].input();
			x[cnt++] = line[i].s.x;
			x[cnt++] = line[i].e.x;
		}
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j++)
				if(line[i].segcrossseg(line[j]) == 2){
					Point tmp = line[i].crosspoint(line[j]);
					x[cnt++] = tmp.x;
				}
		sort(x,x+cnt);
		cnt = unique(x,x+cnt)-x;
		double ans[3];
		ans[0] = ans[1] = ans[2] = 0;
		for(int i = 0;i < cnt-1;i++){
			if(fabs(x[i+1]-x[i]) < eps)continue;
			double xx = (x[i]+x[i+1])/2;
			double now;
			int tt = -1;
			for(int j = 0;j < n;j++){
				if(line[j].s.x < xx && xx < line[j].e.x){
					double yy = line[j].s.y + (xx-line[j].s.x)*(line[j].e.y-line[j].s.y)/(line[j].e.x-line[j].s.x);
					if(tt == -1){
						tt = line[j].type;
						now = yy;
					}
					else if(now > yy){
						tt = line[j].type;
						now = yy;
					}
				}
			}
			if(tt != -1){
				ans[tt] += x[i+1]-x[i];
			}
		}
		printf("R %.2lf\n",ans[0]);
		printf("G %.2lf\n",ans[1]);
		printf("B %.2lf\n",ans[2]);
	}
    return 0;
}
