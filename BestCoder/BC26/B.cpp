/* ***********************************************
Author        :kuangbin
Created Time  :2015/1/10 19:05:55
File Name     :BC26\B.cpp
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
int C[10][10];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	C[0][0] = 1;
	for(int i = 1;i < 10;i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1;j < i;j++)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
	int T;
   int a,b;
	scanf("%d",&T);   
	int iCase = 0;
	while(T--){
		iCase++;
		scanf("%d%d",&a,&b);
		double tmp = 0.0;
		for(int i = 1;i <= b;i++){
			tmp += (double)C[b][i]*pow((double)(a-1),(double)(b-i));
		}
		tmp /= 2;
		for(int i = 1;i < b;i++)tmp /= a;
		tmp *= (a+1);
		//printf("%.3lf\n",tmp);
		double ans = (1-pow((double)(a-1)/a,(double)b))*a*(a+1)/2;
		printf("Case #%d: %.3lf\n",iCase,ans);
	}
    return 0;
}
