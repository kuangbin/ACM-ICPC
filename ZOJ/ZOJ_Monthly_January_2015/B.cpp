/* ***********************************************
Author        :kuangbin
Created Time  :2015/1/11 13:37:50
File Name     :ZOJ\B.cpp
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
char str[100];
int a[100];

int cnt[20];
const int MOD = 1e9+7;
long long p[100];
long long rp[100];
long long pow_m(long long a,long long n){
	long long ret = 1;
	long long tmp = a%MOD;
	while(n){
		if(n&1){
			ret = ret*tmp%MOD;
		}
		tmp = tmp*tmp%MOD;
		n >>= 1;
	}
	return ret;
}
long long calc(){
	int tot = 0;
	for(int i = 1;i <= 13;i++)
		tot += cnt[i];
	long long ret = p[tot];
	for(int i = 1;i <= 13;i++)
		ret = ret*rp[cnt[i]]%MOD;
	return ret;
}

int main()
{
	p[0] = 1;
	rp[0] = 1;
	for(int i = 1;i < 100;i++){
		p[i] = p[i-1]*i%MOD;
		rp[i] = pow_m(p[i],MOD-2);
	}
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%s",str) == 1){
		int len = strlen(str);
		for(int i = 1;i <= 13;i++)
			cnt[i] = 4;
		int n = 0;
		for(int i = 0;i < len;i++){
			if(str[i] == 'A'){
				cnt[1]--;
				a[n++] = 1;
			}
			else if(str[i] == '1'){
				cnt[10]--;
				a[n++] = 10;
				i++;
			}
			else if(str[i] == 'J'){
				cnt[11]--;
				a[n++] = 11;
			}
			else if(str[i] == 'Q'){
				cnt[12]--;
				a[n++] = 12;
			}
			else if(str[i] == 'K'){
				cnt[13]--;
				a[n++] = 13;
			}
			else {
				cnt[str[i]-'0']--;
				a[n++] =str[i]-'0';
			}
		}
		long long ans = 0;
		int n2 = 52-n;
		if(n2 == 0){
			printf("1\n");
			continue;
		}
		for(int i = 0;i < n;i++){
			if(n2 == 0){
				ans = (ans+1)%MOD;
				break;
			}
			for(int j = 1;j < a[i];j++){
				if(cnt[j]){
					cnt[j]--;
					ans = (ans+calc())%MOD;
					cnt[j]++;
				}
			}
			if(cnt[a[i]] == 0)break;
			cnt[a[i]]--;
			n2--;
		}
		printf("%d\n",(int)ans);
	}
    return 0;
}
