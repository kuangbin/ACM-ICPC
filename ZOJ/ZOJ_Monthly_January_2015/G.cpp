/* ***********************************************
Author        :kuangbin
Created Time  :2015/1/11 12:25:13
File Name     :ZOJ\G.cpp
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
long long gcd(long long a,long long b){
	if(b == 0)return a;
	else return gcd(b,a%b);
}
int a[100010];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	int iCase = 0;
	while(scanf("%d",&n) == 1){
		iCase++;
		int tot = 0;
		for(int i = 0;i < n;i++){
			scanf("%d",&a[i]);
			tot = gcd(tot,a[i]);
		}
		if(tot != 1){
			printf("Case %d: -1\n\n",iCase);
			continue;
		}
		printf("Case %d: %d\n",iCase,2*(n-1));
		for(int i = 1;i < n;i++)
			printf("%d %d\n",1,i+1);
		for(int i = 1;i < n;i++)
			printf("%d %d\n",1,i+1);
		printf("\n");
	}
    return 0;
}
