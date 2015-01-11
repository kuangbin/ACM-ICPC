/* ***********************************************
Author        :kuangbin
Created Time  :2015/1/10 20:20:47
File Name     :BC26\C.cpp
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
const int MOD = 1e9+7;
const int MAXN = 100010;
long long pow_m(long long a,long long n){
	long long ret = 1;
	long long tmp = a%MOD;
	while(n){
		if(n&1)ret = ret*tmp%MOD;
		tmp = tmp*tmp%MOD;
		n >>= 1;
	}
	return ret;
}
long long p[MAXN];
long long rp[MAXN];
long long C(int n,int m){
	long long ret = p[n]*rp[m]%MOD*rp[n-m]%MOD;
	return ret;
}
int a[MAXN];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    p[0] = 1;
	rp[0] = 1;
	for(int i = 1;i < MAXN;i++){
		p[i] = p[i-1]*i%MOD;
		rp[i] = pow_m(p[i],MOD-2);
	}
	int T;
	int n;
	scanf("%d",&T);
	int iCase = 0;
	while(T--){
		iCase++;
		scanf("%d",&n);
		map<int,int>mp;
		for(int i = 0;i < n;i++){
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		int c0 = 0 , c1 = 0;
		long long tmp1 = 1, tmp2 = 1;
		map<int,int>::iterator it;
		for(it = mp.begin();it != mp.end();it++){
			int val = it->first;
			int cc = it->second;
			c1 += cc;
			tmp2 = tmp2*rp[cc]%MOD;
		}
		long long ans = 0;
		for(it = mp.begin();it != mp.end();it++){
			int val = it->first;
			int cc = it->second;
			c1 -= cc;
			tmp2 = tmp2*p[cc]%MOD;
			for(int i = 0;i < cc;i++){
				long long tt = C(cc-i+c1-1,c1)*p[c1]%MOD*tmp2%MOD;
				tt = tt*C(n-c0+1+c0-1,c0)%MOD*p[c0]%MOD*tmp1%MOD;
				ans += tt*val%MOD;
				ans%=MOD;
			}
			c0 += cc;
			tmp1 = tmp1*rp[cc]%MOD;
		}
		printf("Case #%d: %d\n",iCase,(int)ans);
	}
    return 0;
}
