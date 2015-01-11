/* ***********************************************
Author        :kuangbin
Created Time  :2015/1/11 12:17:01
File Name     :ZOJ\E.cpp
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
int a[20];
int n;
bool same(){
	for(int i = 1;i < n;i++)
		if(a[i] != a[i-1])
			return false;
	return true;
}
void go(){
	int id1 = 0, id2 = 0;
	for(int i = 1;i < n;i++){
		if(a[i] < a[id1])
			id1 = i;
		if(a[i] > a[id2])
			id2 = i;
	}
	int tmp = a[id2] - a[id1];
	a[id1] = a[id2] = tmp;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 0;i < n;i++)scanf("%d",&a[i]);
		bool f = false;
		for(int i = 1;i <= 1000000;i++){
			if(same()){
				printf("%d\n",a[0]);
				f = true;
				break;
			}
			go();
		}
		if(!f)printf("Nooooooo!\n");
	}
    return 0;
}
