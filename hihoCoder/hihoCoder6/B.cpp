/* ***********************************************
Author        :kuangbin
Created Time  :2014/12/14 19:46:09
File Name     :hihoCoder6\B.cpp
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
const double eps = 1e-6;
int sgn(double x){
	if(fabs(x) < eps)return 0;
	else if(x < 0)return -1;
	else return 1;
}
double calc(double x1,double y1,double x2,double y2){
	if(sgn(x1-x2) == 0)return 0;
	double k = (y2-y1)/(x2-x1);
	double b = y1 - k*x1;
	return k*(x2*x2*x2-x1*x1*x1)/3 + b*(x2*x2-x1*x1)/2;
}
struct Point{
	double x,y;
	Point(double _x = 0,double _y = 0){
		x = _x;
		y = _y;
	}
	double operator ^(const Point &b)const{
		return x*b.y - y*b.x;
	}
	void input(){
		scanf("%lf%lf",&x,&y);
	}
};
Point p[10010];
double calc2(Point a,Point b){
	return calc(a.x,a.y,b.x,b.y);
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 0;i < n;i++){
			p[i].input();
		}
		double ret = 0;
		double tot = 0;
		double ans = 0;
		ret = 0;
		for(int i = 0;i < n;i++){
			ans += calc2(p[i],p[(i+1)%n]);
			ret += (p[i]^p[(i+1)%n]);
		}
		if(sgn(ret) < 0)tot -= ans;
		else tot += ans;
		ans = ret = 0;
		for(int i = 0;i < n;i++)swap(p[i].x,p[i].y);
		for(int i = 0;i < n;i++){
			ans += calc2(p[i],p[(i+1)%n]);
			ret += (p[i]^p[(i+1)%n]);
		}
		if(sgn(ret) < 0)tot -= ans;
		else tot += ans;
		ans = -tot;
		if(fabs(ans) < 0.000001)ans = 0.0;
		printf("%.2f\n",ans);
	}
    return 0;
}
