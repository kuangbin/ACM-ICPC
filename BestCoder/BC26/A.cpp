/* ***********************************************
Author        :kuangbin
Created Time  :2015/1/10 18:58:02
File Name     :BC26\A.cpp
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
	while(scanf("%d%d",&n,&m) == 2)
		printf("%d\n",(m-1)%n);
    return 0;
}
