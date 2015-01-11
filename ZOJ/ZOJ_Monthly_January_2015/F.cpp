/* ***********************************************
Author        :kuangbin
Created Time  :2015/1/11 14:16:16
File Name     :ZOJ\F.cpp
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
unsigned int bit[32];
long long C[50][50];
unsigned int c;
int k;
long long calc1(unsigned int n){
	int c0,c1;
	c0 = c1 = 0;
	long long ans = 0;
	int i = 31;
	while(i >= 0){
		int end;
		if(n&bit[i])end = 1;
		else end = 0;
		if(end){
			int re = 0;
			int cc0 = c0, cc1 = c1;
			cc0++;
			for(int j = i-1;j >= 0;j--){
				if((c&bit[j]) == 0)
					cc0++;
				else re++;
			}
			for(int j = 0;j <= re;j++){
				if(abs( (j+cc0) - (cc1 + re-j) ) <= k)
					ans += C[re][j];
			}
		}
		if(end == 1 && (c&bit[i]) == 0)break;
		if(end)c1++;
		else c0++;
		i--;
	}
	if(i < 0){
		if(abs(c0-c1) <= k)ans++;
	}
	return ans;
}
long long calc2(unsigned int n){
	int c0,c1;
	c0 = c1 = 0;
	long long ans = 0;
	int i = 31;
	while(i >= 0){
		int end;
		if(n&bit[i])end = 1;
		else end = 0;
		if(end){
			int re = 0;
			int cc0 = c0, cc1 = c1;
			cc0++;
			re = i;
			for(int j = 0;j <= re;j++)
				if(abs((j+cc0)-(cc1+re-j)) <= k)
					ans += C[re][j];
		}
		if(end)c1++;
		else c0++;
		i--;
	}
	if(i < 0){
		if(abs(c0-c1) <= k)ans++;
	}
	return ans;
}
long long calc3(unsigned int n){
	int c0,c1;
	c0 = c1 = 0;
	long long ans = 0;
	int i = 31;
	while(i >= 0){
		int end;
		if(n&bit[i])end = 1;
		else end = 0;
		if(end && (c&bit[i]) == 0){
			int re = 0;
			int cc0 = c0, cc1 = c1;
			cc0++;
			for(int j = i-1;j >= 0;j--){
				if((c&bit[j]) == 0)
					re++;
				else cc1++;
			}
			for(int j = 0;j <= re;j++)
				if(abs((j+cc0) - (cc1+re-j)) <= k)
					ans += C[re][j];
		}
		if(end == 0 && (c&bit[i]) != 0)break;
		if(end)c1++;
		else c0++;
		i--;
	}
	if(i < 0){
		if(abs(c0-c1) <= k)ans++;
	}
	return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    bit[0] = 1;
	for(int i = 1;i < 32;i++)
		bit[i] = bit[i-1]<<1;
	C[0][0] = 1;
	for(int i = 1;i < 40;i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1;j < i;j++)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
	unsigned int L,R;
	int T;
	scanf("%d",&T);
	int iCase = 0;
	while(T--){
		iCase++;
		cin>>L>>R>>c;
		cin>>k;
		printf("Case %d:",iCase);
		long long ans1 = calc1(R);
		if(L > 0)ans1 -= calc1(L-1);
		cout<<" "<<ans1;
		if(c)printf(" 0");
		else{
			long long ans2 = calc2(R);
			if(L)ans2 -= calc2(L-1);
			cout<<" "<<ans2;
		}
		long long ans3 = calc3(R);
		if(L > 0)ans3 -= calc3(L-1);
		cout<<" "<<ans3<<endl;
	}
    return 0;
}
