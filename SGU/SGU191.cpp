/* ***********************************************
Author        :kuangbin
Created Time  :2015/1/25 12:58:24
File Name     :E:\2014ACM\SGU\SGU191.cpp
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
const int MAXN = 30010;
char str[MAXN];
int sta[MAXN];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%s",str) == 1){
		int cnt = 0;
		sta[0] = 1;
		sta[1] = 0;
		cnt = 1;
		sta[cnt++] = 1-sta[cnt-1];
		printf("%d\n",sta[1]);
		cnt = 0;
		sta[cnt++] = (str[0]=='B');
		scanf("%s",str);
		int len = strlen(str);
		int i = 0;
		while(i < len && cnt > 0){
			if(sta[cnt-1] == (str[i]=='A'))cnt--;
			else {
				sta[cnt++] = (str[i]=='A');
			}
			i++;
		}
		if(i == len && cnt == 0)printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}
